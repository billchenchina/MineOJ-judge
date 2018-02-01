//Before the project complete,main.cpp will be exclude from all the build.
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>
#include <thread>
#include <functional>

#include <experimental/filesystem>
#include <json/json.h>

#include "JudgeSideConfig.h"
#include "LibEvHandler.h"
#include "bean/JudgeData.h"

namespace fs = std::experimental::filesystem;

void judge(const MineOJ::JudgeSideConfig &,const bool &);

int main(int argc, char **argv) {

    // Json Read and Write
    std::string json_parse_errs;
    Json::StreamWriterBuilder write_builder;
    Json::CharReaderBuilder read_builder;
    std::stringstream json_parse_ss;

    // Read Judge Config
    // @TODO Replace the default-config.json to config.json after the project done
    std::ifstream config("default-config.json");
    Json::Value config_value;
    json_parse_ss << config.rdbuf();
    Json::parseFromStream(read_builder,
                          json_parse_ss,
                          &config_value,
                          &json_parse_errs);
    json_parse_ss.clear();
    MineOJ::JudgeSideConfig server_config(config_value);

    // Validate data_dir and work_dir
    fs::path data_path(server_config.judge_config.data_path);
    if (!fs::exists(data_path)) {
        std::cerr << "Data path does not exist!" << std::endl;
        std::cerr << "Please check!" << std::endl;
        return 1;
    }

    fs::path work_path(server_config.judge_config.work_path);
    if (!fs::exists(work_path)) {
        std::cerr << "Work path does not exist!" << std::endl;
        std::cerr << "Please check!" << std::endl;
        return 1;
    }
    bool judge_status = 1;
    std::function<void()>bound_judge = std::bind(judge,std::cref(server_config),std::cref(judge_status));
    std::shared_ptr<std::thread> judge_thread(new std::thread(bound_judge));
    AMQP::Address address = AMQP::Address(server_config.rabbitmq_config.ip,
                                          server_config.rabbitmq_config.port,
                                          AMQP::Login(server_config.rabbitmq_config.username,
                                                      server_config.rabbitmq_config.password),
                                          server_config.rabbitmq_config.vhost);

    auto *loop = ev_default_loop(0);
    auto handler = new AMQP::LibEvHandler(loop);
    AMQP::TcpConnection connection(handler, address);
    AMQP::TcpChannel channel(&connection);
    std::string s;
    channel.consume(server_config.rabbitmq_config.signal_queue_name, AMQP::noack)
            .onMessage([&bound_judge,&judge_status,&judge_thread,&channel,&connection,&s,&server_config]
                       (const AMQP::Message &message, uint64_t deliveryTag, bool redelivered) {
        s=std::string(message.body(),message.bodySize());
        if(s=="start")
        {
            if(!judge_status)
            {
                judge_status = 1;
                judge_thread.reset(new std::thread(bound_judge));
            }

        }
        else if(s=="stop")
        {
            judge_status = 0;
            if(judge_thread->joinable())
            {
                judge_thread->join();
            }
        }
    });
    ev_run(loop);

    return 0;
}

// @TODO
void judge(const MineOJ::JudgeSideConfig &server_config,const bool&judge_status)
{
    while(1){
        if(judge_status == 0)
        {
            std::cout <<"stopped"<<std::endl;
            return;
        }
        std::cout<<"In judge thread "<<std::this_thread::get_id()<<std::endl;
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(3s);
    }
}

//Before the project complete,main.cpp will be exclude from all the build.
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>
#include <experimental/filesystem>
#include <json/json.h>

#include "JudgeSideConfig.h"
#include "MQTestDataConsumer.h"
#include "bean/JudgeData.h"
namespace fs = std::experimental::filesystem;


int main(int argc,char **argv){

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
    Json::parseFromStream(read_builder, json_parse_ss, &config_value, &json_parse_errs);
    json_parse_ss.clear();
    MineOJ::JudgeSideConfig server_config(config_value);

    // Validate data_dir and work_dir
    fs::path data_path(server_config.judge_config.data_path);
    if(!fs::exists(data_path))
    {
        std::cerr << "Data path does not exist!" << std::endl
                  << "Please check!" << std::endl;
        return 1;
    }
    fs::path work_path(server_config.judge_config.work_path);
    if(!fs::exists(work_path))
    {
        std::cerr << "Work path does not exist!" << std::endl
                  << "Please check!" << std::endl;
        return 1;
    }

    for(;;)
    {
        // Run a MQTestDataConsumer
        MineOJ::MQTestDataConsumer consumer(server_config.rabbitmq_config);
        auto judge_data_str = consumer.exec(server_config.rabbitmq_config);

        // Parse Json::Value
        MineOJ::JudgeData judge_data;
        Json::Value judge_json_value;
        try
        {
            json_parse_ss << judge_data_str;
            parseFromStream(read_builder, json_parse_ss, &judge_json_value, &json_parse_errs);
            judge_data.parse_from_json(judge_json_value);
            json_parse_ss.clear();
        }
        catch(const Json::LogicError &e)
        {
            std::cerr << "judge_data unvaliable!" << std::endl;
            std::cerr << "Please check!" << std::endl;
            std::cerr << judge_data_str << std::endl;
            continue;
        }
        fs::path problem_path = data_path / std::to_string(judge_data.problem_id);
        if(!fs::exists(problem_path))
        {
            try
            {
                fs::create_directory(problem_path);
            }
            catch(const fs::filesystem_error &e)
            {
                std::cerr << "Failed to create path in " << problem_path.c_str() << std::endl;
                return 1;
            }

        }
        bool data_out_of_date = false;
        if(!fs::exists(problem_path/"problem.json"))
        {
            data_out_of_date = true;
        }
        else
        {
            std::ifstream existed_problem_json((problem_path/"problem.json").c_str());
            Json::Value existed_problem_value;
            json_parse_ss << existed_problem_json.rdbuf();
            Json::parseFromStream(read_builder, json_parse_ss, &existed_problem_value, &json_parse_errs);
            json_parse_ss.clear();
            if((!existed_problem_value.isMember("data_version")) || existed_problem_value["data_version"] != judge_data.data_version)
            {
                data_out_of_date = true;
            }
        }
        if(data_out_of_date)
        {

        }

        // @TODO Judge


    }

    return 0;
}

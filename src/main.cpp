//Before the project complete,main.cpp will be exclude from all the build.
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>
#include <json/json.h>

#include "JudgeSideConfig.h"
#include "MQConsumer.h"
#include "bean/JudgeData.h"

int main(int argc,char **argv){
    MineOJ::JudgeSideConfig server_config;
    Json::StreamWriterBuilder write_builder;
    Json::CharReaderBuilder read_builder;
    for(;;)
    {
        MineOJ::MQConsumer consumer(server_config.rabbitmq_config);
        auto judge_data_str = consumer.exec();
        std::cout << "Recevied" <<std::endl;
        MineOJ::JudgeData judge_data;
        try
        {
            judge_data.parse_from_json(Json::Value(judge_data_str));
        }
        catch(const Json::LogicError &e)
        {
            std::cerr << "judge_data unvaliable!" << std::endl;
            std::cerr << "Please check!" << std::endl;
            continue;
        }
        if(judge_data.data_version)
        {

        }

    }

    return 0;
}

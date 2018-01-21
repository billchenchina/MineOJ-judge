/*
 * RabbitmqConfig.h
 *
 *  Created on: 2018年1月20日
 *      Author: billchenchina
 */

#ifndef INCLUDE_RABBITMQCONFIG_H_
#define INCLUDE_RABBITMQCONFIG_H_

#include <string>

#include <Config.h>

class RabbitmqConfig: public MineOJ::Config {
public:
    RabbitmqConfig(const Json::Value &value);
    virtual ~RabbitmqConfig();
    std::string ip;
    uint16_t port;
    std::string username;
    std::string password;
    std::string vhost;
    std::string exchange_name;
    std::string queue_name;
    std::string signal_queue_name;
};

#endif /* INCLUDE_RABBITMQCONFIG_H_ */

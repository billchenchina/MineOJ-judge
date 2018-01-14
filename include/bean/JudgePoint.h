/*
 * JudgePoint.h
 *
 *  Created on: 2017年7月15日
 *      Author: billchenchina
 */

#ifndef BEAN_JUDGEPOINT_H_
#define BEAN_JUDGEPOINT_H_

#include <cstdint>

#include <string>

#include <json/json.h>

#include <bean/JudgeStatus.h>

namespace MineOJ
{
	class JudgePoint
	{
	public:
		std::uint64_t time;
		std::uint64_t memory;
		std::uint32_t score;
		JudgeStatus judge_status;
		std::string info;
		std::string in_data;
		std::string ans_data;
		JudgePoint() = default;
		JudgePoint(std::uint64_t time, std::uint64_t memory, std::uint32_t score, JudgeStatus judge_status, const std::string &info);
		JudgePoint(const Json::Value &json);

		Json::Value to_json() const;
	};

/*
	class JudgePoint{
	public:
		unsigned long long use_time;
		unsigned long long use_memory;
		int score;
		JudgeStatus judge_status;
		std::string info;
		void parseJson(Json::Value data_json){
			use_time=static_cast<long long>(data_json["useTime"].asDouble());
			use_memory=static_cast<long long>(data_json["useMemory"].asDouble());
			score=data_json["score"].asInt();
			judge_status=static_cast<JudgeStatus>(data_json["judgeStatus"].asInt());
			info=data_json["info"].asString();
		}
		Json::Value toJson(){
			Json::Value data_json;
			insertJson(data_json);
			return data_json;
		}
	private:
		void insertJson(Json::Value &data_json){
			data_json["useTime"]        = static_cast<double>(use_time);
			data_json["useMemory"]      = static_cast<double>(use_memory);
			data_json["score"]          = score;
			data_json["judgeStatus"]    = judge_status;
			data_json["info"]           = info;
		}

	};

*/
}



#endif /* BEAN_JUDGEPOINT_H_ */

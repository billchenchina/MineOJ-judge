#include "JudgePoint.h"

#include <cstdint>

#include <string>

#include <json/json.h>

MineOJ::JudgePoint::JudgePoint(std::uint64_t time, std::uint64_t memory, std::uint32_t score, JudgeStatus judge_status, const std::string &info)
    : time(time),
	memory(memory),
	score(score),
	judge_status(judge_status),
	info(info)
{}

MineOJ::JudgePoint::JudgePoint(const Json::Value &json)
    : time(json["time"].asUInt64()),
	memory(json["memory"].asUInt64()),
	score(json["score"].asUInt()),
	judge_status(static_cast<JudgeStatus>(json["judgeStatus"].asUInt())),
	info(json["info"].asString())
{}

Json::Value MineOJ::JudgePoint::to_json() const
{
	Json::Value json;
	json["time"] = time;
	json["memory"] = memory;
	json["score"] = score;
	json["judgeStatus"] = static_cast<std::uint8_t>(judge_status);
	json["info"] = info;
	return json;
}

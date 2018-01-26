#ifndef INCLUDE_BEAN_JUDGETYPE_H_
#define INCLUDE_BEAN_JUDGETYPE_H_

#include <cstdint>

namespace MineOJ {
enum class JudgeType
    : std::uint8_t
    {
        NormalJudge, SpecialJudge,
};
}

#endif // INCLUDE_BEAN_JUDGETYPE_H_

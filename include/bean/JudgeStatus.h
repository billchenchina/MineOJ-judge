#ifndef INCLUDE_BEAN_JUDGESTATUS_H_
#define INCLUDE_BEAN_JUDGESTATUS_H_

#include <cstdint>

namespace MineOJ {
enum class JudgeStatus
    : std::uint8_t
    {
        Accept,
    CompileError,
    WrongAnswer,
    RuntimeError,
    MemoryLimitExceeded,
    TimeLimitExceeded,
    OutputLimitExceeded,
    DangerousSystemCall,
    JudgementFailed,
};
}

#endif /* INCLUDE_BEAN_JUDGESTATUS_H_ */

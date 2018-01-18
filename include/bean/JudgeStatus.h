#ifndef BEAN_JUDGESTATUS_H_
#define BEAN_JUDGESTATUS_H_

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

#endif /* BEAN_JUDGESTATUS_H_ */

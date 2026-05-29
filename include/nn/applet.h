#pragma once

#include <nn/types.h>

namespace nn::applet {
enum class ExitReason { Normal = 0, Canceled = 1, Abnormal = 2, Unexpected = 10 };

namespace CTR {
enum class WakeupState : s8 {
    WAKEUP_BY_TIMEOUT = -1,
    WAKEUP_SKIP,
    WAKEUP_TO_START,
    WAKEUP_BY_EXIT,
    WAKEUP_BY_PAUSE,
    WAKEUP_BY_CANCEL,
    WAKEUP_BY_CANCELALL,
    WAKEUP_BY_POWER_BUTTON_CLICK,
    WAKEUP_TO_JUMP_HOME,
    WAKEUP_TO_JUMP_APPLICATION,
    WAKEUP_TO_LAUNCH_APPLICATION
};
}
}

#pragma once

#include "../math/VEC.h"
#include <nn/types.h>

namespace nn::hid {
namespace CTR {

struct Direction {
    math::VEC3 x, y, z;
};

struct GyroscopeStatus {
    GyroscopeStatus();

    math::VEC3 speed;
    math::VEC3 angle;
    Direction direction;
};

struct PadReader {
    enum class StickClampMode : u8 {
        STICK_CLAMP_MODE_CIRCLE,
        STICK_CLAMP_MODE_CROSS,
        STICK_CLAMP_MODE_MINIMUM
    };

    u8 field_0x00[0x38];
};

};
};

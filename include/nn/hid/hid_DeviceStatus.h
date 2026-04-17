#pragma once

#include "../math/VEC.h"

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

};
};

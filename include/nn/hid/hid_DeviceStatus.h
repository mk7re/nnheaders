#pragma once

#include "../math/VEC.h"

namespace nn::hid {
namespace CTR {

struct Direction {
    VEC3 x, y, z;
};

struct GyroscopeStatus {
    GyroscopeStatus();

    VEC3 speed;
    VEC3 angle;
    Direction direction;
};

};
};

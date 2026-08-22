#pragma once

#include "VEC.h"

namespace nn::math {

struct Transform3 {
    VEC3 scale;
    VEC3 rotate;
    VEC3 translate;
};

};

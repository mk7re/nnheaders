#pragma once

#include "VEC3.h"

namespace nn::math {

struct Transform3 {
    VEC3 scale;
    VEC3 rotate;
    VEC3 translate;
};

};

#pragma once

#include "../types.h"

namespace nn::math {

struct MTX44 {
    f32 data[4][4];
};

struct MTX34 {
    f32 data[3][4];
};

typedef MTX44 Matrix44;
typedef MTX34 Matrix34;

};

#pragma once

#include "../../types.h"
#include "../../math/VEC.h"

namespace nn::ulcd::CTR {

class StereoCamera {
public:
    struct CameraInfo {
        f32 left;
        f32 right;
        f32 bottom;
        f32 top;
        f32 near;
        f32 far;
        math::Vector3 position;
        math::Vector3 rightDir;
        math::Vector3 upDir;
        math::Vector3 targetDir;
    };

    CameraInfo m_BaseCamera;
    f32 m_LimitParallax;
    f32 m_LevelWidth;
    f32 m_DepthLevel;
    f32 m_DistanceToNearClip;
    f32 m_DistanceToFarClip;
    f32 mCameraInterval;
};

};

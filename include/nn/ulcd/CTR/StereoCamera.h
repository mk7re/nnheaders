#pragma once

#include "../../types.h"
#include "../../math/VEC.h"
#include "../../math/MTX.h"

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

    StereoCamera();
    f32 GetParallax(f32) const;
    void Initialize();
    void CalculateMatrices(math::MTX44*, math::MTX34*, math::MTX44*, math::MTX34*, const math::MTX44*, const math::MTX34*, f32, f32, bool);

    CameraInfo m_BaseCamera;
    f32 m_LimitParallax;
    f32 m_LevelWidth;
    f32 m_DepthLevel;
    f32 m_DistanceToNearClip;
    f32 m_DistanceToFarClip;
    f32 mCameraInterval;
};

};

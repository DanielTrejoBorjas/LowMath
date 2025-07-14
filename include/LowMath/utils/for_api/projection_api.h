#pragma once

#include <lowmath/matrix/Matrix4x4.h>
#include <lowmath/type/ApiType.h>
#include <cmath>

namespace LowMath {


    inline Matrix4x4 makePerspective(
        ApiType api,
        float fovYRadians,
        float aspect,
        float nearZ,
        float farZ
    ) {
        const float f = 1.0f / std::tan(fovYRadians / 2.0f);
        Matrix4x4 m = Matrix4x4::zero();

        switch (api) {
            case ApiType::OpenGL:
                // RH, depth -1 to 1
                m.data[0][0] = f / aspect;
                m.data[1][1] = f;
                m.data[2][2] = (farZ + nearZ) / (nearZ - farZ);
                m.data[2][3] = (2 * farZ * nearZ) / (nearZ - farZ);
                m.data[3][2] = -1.0f;
                break;

            case ApiType::Vulkan:
            case ApiType::Metal:
                // RH, depth 0 to 1
                m.data[0][0] = f / aspect;
                m.data[1][1] = f;
                m.data[2][2] = farZ / (farZ - nearZ);
                m.data[2][3] = -(farZ * nearZ) / (farZ - nearZ);
                m.data[3][2] = 1.0f;
                break;

            case ApiType::DirectX:
                // LH, depth 0 to 1
                m.data[0][0] = f / aspect;
                m.data[1][1] = f;
                m.data[2][2] = farZ / (farZ - nearZ);
                m.data[2][3] = -(farZ * nearZ) / (farZ - nearZ);
                m.data[3][2] = 1.0f;
                break;
        }

        return m;
    }

    inline Matrix4x4 makeOrthographic(
        ApiType api,
        float left,
        float right,
        float bottom,
        float top,
        float nearZ,
        float farZ
    ) {
        Matrix4x4 m = Matrix4x4::zero();

        float rl = right - left;
        float tb = top - bottom;
        float fn = farZ - nearZ;

        m.data[0][0] = 2.0f / rl;
        m.data[1][1] = 2.0f / tb;

        if (api == ApiType::OpenGL) {
            // depth -1 to 1
            m.data[2][2] = -2.0f / fn;
            m.data[3][2] = -(farZ + nearZ) / fn;
        } else {
            // depth 0 to 1
            m.data[2][2] = 1.0f / fn;
            m.data[3][2] = -nearZ / fn;
        }

        m.data[3][0] = -(right + left) / rl;
        m.data[3][1] = -(top + bottom) / tb;
        m.data[3][3] = 1.0f;

        return m;
    }

}

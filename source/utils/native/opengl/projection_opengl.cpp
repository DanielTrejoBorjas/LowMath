
#pragma once
#include <LowMath/matrix/Matrix4x4.h>
#include <cmath>

namespace LowMath {

    Matrix4x4 perspectiveOpenGL(float fovY, float aspect, float near, float far) {
        Matrix4x4 result = Matrix4x4::zero();
        float tanHalfFov = std::tan(fovY * 0.5f);

        result.data[0][0] = 1.0f / (aspect * tanHalfFov);
        result.data[1][1] = 1.0f / tanHalfFov;
        result.data[2][2] = -(far + near) / (far - near);
        result.data[2][3] = -1.0f;
        result.data[3][2] = -(2.0f * far * near) / (far - near);

        return result;
    }

    Matrix4x4 orthographicOpenGL(float left, float right, float bottom, float top, float near, float far) {
        Matrix4x4 result = Matrix4x4::zero();

        result.data[0][0] = 2.0f / (right - left);
        result.data[1][1] = 2.0f / (top - bottom);
        result.data[2][2] = -2.0f / (far - near);
        result.data[3][0] = -(right + left) / (right - left);
        result.data[3][1] = -(top + bottom) / (top - bottom);
        result.data[3][2] = -(far + near) / (far - near);
        result.data[3][3] = 1.0f;

        return result;
    }

}


#pragma once
#include <LowMath/matrix/Matrix4x4.h>

namespace LowMath {

    Matrix4x4 perspectiveOpenGL(float fovY, float aspect, float near, float far);
    Matrix4x4 orthographicOpenGL(float left, float right, float bottom, float top, float near, float far);

}

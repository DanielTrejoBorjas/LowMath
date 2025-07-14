#pragma once

#include <array>

namespace LowMath {
    class Matrix4x4 {
    public:
        std::array<std::array<float, 4>, 4> data;

        Matrix4x4();
        Matrix4x4(const Matrix4x4& other) = default;
        Matrix4x4(const float* values);
        Matrix4x4(
            float a00, float a01, float a02, float a03,
            float a10, float a11, float a12, float a13,
            float a20, float a21, float a22, float a23,
            float a30, float a31, float a32, float a33
        );

        static Matrix4x4 identity();
        static Matrix4x4 zero();

        Matrix4x4 operator*(const Matrix4x4& other) const;
        Matrix4x4 operator*(float scalar) const;
        Matrix4x4 operator/(float scalar) const;
        Matrix4x4 operator+(const Matrix4x4& other) const;
        Matrix4x4 operator-(const Matrix4x4& other) const;

        bool operator==(const Matrix4x4& other) const;
        bool operator!=(const Matrix4x4& other) const;
    };
}
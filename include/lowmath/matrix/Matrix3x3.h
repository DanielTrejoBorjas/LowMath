#pragma once

#include <array>

class Matrix3x3 {
public:
    std::array<std::array<float, 3>, 3> data;

    Matrix3x3();
    Matrix3x3(const Matrix3x3& other) = default;
    Matrix3x3(const float* values);
    Matrix3x3(
        float a00, float a01, float a02,
        float a10, float a11, float a12,
        float a20, float a21, float a22
    );

    static Matrix3x3 identity();
    static Matrix3x3 zero();

    Matrix3x3 operator*(const Matrix3x3& other) const;
    Matrix3x3 operator*(float scalar) const;
    Matrix3x3 operator/(float scalar) const;
    Matrix3x3 operator+(const Matrix3x3& other) const;
    Matrix3x3 operator-(const Matrix3x3& other) const;

    bool operator==(const Matrix3x3& other) const;
    bool operator!=(const Matrix3x3& other) const;
};

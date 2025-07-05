#pragma once

class Matrix2x2 {
public:
    float data[2][2];

    Matrix2x2();
    Matrix2x2(const Matrix2x2& other);
    Matrix2x2(const float* values);
    Matrix2x2(
        float a00, float a01,
        float a10, float a11
    );

    static Matrix2x2 identity();
    static Matrix2x2 zero();

    Matrix2x2 operator*(const Matrix2x2& other) const;
    Matrix2x2 operator*(float scalar) const;
    Matrix2x2 operator+(const Matrix2x2& other) const;
    Matrix2x2 operator-(const Matrix2x2& other) const;

    bool operator==(const Matrix2x2& other) const;
    bool operator!=(const Matrix2x2& other) const;
};

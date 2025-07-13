
#pragma once

class Vector4 {
public:
    float x, y, z, w;

    Vector4();
    Vector4(float x, float y, float z, float w);

    // Element-wise operators
    Vector4 operator+(const Vector4& other) const;
    Vector4 operator-(const Vector4& other) const;
    Vector4 operator*(const Vector4& other) const;
    Vector4 operator/(const Vector4& other) const;

    // Scalar operators
    Vector4 operator*(float scalar) const;
    Vector4 operator/(float scalar) const;

    // Comparators
    bool operator==(const Vector4& other) const;
    bool operator!=(const Vector4& other) const;
};

#pragma once
#include <cmath>

namespace LowMath {
    class Vector4 {
    public:
        float x, y, z, w;

        Vector4();
        Vector4(float x, float y, float z, float w);

        // OPERATORS
        Vector4 operator+(const Vector4& other) const;
        Vector4 operator-(const Vector4& other) const;
        Vector4 operator*(const Vector4& other) const;
        Vector4 operator/(const Vector4& other) const;

        Vector4 operator*(float scalar) const;
        Vector4 operator/(float scalar) const;

        bool operator==(const Vector4& other) const;
        bool operator!=(const Vector4& other) const;

        // UTILS
        float length() const;
        Vector4 normalized() const;
        float dot(const Vector4& other) const;
        float distance(const Vector4& other) const;
        Vector4 lerp(const Vector4& other, float t) const;
        Vector4 clamp(float minVal, float maxVal) const;
    };
}

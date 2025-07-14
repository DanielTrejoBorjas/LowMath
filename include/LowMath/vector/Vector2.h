#pragma once
#include <cmath>

namespace LowMath {
    class Vector2 {
    public:
        float x, y;

        Vector2();
        Vector2(float x, float y);

        // OPERATORS
        Vector2 operator+(const Vector2& other) const;
        Vector2 operator-(const Vector2& other) const;
        Vector2 operator*(const Vector2& other) const;
        Vector2 operator/(const Vector2& other) const;

        Vector2 operator*(float scalar) const;
        Vector2 operator/(float scalar) const;

        bool operator==(const Vector2& other) const;
        bool operator!=(const Vector2& other) const;

        // UTILS
        float length() const;
        Vector2 normalized() const;
        float dot(const Vector2& other) const;
        float distance(const Vector2& other) const;
        Vector2 lerp(const Vector2& other, float t) const;
        Vector2 clamp(float minVal, float maxVal) const;
        Vector2 reflect(const Vector2& normal) const;
    };
}

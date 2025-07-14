#pragma once
#include <cmath>

namespace LowMath {
    class Vector3 {
    public:
        float x, y, z;

        Vector3();
        Vector3(float x, float y, float z);

        // OPERATORS
        Vector3 operator+(const Vector3& other) const;
        Vector3 operator-(const Vector3& other) const;
        Vector3 operator*(const Vector3& other) const;
        Vector3 operator/(const Vector3& other) const;

        Vector3 operator*(float scalar) const;
        Vector3 operator/(float scalar) const;

        bool operator==(const Vector3& other) const;
        bool operator!=(const Vector3& other) const;

        // UTILS
        float length() const;
        Vector3 normalized() const;
        float dot(const Vector3& other) const;
        Vector3 cross(const Vector3& other) const;
        float distance(const Vector3& other) const;
        Vector3 lerp(const Vector3& other, float t) const;
        Vector3 clamp(float minVal, float maxVal) const;
        Vector3 reflect(const Vector3& normal) const;
    };
}

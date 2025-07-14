
#pragma once

namespace LowMath {
    class Vector3 {
    public:
        float x, y, z;

        Vector3();
        Vector3(float x, float y, float z);

        // Element-wise operators
        Vector3 operator+(const Vector3& other) const;
        Vector3 operator-(const Vector3& other) const;
        Vector3 operator*(const Vector3& other) const;
        Vector3 operator/(const Vector3& other) const;

        // Scalar operators
        Vector3 operator*(float scalar) const;
        Vector3 operator/(float scalar) const;

        // Comparators
        bool operator==(const Vector3& other) const;
        bool operator!=(const Vector3& other) const;
    };
}
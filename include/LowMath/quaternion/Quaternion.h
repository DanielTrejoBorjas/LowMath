#pragma once
#include <LowMath/matrix/Matrix4x4.h>
#include <LowMath/vector/Vector3.h>


namespace LowMath {
    class Quaternion {
    public:
        float x, y, z, w;

        Quaternion();
        Quaternion(float x, float y, float z, float w);

        Quaternion operator*(const Quaternion& other) const;
        Quaternion operator*(float scalar) const;
        Quaternion operator/(float scalar) const;
        Quaternion operator+(const Quaternion& other) const;
        Quaternion operator-(const Quaternion& other) const;

        bool operator==(const Quaternion& other) const;
        bool operator!=(const Quaternion& other) const;

        // UTILS
        float norm() const;
        Quaternion normalized() const;
        Quaternion conjugate() const;
        Quaternion inverse() const;
        float dot(const Quaternion& other) const;

        Matrix4x4 toRotationMatrix() const;

        static Quaternion fromAxisAngle(const Vector3& axis, float angle);
        void toAxisAngle(Vector3& axis, float& angle) const;

        Quaternion slerp(const Quaternion& target, float t) const;

    };
}
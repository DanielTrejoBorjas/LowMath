#pragma once


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
    };
}
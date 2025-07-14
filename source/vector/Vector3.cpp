#include <LowMath/vector/Vector3.h>

namespace LowMath {
    Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3 Vector3::operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 Vector3::operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 Vector3::operator*(const Vector3& other) const {
        return Vector3(x * other.x, y * other.y, z * other.z);
    }

    Vector3 Vector3::operator/(const Vector3& other) const {
        return Vector3(x / other.x, y / other.y, z / other.z);
    }

    Vector3 Vector3::operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3 Vector3::operator/(float scalar) const {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    bool Vector3::operator==(const Vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool Vector3::operator!=(const Vector3& other) const {
        return !(*this == other);
    }

    // UTILS
    float Vector3::length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3 Vector3::normalized() const {
        float len = length();
        if (len == 0.0f) return Vector3(0, 0, 0);
        return *this / len;
    }

    float Vector3::dot(const Vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3 Vector3::cross(const Vector3& other) const {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    float Vector3::distance(const Vector3& other) const {
        return (*this - other).length();
    }

    Vector3 Vector3::lerp(const Vector3& other, float t) const {
        return *this * (1.0f - t) + other * t;
    }

    Vector3 Vector3::clamp(float minVal, float maxVal) const {
        auto clampVal = [](float v, float minV, float maxV) {
            if (v < minV) return minV;
            if (v > maxV) return maxV;
            return v;
        };
        return Vector3(
            clampVal(x, minVal, maxVal),
            clampVal(y, minVal, maxVal),
            clampVal(z, minVal, maxVal)
        );
    }

    Vector3 Vector3::reflect(const Vector3& normal) const {
        return *this - normal * (2.0f * this->dot(normal));
    }
}

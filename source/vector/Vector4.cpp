#include <LowMath/vector/Vector4.h>

namespace LowMath {
    Vector4::Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
    Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    Vector4 Vector4::operator+(const Vector4& other) const {
        return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    Vector4 Vector4::operator-(const Vector4& other) const {
        return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    Vector4 Vector4::operator*(const Vector4& other) const {
        return Vector4(x * other.x, y * other.y, z * other.z, w * other.w);
    }

    Vector4 Vector4::operator/(const Vector4& other) const {
        return Vector4(x / other.x, y / other.y, z / other.z, w / other.w);
    }

    Vector4 Vector4::operator*(float scalar) const {
        return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    Vector4 Vector4::operator/(float scalar) const {
        return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
    }

    bool Vector4::operator==(const Vector4& other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool Vector4::operator!=(const Vector4& other) const {
        return !(*this == other);
    }

    // UTILS
    float Vector4::length() const {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    Vector4 Vector4::normalized() const {
        float len = length();
        if (len == 0.0f) return Vector4(0, 0, 0, 0);
        return *this / len;
    }

    float Vector4::dot(const Vector4& other) const {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    float Vector4::distance(const Vector4& other) const {
        return (*this - other).length();
    }

    Vector4 Vector4::lerp(const Vector4& other, float t) const {
        return *this * (1.0f - t) + other * t;
    }

    Vector4 Vector4::clamp(float minVal, float maxVal) const {
        auto clampVal = [](float v, float minV, float maxV) {
            if (v < minV) return minV;
            if (v > maxV) return maxV;
            return v;
        };
        return Vector4(
            clampVal(x, minVal, maxVal),
            clampVal(y, minVal, maxVal),
            clampVal(z, minVal, maxVal),
            clampVal(w, minVal, maxVal)
        );
    }
}

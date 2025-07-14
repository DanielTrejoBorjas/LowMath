#include <LowMath/vector/Vector2.h>

namespace LowMath {
    Vector2::Vector2() : x(0.0f), y(0.0f) {}
    Vector2::Vector2(float x, float y) : x(x), y(y) {}

    Vector2 Vector2::operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 Vector2::operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 Vector2::operator*(const Vector2& other) const {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 Vector2::operator/(const Vector2& other) const {
        return Vector2(x / other.x, y / other.y);
    }

    Vector2 Vector2::operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    Vector2 Vector2::operator/(float scalar) const {
        return Vector2(x / scalar, y / scalar);
    }

    bool Vector2::operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }

    bool Vector2::operator!=(const Vector2& other) const {
        return !(*this == other);
    }

    // UTILS
    float Vector2::length() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2 Vector2::normalized() const {
        float len = length();
        if (len == 0.0f) return Vector2(0, 0);
        return *this / len;
    }

    float Vector2::dot(const Vector2& other) const {
        return x * other.x + y * other.y;
    }

    float Vector2::distance(const Vector2& other) const {
        return (*this - other).length();
    }

    Vector2 Vector2::lerp(const Vector2& other, float t) const {
        return *this * (1.0f - t) + other * t;
    }

    Vector2 Vector2::clamp(float minVal, float maxVal) const {
        auto clampVal = [](float v, float minV, float maxV) {
            if (v < minV) return minV;
            if (v > maxV) return maxV;
            return v;
        };
        return Vector2(
            clampVal(x, minVal, maxVal),
            clampVal(y, minVal, maxVal)
        );
    }

    Vector2 Vector2::reflect(const Vector2& normal) const {
        return *this - normal * (2.0f * this->dot(normal));
    }
}

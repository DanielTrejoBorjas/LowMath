#include <LowMath/vector/Vector3.h>
namespace LowMath {
    Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

    Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    // Element-wise operators
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

    // Scalar operators
    Vector3 Vector3::operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3 Vector3::operator/(float scalar) const {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    // Comparators
    bool Vector3::operator==(const Vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool Vector3::operator!=(const Vector3& other) const {
        return !(*this == other);
    }
}
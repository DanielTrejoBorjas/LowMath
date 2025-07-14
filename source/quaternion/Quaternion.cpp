#include <LowMath/quaternion/Quaternion.h>

namespace LowMath {
    Quaternion::Quaternion() : x(0), y(0), z(0), w(1) {
    }

    Quaternion::Quaternion(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w) {
    }

    Quaternion Quaternion::operator*(const Quaternion &other) const {
        return Quaternion(
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w,
            w * other.w - x * other.x - y * other.y - z * other.z
        );
    }

    Quaternion Quaternion::operator*(float scalar) const {
        return Quaternion(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    Quaternion Quaternion::operator/(float scalar) const {
        return Quaternion(x / scalar, y / scalar, z / scalar, w / scalar);
    }

    Quaternion Quaternion::operator+(const Quaternion &other) const {
        return Quaternion(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    Quaternion Quaternion::operator-(const Quaternion &other) const {
        return Quaternion(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    bool Quaternion::operator==(const Quaternion &other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool Quaternion::operator!=(const Quaternion &other) const {
        return !(*this == other);
    }

    //=========================UTILS=====================

    float Quaternion::norm() const {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    Quaternion Quaternion::normalized() const {
        float n = norm();
        if (n == 0) return Quaternion(0, 0, 0, 1);
        return *this / n;
    }

    Quaternion Quaternion::conjugate() const {
        return Quaternion(-x, -y, -z, w);
    }

    Quaternion Quaternion::inverse() const {
        float n = norm();
        if (n == 0) return Quaternion(0, 0, 0, 1);
        return conjugate() / (n * n);
    }

    float Quaternion::dot(const Quaternion &other) const {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    Matrix4x4 Quaternion::toRotationMatrix() const {
        float xx = x * x;
        float yy = y * y;
        float zz = z * z;
        float xy = x * y;
        float xz = x * z;
        float yz = y * z;
        float wx = w * x;
        float wy = w * y;
        float wz = w * z;

        return Matrix4x4(
            1 - 2 * (yy + zz), 2 * (xy - wz), 2 * (xz + wy), 0,
            2 * (xy + wz), 1 - 2 * (xx + zz), 2 * (yz - wx), 0,
            2 * (xz - wy), 2 * (yz + wx), 1 - 2 * (xx + yy), 0,
            0, 0, 0, 1
        );
    }

    Quaternion Quaternion::fromAxisAngle(const Vector3 &axis, float angle) {
        float halfAngle = angle * 0.5f;
        float s = std::sin(halfAngle);
        return Quaternion(
            axis.x * s,
            axis.y * s,
            axis.z * s,
            std::cos(halfAngle)
        ).normalized();
    }

    void Quaternion::toAxisAngle(Vector3 &axis, float &angle) const {
        Quaternion q = normalized();
        angle = 2 * std::acos(q.w);
        float s = std::sqrt(1 - q.w * q.w);
        if (s < 0.001f) {
            axis = Vector3(1, 0, 0);
        } else {
            axis = Vector3(q.x / s, q.y / s, q.z / s);
        }
    }

    Quaternion Quaternion::slerp(const Quaternion &target, float t) const {
        // Compute the cosine of the angle between the two quaternions.
        float dotProd = dot(target);

        // If the dot product is negative, slerp won't take
        // the shorter path. Fix by reversing one quaternion.
        Quaternion targetAdjusted = target;
        if (dotProd < 0.0f) {
            targetAdjusted = target * -1.0f;
            dotProd = -dotProd;
        }

        const float DOT_THRESHOLD = 0.9995f;
        if (dotProd > DOT_THRESHOLD) {
            // Quaternions are very close, use linear interpolation
            Quaternion result = *this + (targetAdjusted - *this) * t;
            return result.normalized();
        }

        // Calculate the angle between the quaternions
        float theta_0 = std::acos(dotProd);
        float theta = theta_0 * t;

        Quaternion q2 = (targetAdjusted - *this * dotProd).normalized();

        return *this * std::cos(theta) + q2 * std::sin(theta);
    }
}


#include <LowMath/matrix/Matrix3x3.h>

namespace LowMath {
    Matrix3x3::Matrix3x3() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                data[i][j] = (i == j) ? 1.0f : 0.0f;
    }

    Matrix3x3::Matrix3x3(const float* values) {
        for (int i = 0; i < 9; ++i)
            data[i / 3][i % 3] = values[i];
    }

    Matrix3x3::Matrix3x3(
        float a00, float a01, float a02,
        float a10, float a11, float a12,
        float a20, float a21, float a22
    ) {
        data[0] = { a00, a01, a02 };
        data[1] = { a10, a11, a12 };
        data[2] = { a20, a21, a22 };
    }

    Matrix3x3 Matrix3x3::identity() {
        return Matrix3x3();
    }

    Matrix3x3 Matrix3x3::zero() {
        Matrix3x3 result{};
        for (auto& row : result.data)
            row.fill(0.0f);
        return result;
    }

    Matrix3x3 Matrix3x3::operator*(const Matrix3x3& other) const {
        Matrix3x3 result = Matrix3x3::zero();
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    Matrix3x3 Matrix3x3::operator*(float scalar) const {
        Matrix3x3 result;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                result.data[i][j] = data[i][j] * scalar;
        return result;
    }

    Matrix3x3 Matrix3x3::operator/(float scalar) const {
        Matrix3x3 result;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                result.data[i][j] = data[i][j] / scalar;
        return result;
    }

    Matrix3x3 Matrix3x3::operator+(const Matrix3x3& other) const {
        Matrix3x3 result;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix3x3 Matrix3x3::operator-(const Matrix3x3& other) const {
        Matrix3x3 result;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    bool Matrix3x3::operator==(const Matrix3x3& other) const {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (data[i][j] != other.data[i][j])
                    return false;
        return true;
    }

    bool Matrix3x3::operator!=(const Matrix3x3& other) const {
        return !(*this == other);
    }
}
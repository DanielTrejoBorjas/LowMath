#include <LowMath/matrix/Matrix2x2.h>

namespace LowMath {
    Matrix2x2::Matrix2x2() {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                data[i][j] = (i == j) ? 1.0f : 0.0f;
    }

    Matrix2x2::Matrix2x2(const float* values) {
        for (int i = 0; i < 4; ++i)
            data[i / 2][i % 2] = values[i];
    }

    Matrix2x2::Matrix2x2(
        float a00, float a01,
        float a10, float a11
    ) {
        data[0] = { a00, a01 };
        data[1] = { a10, a11 };
    }

    Matrix2x2 Matrix2x2::identity() {
        return Matrix2x2();
    }

    Matrix2x2 Matrix2x2::zero() {
        Matrix2x2 result{};
        for (auto& row : result.data)
            row.fill(0.0f);
        return result;
    }

    Matrix2x2 Matrix2x2::operator*(const Matrix2x2& other) const {
        Matrix2x2 result = Matrix2x2::zero();
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    Matrix2x2 Matrix2x2::operator*(float scalar) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                result.data[i][j] = data[i][j] * scalar;
        return result;
    }

    Matrix2x2 Matrix2x2::operator/(float scalar) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                result.data[i][j] = data[i][j] / scalar;
        return result;
    }

    Matrix2x2 Matrix2x2::operator+(const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix2x2 Matrix2x2::operator-(const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    bool Matrix2x2::operator==(const Matrix2x2& other) const {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                if (data[i][j] != other.data[i][j])
                    return false;
        return true;
    }

    bool Matrix2x2::operator!=(const Matrix2x2& other) const {
        return !(*this == other);
    }
}
#include <lowmath/matrix/Matrix2x2.h>

Matrix2x2::Matrix2x2() {
    data[0][0] = 1.0f; data[0][1] = 0.0f;
    data[1][0] = 0.0f; data[1][1] = 1.0f;
}

Matrix2x2::Matrix2x2(const Matrix2x2& other) {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            data[i][j] = other.data[i][j];
}

Matrix2x2::Matrix2x2(const float* values) {
    for (int i = 0; i < 4; ++i)
        data[i / 2][i % 2] = values[i];
}

Matrix2x2::Matrix2x2(
    float a00, float a01,
    float a10, float a11
) {
    data[0][0] = a00; data[0][1] = a01;
    data[1][0] = a10; data[1][1] = a11;
}

Matrix2x2 Matrix2x2::identity() {
    return Matrix2x2();
}

Matrix2x2 Matrix2x2::zero() {
    Matrix2x2 result;
    result.data[0][0] = 0.0f; result.data[0][1] = 0.0f;
    result.data[1][0] = 0.0f; result.data[1][1] = 0.0f;
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


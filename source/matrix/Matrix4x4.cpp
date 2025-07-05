
#include <lowmath/matrix/Matrix4x4.h>

Matrix4x4::Matrix4x4() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            data[i][j] = (i == j) ? 1.0f : 0.0f;
}

Matrix4x4::Matrix4x4(const Matrix4x4& other) {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            data[i][j] = other.data[i][j];
}

Matrix4x4::Matrix4x4(const float* values) {
    for (int i = 0; i < 16; ++i)
        data[i / 4][i % 4] = values[i];
}

Matrix4x4::Matrix4x4(
    float a00, float a01, float a02, float a03,
    float a10, float a11, float a12, float a13,
    float a20, float a21, float a22, float a23,
    float a30, float a31, float a32, float a33
) {
    data[0][0] = a00; data[0][1] = a01; data[0][2] = a02; data[0][3] = a03;
    data[1][0] = a10; data[1][1] = a11; data[1][2] = a12; data[1][3] = a13;
    data[2][0] = a20; data[2][1] = a21; data[2][2] = a22; data[2][3] = a23;
    data[3][0] = a30; data[3][1] = a31; data[3][2] = a32; data[3][3] = a33;
}

Matrix4x4 Matrix4x4::identity() {
    return Matrix4x4();
}

Matrix4x4 Matrix4x4::zero() {
    Matrix4x4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result.data[i][j] = 0.0f;
    return result;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other) const {
    Matrix4x4 result = Matrix4x4::zero();
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

Matrix4x4 Matrix4x4::operator*(float scalar) const {
    Matrix4x4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result.data[i][j] = data[i][j] * scalar;
    return result;
}

Matrix4x4 Matrix4x4::operator/(float scalar) const {
    Matrix4x4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result.data[i][j] = data[i][j] / scalar;
    return result;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& other) const {
    Matrix4x4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& other) const {
    Matrix4x4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
}

bool Matrix4x4::operator==(const Matrix4x4& other) const {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (data[i][j] != other.data[i][j])
                return false;
    return true;
}

bool Matrix4x4::operator!=(const Matrix4x4& other) const {
    return !(*this == other);
}

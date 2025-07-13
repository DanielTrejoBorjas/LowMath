#pragma once

class Vector2 {
public:
    float x, y;

    Vector2();
    Vector2(float x, float y);

    // Element-wise operators
    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(const Vector2& other) const;
    Vector2 operator/(const Vector2& other) const;

    // Scalar operators
    Vector2 operator*(float scalar) const;
    Vector2 operator/(float scalar) const;

    // Comparators
    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;

};

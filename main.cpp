#include <iostream>
#include <LowMath/vector/Vector.h>

void printVector(const Vector2& v, const std::string& name) {
    std::cout << name << ": (" << v.x << ", " << v.y << ")\n";
}

int main() {
    Vector2 v1(1, 2);
    Vector2 v2(2, 2);

    Vector2 v3 = v2 + v1;
    Vector2 v4 = v2 - v1;
    Vector2 v5 = v2 * v1;
    Vector2 v6 = v2 / v1;

    printVector(v3, "v2 + v1");
    printVector(v4, "v2 - v1");
    printVector(v5, "v2 * v1");
    printVector(v6, "v2 / v1");

    // Operaciones con escalares
    Vector2 v7 = v1 * 3.0f;
    Vector2 v8 = v2 / 2.0f;
    printVector(v7, "v1 * 3");
    printVector(v8, "v2 / 2");

    // Comparación
    std::cout << "v1 == v2: " << (v1 == v2 ? "true" : "false") << "\n";
    std::cout << "v1 != v2: " << (v1 != v2 ? "true" : "false") << "\n";

    return 0;
}

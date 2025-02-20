#include <iostream>
#include "include/vector2.h"
#include "include/vector3.h"
#include "include/matrix3.h"
#include "include/matrix4.h"
#include "include/transform.h"

int main() {
    // Test vector2
    Vector2 v2a(1, 2);
    Vector2 v2b(3, 4);
    Vector2 v2c = v2a + v2b;
	std::cout << "Vector2 addition: ";
    v2c.print();

    // Test vector3
    Vector3 v3a(1, 2, 3);
    Vector3 v3b(4, 5, 6);
	std::cout << "Vector3 cross product: ";
	Vector3 v3c = v3a.cross(v3b);
    v3c.print();

    // Test matrix3
    Matrix3 m3a;
    Matrix3 m3b;
    Matrix3 m3c = m3a * m3b;
	std::cout << "Matrix3 multiplication: ";
    m3c.print();

    // Test matrix4
    Matrix4 m4a;
    Matrix4 m4b;
    Matrix4 m4c = m4a * m4b;
	std::cout << "Matrix4 multiplication: ";
    m4c.print();

    // Test transform
    Transform transform;
    transform.position = Vector3(1, 2, 3);
    transform.rotation = Vector3(45, 0, 0);
    transform.scale = Vector3(1, 1, 1);
	std::cout << "Transformation matrix: ";
    Matrix4 transformMatrix = transform.getMatrix();
    transformMatrix.print();

    // Pause the console
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.get();

    return 0;
}
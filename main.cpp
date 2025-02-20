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
    Matrix4 mat;
	mat.data[0][0] = 2; mat.data[0][1] = 0; mat.data[0][2] = 0; mat.data[0][3] = 1;
	mat.data[1][0] = 0; mat.data[1][1] = 2; mat.data[1][2] = 0; mat.data[1][3] = 2;
	mat.data[2][0] = 0; mat.data[2][1] = 0; mat.data[2][2] = 2; mat.data[2][3] = 3;
	mat.data[3][0] = 0; mat.data[3][1] = 0; mat.data[3][2] = 0; mat.data[3][3] = 1;

	std::cout << "Original matrix: " << std::endl;
	mat.print();

	// Compute the determinant
	float det = mat.determinant();
	std::cout << "Determinant: " << det << std::endl;

	// Compute the inverse
	Matrix4 inv = mat.inverse();
	std::cout << "Inverse matrix: " << std::endl;
	inv.print();

	// Verify inverse by multiplying with original matrix
	Matrix4 identity = mat * inv;
	std::cout << "Identity matrix: " << std::endl;
	identity.print();

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
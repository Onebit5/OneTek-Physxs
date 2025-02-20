#include <cmath>
#include <iostream>
#include "../include/transform.h"

// Constructor
Transform::Transform() : position(0.0f, 0.0f, 0.0f), rotation(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f) {}

// Transformation matrix
Matrix4 Transform::getMatrix() const {
	Matrix4 translation;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			translation.data[i][j] = (i == j) ? 1.0f : 0.0f;
		}
	}
	translation.data[0][3] = position.x;
	translation.data[1][3] = position.y;
	translation.data[2][3] = position.z;

	// Convert rotation angles to radians
	constexpr float M_PI_F = 3.14159265358979323846f;
	float radX = rotation.x * M_PI_F / 180.0f;
	float radY = rotation.y * M_PI_F / 180.0f;
	float radZ = rotation.z * M_PI_F / 180.0f;

	Matrix4 rotationX;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			rotationX.data[i][j] = (i == j) ? 1.0f : 0.0f;
		}
	}
	rotationX.data[1][1] = cosf(radX);
	rotationX.data[1][2] = -sinf(radX);
	rotationX.data[2][1] = sinf(radX);
	rotationX.data[2][2] = cosf(radX);

	Matrix4 rotationY;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			rotationY.data[i][j] = (i == j) ? 1.0f : 0.0f;
		}
	}
	rotationY.data[0][0] = cosf(radY);
	rotationY.data[0][2] = sinf(radY);
	rotationY.data[2][0] = -sinf(radY);
	rotationY.data[2][2] = cosf(radY);

	Matrix4 rotationZ;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			rotationZ.data[i][j] = (i == j) ? 1.0f : 0.0f;
		}
	}
	rotationZ.data[0][0] = cosf(radZ);
	rotationZ.data[0][1] = -sinf(radZ);
	rotationZ.data[1][0] = sinf(radZ);
	rotationZ.data[1][1] = cosf(radZ);

	Matrix4 scaling;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scaling.data[i][j] = (i == j) ? 1.0f : 0.0f;
		}
	}
	scaling.data[0][0] = scale.x;
	scaling.data[1][1] = scale.y;
	scaling.data[2][2] = scale.z;

	return translation * rotationX * rotationY * rotationZ * scaling;
}

// Print the transform
void Transform::print() const {
	std::cout << "Position: ";
	position.print();
	std::cout << "Rotation: ";
	rotation.print();
	std::cout << "Scale: ";
	scale.print();
}

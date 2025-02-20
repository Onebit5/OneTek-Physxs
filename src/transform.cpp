## Code Commented

```cpp
#include <cmath>
#include <iostream>
#include "../include/transform.h"

// Constructor initializes position, rotation, and scale
Transform::Transform() : position(0.0f, 0.0f, 0.0f), rotation(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f) {}

// Transformation matrix
Matrix4 Transform::getMatrix() const {
	Matrix4 translation;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			translation.data[i][j] = (i == j) ? 1.0f : 0.0f; // Initialize identity matrix
		}
	}
	translation.data[0][3] = position.x; // Set translation in x-axis
	translation.data[1][3] = position.y; // Set translation in y-axis
	translation.data[2][3] = position.z; // Set translation in z-axis

	// Convert rotation angles to radians
	constexpr float M_PI_F = 3.14159265358979323846f;
	float radX = rotation.x * M_PI_F / 180.0f; // Convert x rotation to radians
	float radY = rotation.y * M_PI_F / 180.0f; // Convert y rotation to radians
	float radZ = rotation.z * M_PI_F / 180.0f; // Convert z rotation to radians

	Matrix4 rotationX;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			rotationX.data[i][j] = (i == j) ? 1.0f : 0.0f; // Initialize identity matrix
		}
	}
	rotationX.data[1][1] = cosf(radX);	// Set rotation around x-axis
	rotationX.data[1][2] = -sinf(radX); // Set rotation around x-axis
	rotationX.data[2][1] = sinf(radX);	// Set rotation around x-axis
	rotationX.data[2][2] = cosf(radX);	// Set rotation around x-axis

	Matrix4 rotationY;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			rotationY.data[i][j] = (i == j) ? 1.0f : 0.0f; // Initialize identity matrix
		}
	}
	rotationY.data[0][0] = cosf(radY);	// Set rotation around y-axis
	rotationY.data[0][2] = sinf(radY);	// Set rotation around y-axis
	rotationY.data[2][0] = -sinf(radY); // Set rotation around y-axis
	rotationY.data[2][2] = cosf(radY);	// Set rotation around y-axis

	Matrix4 rotationZ;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			rotationZ.data[i][j] = (i == j) ? 1.0f : 0.0f; // Initialize identity matrix
		}
	}
	rotationZ.data[0][0] = cosf(radZ);	// Set rotation around z-axis
	rotationZ.data[0][1] = -sinf(radZ); // Set rotation around z-axis
	rotationZ.data[1][0] = sinf(radZ);	// Set rotation around z-axis
	rotationZ.data[1][1] = cosf(radZ);	// Set rotation around z-axis

	Matrix4 scaling;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scaling.data[i][j] = (i == j) ? 1.0f : 0.0f; // Initialize identity matrix
		}
	}
	scaling.data[0][0] = scale.x; // Set scaling in x-axis
	scaling.data[1][1] = scale.y; // Set scaling in y-axis
	scaling.data[2][2] = scale.z; // Set scaling in z-axis

	return translation * rotationX * rotationY * rotationZ * scaling; // Return the combined transformation matrix
}

// Print the transform
void Transform::print() const {
	std::cout << "Position: ";		// Output position
	position.print();				// Print position details
	std::cout << "Rotation: ";		// Output rotation
	rotation.print();				// Print rotation details
	std::cout << "Scale: ";			// Output scale
	scale.print();					// Print scale details
}
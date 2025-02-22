#ifndef MATRIX4_H
#define MATRIX4_H

#include <iostream>
#include "vector3.h"

class Matrix4
{
public:
	float data[4][4]; // 2D array to hold the elements of a 4x4 matrix

	// Constructor (identity matrix by default)
	Matrix4();

	// Matrix multiplication
	Matrix4 operator*(const Matrix4& other) const;

	Vector3 operator*(const Vector3& vec) const;

	// Determinant
	float determinant() const;

	// Inverse
	Matrix4 inverse() const;

	// Utility
	void print() const;

	// Helper function to compute the determinant of a 3x3 submatrix
	static float determinant3x3(
		float a, float b, float c,
		float d, float e, float f,
		float g, float h, float i
	);
};

#endif
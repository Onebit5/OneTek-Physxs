#ifndef MATRIX4_H
#define MATRIX4_H

#include <iostream>

class Matrix4
{
public:
	float data[4][4];

	// Constructor (identity matrix by default)
	Matrix4();

	// Matrix multiplication
	Matrix4 operator*(const Matrix4& other) const;

	// Determinant
	float determinant() const;

	// Inverse
	Matrix4 inverse() const;

	// Utility
	void print() const;

};

#endif
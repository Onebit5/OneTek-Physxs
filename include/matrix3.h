#ifndef MATRIX3_H
#define MATRIX3_H

#include <iostream>

class Matrix3
{
public:
	float data[3][3];

	// Constructor (identity matrix by default)
	Matrix3();

	// Matrix multiplication
	Matrix3 operator*(const Matrix3& other) const;

	// Determinant
	float determinant() const;

	// Inverse
	Matrix3 inverse() const;

	// Utility
	void print() const;

};

#endif
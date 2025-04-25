#ifndef MATRIX3_H
#define MATRIX3_H

#include <iostream>
#include "vector2.h"

class Matrix3
{
public:
	float data[3][3]; // 2D array to hold the elements of a 3x3 matrix

	// Constructor (identity matrix by default)
	Matrix3();

	// Matrix multiplication
	Matrix3 operator*(const Matrix3& other) const;

	Vector2 operator*(const Vector2& vec) const;

	// Determinant
	float determinant() const;

	// Inverse
	Matrix3 inverse() const;

	// Additional operator overloads
	Matrix3& operator*=(const Matrix3& other);
	Matrix3 operator+(const Matrix3& other) const;
	Matrix3& operator+=(const Matrix3& other);
	Matrix3 operator-(const Matrix3& other) const;
	Matrix3& operator-=(const Matrix3& other);
	Matrix3 operator*(float scalar) const;
	Matrix3& operator*=(float scalar);

	// Interpolation
	static Matrix3 lerp(const Matrix3& a, const Matrix3& b, float t);

	// Utility
	void print() const;

};

#endif
#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <cmath>

class Vector3 {
public:
	float x, y, z;

	// Constructors
	Vector3(float x = 0, float y = 0, float z = 0);

	// Vector operations
	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	Vector3 operator*(float scalar) const;
	float dot(const Vector3& other) const;
	Vector3 cross(const Vector3& other) const;
	float magnitude() const;
	Vector3 normalize() const;

	// Utility
	void print() const;

};

#endif
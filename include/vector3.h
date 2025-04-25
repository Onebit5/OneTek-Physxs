#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <cmath>

class Vector3 {
public:
	float x, y, z; // Public member variables to store the x, y and z coordinates of the vector

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

	// Additional operator overloads
	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);
	Vector3& operator*=(float scalar);
	Vector3& operator/=(float scalar);
	Vector3 operator/(float scalar) const;

	// Interpolation
	static Vector3 lerp(const Vector3& a, const Vector3& b, float t);
	static Vector3 slerp(const Vector3& a, const Vector3& b, float t);

	// Reflection and projection
	Vector3 reflect(const Vector3& normal) const;
	Vector3 project(const Vector3& onto) const;

	// Component-wise operations
	static Vector3 min(const Vector3& a, const Vector3& b);
	static Vector3 max(const Vector3& a, const Vector3& b);
	static Vector3 clamp(const Vector3& value, const Vector3& min, const Vector3& max);

	// Utility
	void print() const;

};

#endif
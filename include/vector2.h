#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>
#include <cmath>

class Vector2
{
public:
	float x, y; // Public member variables to store the x and y coordinates of the vector

	// Constructors
	Vector2(float x = 0, float y = 0);

	// Vector operations
	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator*(float scalar) const;
	float dot(const Vector2& other) const;
	float magnitude() const;
	Vector2 normalize() const;

	// Additional operator overloads
	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	Vector2& operator*=(float scalar);
	Vector2& operator/=(float scalar);
	Vector2 operator/(float scalar) const;

	// Interpolation
	static Vector2 lerp(const Vector2& a, const Vector2& b, float t);

	// Reflection and projection
	Vector2 reflect(const Vector2& normal) const;
	Vector2 project(const Vector2& onto) const;

	// Component-wise operations
	static Vector2 min(const Vector2& a, const Vector2& b);
	static Vector2 max(const Vector2& a, const Vector2& b);
	static Vector2 clamp(const Vector2& value, const Vector2& min, const Vector2& max);

	// Utility
	void print() const;

};

#endif
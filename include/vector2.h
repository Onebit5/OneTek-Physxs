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

	// Utility
	void print() const;

};

#endif
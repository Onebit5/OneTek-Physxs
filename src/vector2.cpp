#include <cmath>
#include <iostream>
#include "../include/vector2.h"

// Constructor
Vector2::Vector2(float x, float y) : x(x), y(y) {}

// Vector operations
Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float scalar) const {
	return Vector2(x * scalar, y * scalar);
}

// Dot product
float Vector2::dot(const Vector2& other) const {
	return x * other.x + y * other.y;
}

// Magnitude (length) of the vector
float Vector2::magnitude() const {
	return std::sqrt(x * x + y * y);
}

// Normalize the vector safely
Vector2 Vector2::normalize() const {
	float mag = magnitude();
	if (mag == 0) {
		throw std::runtime_error("Cannot normalize a zero-length vector");
	}
	return Vector2(x / mag, y / mag);
}

// Print the vector
void Vector2::print() const {
	std::cout << "(" << x << ", " << y << ")" << std::endl;
}
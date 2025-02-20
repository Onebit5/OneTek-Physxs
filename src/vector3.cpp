#include <cmath>
#include <iostream>
#include "../include/vector3.h"

// Constructor
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

// Vector operations
Vector3 Vector3::operator+(const Vector3& other) const {
	return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
	return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(float scalar) const {
	return Vector3(x * scalar, y * scalar, z * scalar);
}

// Dot product
float Vector3::dot(const Vector3& other) const {
	return x * other.x + y * other.y + z * other.z;
}

// Cross product
Vector3 Vector3::cross(const Vector3& other) const {
	return Vector3(
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x
	);
}

// Magnitude (length) of the vector
float Vector3::magnitude() const {
	return std::sqrt(x * x + y * y + z * z);
}

// Normalize the vector
Vector3 Vector3::normalize() const {
	float mag = magnitude();
	if (mag == 0) {
		throw std::runtime_error("Cannot normalize a zero-length vector");
	}
	return Vector3(x / mag, y / mag, z / mag);
}

// Print the vector
void Vector3::print() const {
	std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}
#include <cmath>
#include <iostream>
#include <algorithm>
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

// Operator overloads
Vector3& Vector3::operator+=(const Vector3& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3& Vector3::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vector3& Vector3::operator/=(float scalar) {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

Vector3 Vector3::operator/(float scalar) const {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Vector3(x / scalar, y / scalar, z / scalar);
}

// Interpolation
Vector3 Vector3::lerp(const Vector3& a, const Vector3& b, float t) {
    // Clamp t between 0 and 1
    float clampedT = (t < 0) ? 0 : ((t > 1) ? 1 : t);
    return a * (1 - clampedT) + b * clampedT;
}

Vector3 Vector3::slerp(const Vector3& a, const Vector3& b, float t) {
    // Clamp t between 0 and 1
    float clampedT = (t < 0) ? 0 : ((t > 1) ? 1 : t);
    
    // Compute the cosine of the angle between the vectors
    Vector3 normA = a.normalize();
    Vector3 normB = b.normalize();
    float dot = normA.dot(normB);
    
    // Clamp dot to valid range to avoid precision issues
    dot = std::clamp(dot, -1.0f, 1.0f);
    
    // Calculate the angle between vectors
    float theta = std::acos(dot) * clampedT;
    
    // Create the orthogonal vector to normA in the plane containing a and b
    Vector3 relative = (normB - normA * dot).normalize();
    
    // Final calculation
    return normA * std::cos(theta) + relative * std::sin(theta) * a.magnitude();
}

// Reflection and projection
Vector3 Vector3::reflect(const Vector3& normal) const {
    // Assumes normal is normalized
    Vector3 normalizedNormal = normal.normalize();
    return *this - normalizedNormal * (2 * this->dot(normalizedNormal));
}

Vector3 Vector3::project(const Vector3& onto) const {
    // Project this vector onto the 'onto' vector
    Vector3 normalizedOnto = onto.normalize();
    return normalizedOnto * this->dot(normalizedOnto);
}

// Component-wise operations
Vector3 Vector3::min(const Vector3& a, const Vector3& b) {
    return Vector3(
        std::min(a.x, b.x),
        std::min(a.y, b.y),
        std::min(a.z, b.z)
    );
}

Vector3 Vector3::max(const Vector3& a, const Vector3& b) {
    return Vector3(
        std::max(a.x, b.x),
        std::max(a.y, b.y),
        std::max(a.z, b.z)
    );
}

Vector3 Vector3::clamp(const Vector3& value, const Vector3& min, const Vector3& max) {
    return Vector3(
        std::clamp(value.x, min.x, max.x),
        std::clamp(value.y, min.y, max.y),
        std::clamp(value.z, min.z, max.z)
    );
}

// Print the vector
void Vector3::print() const {
	std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}
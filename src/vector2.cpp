#include <cmath>
#include <iostream>
#include <algorithm>
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

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2& Vector2::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2& Vector2::operator/=(float scalar) {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }
    x /= scalar;
    y /= scalar;
    return *this;
}

Vector2 Vector2::operator/(float scalar) const {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Vector2(x / scalar, y / scalar);
}

// Interpolation
Vector2 Vector2::lerp(const Vector2& a, const Vector2& b, float t) {
    // Clamp t between 0 and 1
    float clampedT = (t < 0) ? 0 : ((t > 1) ? 1 : t);
    return a * (1 - clampedT) + b * clampedT;
}

// Reflection and projection
Vector2 Vector2::reflect(const Vector2& normal) const {
    // Assumes normal is normalized
    Vector2 normalizedNormal = normal.normalize();
    return *this - normalizedNormal * (2 * this->dot(normalizedNormal));
}

Vector2 Vector2::project(const Vector2& onto) const {
    // Project this vector onto the 'onto' vector
    Vector2 normalizedOnto = onto.normalize();
    return normalizedOnto * this->dot(normalizedOnto);
}

// Component-wise operations
Vector2 Vector2::min(const Vector2& a, const Vector2& b) {
    return Vector2(
        std::min(a.x, b.x),
        std::min(a.y, b.y)
    );
}

Vector2 Vector2::max(const Vector2& a, const Vector2& b) {
    return Vector2(
        std::max(a.x, b.x),
        std::max(a.y, b.y)
    );
}

Vector2 Vector2::clamp(const Vector2& value, const Vector2& min, const Vector2& max) {
    return Vector2(
        std::clamp(value.x, min.x, max.x),
        std::clamp(value.y, min.y, max.y)
    );
}

// Print the vector
void Vector2::print() const {
	std::cout << "(" << x << ", " << y << ")" << std::endl;
}
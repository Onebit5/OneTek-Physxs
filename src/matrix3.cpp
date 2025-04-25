#include "../include/matrix3.h"
#include <iostream>
#include <stdexcept>

// Constructor (identity matrix by default)
Matrix3::Matrix3() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// Set the diagonal elements to 1 and others to 0
			data[i][j] = (i == j) ? 1.0f : 0.0f;
		}
	}
}

// Matrix multiplication
Matrix3 Matrix3::operator*(const Matrix3& other) const {
	Matrix3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// Initialize the result matrix element to 0
			result.data[i][j] = 0.0f;
			for (int k = 0; k < 3; k++) {
				// Accumulate the product of the corresponding elements
				result.data[i][j] += data[i][k] * other.data[k][j];
			}
		}
	}
	return result; // Return the resulting matrix
}

Vector2 Matrix3::operator*(const Vector2& vec) const {
	float x = data[0][0] * vec.x + data[0][1] * vec.y + data[0][2];
	float y = data[1][0] * vec.x + data[1][1] * vec.y + data[1][2];
	return Vector2(x, y);
}

// Determinant
float Matrix3::determinant() const {
	// Calculate the determinant using the formula for a 3x3 matrix
	return data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1])
		- data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0])
		+ data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
}

// Inverse
Matrix3 Matrix3::inverse() const {
	float det = determinant();
	if (det == 0) {
		// Throw an error if the matrix is not invertible
		throw std::runtime_error("Matrix is not invertible!");
	}

	Matrix3 result;
	// Calculate the inverse matrix elements using the determinant
	result.data[0][0] = (data[1][1] * data[2][2] - data[1][2] * data[2][1]) / det;
	result.data[0][1] = -(data[0][1] * data[2][2] - data[0][2] * data[2][1]) / det;
	result.data[0][2] = (data[0][1] * data[1][2] - data[0][2] * data[1][1]) / det;
	result.data[1][0] = -(data[1][0] * data[2][2] - data[1][2] * data[2][0]) / det;
	result.data[1][1] = (data[0][0] * data[2][2] - data[0][2] * data[2][0]) / det;
	result.data[1][2] = -(data[0][0] * data[1][2] - data[0][2] * data[1][0]) / det;
	result.data[2][0] = (data[1][0] * data[2][1] - data[1][1] * data[2][0]) / det;
	result.data[2][1] = -(data[0][0] * data[2][1] - data[0][1] * data[2][0]) / det;
	result.data[2][2] = (data[0][0] * data[1][1] - data[0][1] * data[1][0]) / det;

	return result; // Return the inverse matrix
}

// Additional operator overloads
Matrix3& Matrix3::operator*=(const Matrix3& other) {
    *this = *this * other;
    return *this;
}

Matrix3 Matrix3::operator+(const Matrix3& other) const {
    Matrix3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix3& Matrix3::operator+=(const Matrix3& other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

Matrix3 Matrix3::operator-(const Matrix3& other) const {
    Matrix3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix3& Matrix3::operator-=(const Matrix3& other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] -= other.data[i][j];
        }
    }
    return *this;
}

Matrix3 Matrix3::operator*(float scalar) const {
    Matrix3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

Matrix3& Matrix3::operator*=(float scalar) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] *= scalar;
        }
    }
    return *this;
}

// Interpolation
Matrix3 Matrix3::lerp(const Matrix3& a, const Matrix3& b, float t) {
    // Clamp t between 0 and 1
    float clampedT = (t < 0) ? 0 : ((t > 1) ? 1 : t);
    
    Matrix3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.data[i][j] = a.data[i][j] * (1 - clampedT) + b.data[i][j] * clampedT;
        }
    }
    return result;
}

// Print the matrix
void Matrix3::print() const {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// Output each element of the matrix
			std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
#include "../include/matrix4.h"

// Constructor (identity matrix by default)
Matrix4::Matrix4() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			data[i][j] = (i == j) ? 1.0f : 0.0f;
		}
	}
}

// Matrix multiplication
Matrix4 Matrix4::operator*(const Matrix4& other) const {
	Matrix4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.data[i][j] = 0.0f;
			for (int k = 0; k < 4; k++) {
				result.data[i][j] += data[i][k] * other.data[k][j];
			}
		}
	}
	return result;
}

// Determinant
float Matrix4::determinant() const {
	// Implement the determinant calculation here
	return 1;
}

// Inverse
Matrix4 Matrix4::inverse() const {
	// Implement the inverse calculation here
	return Matrix4();
}

// Print the matrix
void Matrix4::print() const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
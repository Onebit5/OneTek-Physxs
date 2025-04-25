#include "../include/matrix4.h"

// Constructor (identity matrix by default)
Matrix4::Matrix4() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			data[i][j] = (i == j) ? 1.0f : 0.0f; // Initialize the matrix to the identity matrix
		}
	}
}

// Matrix multiplication
Matrix4 Matrix4::operator*(const Matrix4& other) const {
	Matrix4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.data[i][j] = 0.0f; // Initialize the result matrix element to zero
			for (int k = 0; k < 4; k++) {
				result.data[i][j] += data[i][k] * other.data[k][j]; // Perform multiplication and accumulate
			}
		}
	}
	return result; // Return the resulting matrix
}

Vector3 Matrix4::operator*(const Vector3& vec) const {
	float x = data[0][0] * vec.x + data[0][1] * vec.y + data[0][2] * vec.z + data[0][3];
	float y = data[1][0] * vec.x + data[1][1] * vec.y + data[1][2] * vec.z + data[1][3];
	float z = data[2][0] * vec.x + data[2][1] * vec.y + data[2][2] * vec.z + data[2][3];
	return Vector3(x, y, z);
}

// Helper function to compute the determinant of a 3x3 submatrix
float Matrix4::determinant3x3(
	float a, float b, float c,
	float d, float e, float f,
	float g, float h, float i
) {
	return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g); // Calculate the determinant of a 3x3 matrix
}

// Determinant
float Matrix4::determinant() const {
	float det = 0.0f; // Initialize determinant to zero
	for (int col = 0; col < 4; col++) {
		float submatrix[3][3];
		int sub_i = 0;
		for (int i = 1; i < 4; i++) {
			int sub_j = 0;
			for (int j = 0; j < 4; j++) {
				if (j == col) continue; // Skip the current column
				submatrix[sub_i][sub_j] = data[i][j]; // Fill the submatrix
				sub_j++;
			}
			sub_i++;
		}
		float sub_det = determinant3x3(
			submatrix[0][0], submatrix[0][1], submatrix[0][2],
			submatrix[1][0], submatrix[1][1], submatrix[1][2],
			submatrix[2][0], submatrix[2][1], submatrix[2][2]
		);
		det += ((col % 2 == 0) ? 1 : -1) * data[0][col] * sub_det; // Accumulate the determinant
	}
	return det; // Return the computed determinant
}

// Inverse
Matrix4 Matrix4::inverse() const {
	float det = determinant(); // Calculate the determinant
	if (det == 0.0f) {
		throw std::runtime_error("Matrix is not invertible"); // Throw an error if the matrix is not invertible
	}

	Matrix4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float submatrix[3][3];
			int sub_i = 0;
			for (int x = 0; x < 4; x++) {
				if (x == i) continue; // Skip the current row
				int sub_j = 0;
				for (int y = 0; y < 4; y++) {
					if (y == j) continue; // Skip the current column
					submatrix[sub_i][sub_j] = data[x][y]; // Fill the submatrix
					sub_j++;
				}
				sub_i++;
			}
			float sub_det = determinant3x3(
				submatrix[0][0], submatrix[0][1], submatrix[0][2],
				submatrix[1][0], submatrix[1][1], submatrix[1][2],
				submatrix[2][0], submatrix[2][1], submatrix[2][2]
			);
			result.data[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * sub_det / det; // Calculate the inverse element
		}
	}
	return result; // Return the inverted matrix
}

// Additional operator overloads
Matrix4& Matrix4::operator*=(const Matrix4& other) {
    *this = *this * other;
    return *this;
}

Matrix4 Matrix4::operator+(const Matrix4& other) const {
    Matrix4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix4& Matrix4::operator+=(const Matrix4& other) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

Matrix4 Matrix4::operator-(const Matrix4& other) const {
    Matrix4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix4& Matrix4::operator-=(const Matrix4& other) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            data[i][j] -= other.data[i][j];
        }
    }
    return *this;
}

Matrix4 Matrix4::operator*(float scalar) const {
    Matrix4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

Matrix4& Matrix4::operator*=(float scalar) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            data[i][j] *= scalar;
        }
    }
    return *this;
}

// Interpolation
Matrix4 Matrix4::lerp(const Matrix4& a, const Matrix4& b, float t) {
    // Clamp t between 0 and 1
    float clampedT = (t < 0) ? 0 : ((t > 1) ? 1 : t);
    
    Matrix4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.data[i][j] = a.data[i][j] * (1 - clampedT) + b.data[i][j] * clampedT;
        }
    }
    return result;
}

// Print the matrix
void Matrix4::print() const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << data[i][j] << " "; // Output each element of the matrix
		}
		std::cout << std::endl;
	}
}
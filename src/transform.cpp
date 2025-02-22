#include <cmath>
#include "Transform.h"
#define M_PI 3.14159265358979323846

// Constructor
Transform::Transform() : position(0.0f, 0.0f, 0.0f), rotation(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f) {}

// Transformation matrix for 3D
Matrix4 Transform::getMatrix3D() const {
    return translation3D(position) * rotation3D(rotation.x, rotation.y, rotation.z) * scaling3D(scale);
}

// Transformation matrix for 2D
Matrix3 Transform::getMatrix2D() const {
    return translation2D(position.x, position.y) * rotation2D(rotation.z) * scaling2D(scale.x, scale.y);
}

// Static transformation functions for 2D
Matrix3 Transform::translation2D(float tx, float ty) {
    Matrix3 mat;
    mat.data[0][2] = tx;
    mat.data[1][2] = ty;
    return mat;
}

Matrix3 Transform::rotation2D(float angle) {
    float rad = angle * static_cast<float>(M_PI) / 180.0f;
    float cosA = cosf(rad);
    float sinA = sinf(rad);

    Matrix3 mat;
    mat.data[0][0] = cosA;
    mat.data[0][1] = -sinA;
    mat.data[1][0] = sinA;
    mat.data[1][1] = cosA;
    return mat;
}

Matrix3 Transform::scaling2D(float sx, float sy) {
    Matrix3 mat;
    mat.data[0][0] = sx;
    mat.data[1][1] = sy;
    return mat;
}

// Static transformation functions for 3D
Matrix4 Transform::translation3D(const Vector3& translation) {
    Matrix4 mat;
    mat.data[0][3] = translation.x;
    mat.data[1][3] = translation.y;
    mat.data[2][3] = translation.z;
    return mat;
}

Matrix4 Transform::rotation3D(float angleX, float angleY, float angleZ) {
    float radX = angleX * static_cast<float>(M_PI) / 180.0f;
    float radY = angleY * static_cast<float>(M_PI) / 180.0f;
    float radZ = angleZ * static_cast<float>(M_PI) / 180.0f;

    float cosX = cosf(radX);
    float sinX = sinf(radX);
    float cosY = cosf(radY);
    float sinY = sinf(radY);
    float cosZ = cosf(radZ);
    float sinZ = sinf(radZ);

    Matrix4 rotX;
    rotX.data[1][1] = cosX;
    rotX.data[1][2] = -sinX;
    rotX.data[2][1] = sinX;
    rotX.data[2][2] = cosX;

    Matrix4 rotY;
    rotY.data[0][0] = cosY;
    rotY.data[0][2] = sinY;
    rotY.data[2][0] = -sinY;
    rotY.data[2][2] = cosY;

    Matrix4 rotZ;
    rotZ.data[0][0] = cosZ;
    rotZ.data[0][1] = -sinZ;
    rotZ.data[1][0] = sinZ;
    rotZ.data[1][1] = cosZ;

    return rotZ * rotY * rotX;
}

Matrix4 Transform::scaling3D(const Vector3& scale) {
    Matrix4 mat;
    mat.data[0][0] = scale.x;
    mat.data[1][1] = scale.y;
    mat.data[2][2] = scale.z;
    return mat;
}

// Print the transform
void Transform::print() const {
    std::cout << "Position: ";
    position.print();
    std::cout << "Rotation: ";
    rotation.print();
    std::cout << "Scale: ";
    scale.print();
}
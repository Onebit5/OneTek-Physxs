#include "quaternion.h"
#include <cmath>

// Constructor
Quaternion::Quaternion() : w(1.0f), x(0.0f), y(0.0f), z(0.0f) {}

Quaternion::Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

// Quaternion multiplication
Quaternion Quaternion::operator*(const Quaternion& other) const {
    return Quaternion(
        w * other.w - x * other.x - y * other.y - z * other.z,
        w * other.x + x * other.w + y * other.z - z * other.y,
        w * other.y - x * other.z + y * other.w + z * other.x,
        w * other.z + x * other.y - y * other.x + z * other.w
    );
}

// Quaternion conjugate
Quaternion Quaternion::conjugate() const {
    return Quaternion(w, -x, -y, -z);
}

// Normalize the quaternion
Quaternion Quaternion::normalize() const {
    float mag = std::sqrt(w * w + x * x + y * y + z * z);
    return Quaternion(w / mag, x / mag, y / mag, z / mag);
}

// Convert quaternion to rotation matrix
Matrix4 Quaternion::toMatrix() const {
    Matrix4 mat;

    float xx = x * x;
    float xy = x * y;
    float xz = x * z;
    float xw = x * w;

    float yy = y * y;
    float yz = y * z;
    float yw = y * w;

    float zz = z * z;
    float zw = z * w;

    mat.data[0][0] = 1 - 2 * (yy + zz);
    mat.data[0][1] = 2 * (xy - zw);
    mat.data[0][2] = 2 * (xz + yw);
    mat.data[0][3] = 0.0f;

    mat.data[1][0] = 2 * (xy + zw);
    mat.data[1][1] = 1 - 2 * (xx + zz);
    mat.data[1][2] = 2 * (yz - xw);
    mat.data[1][3] = 0.0f;

    mat.data[2][0] = 2 * (xz - yw);
    mat.data[2][1] = 2 * (yz + xw);
    mat.data[2][2] = 1 - 2 * (xx + yy);
    mat.data[2][3] = 0.0f;

    mat.data[3][0] = 0.0f;
    mat.data[3][1] = 0.0f;
    mat.data[3][2] = 0.0f;
    mat.data[3][3] = 1.0f;

    return mat;
}

// Conver quaternion to Euler angles
Vector3 Quaternion::toEulerAngles() const {
    Vector3 euler;

    // Roll (x-axis rotation)
    float sinr_cosp = 2 * (w * x + y * z);
    float cosr_cosp = 1 - 2 * (x * x + y * y);
    euler.z = std::atan2(sinr_cosp, cosr_cosp);

    // Pitch (y-axis rotation)
    float sinp = 2 * (w * y - z * x);
    if (std::abs(sinp) >= 1)
        euler.x = std::copysign(M_PI / 2, sinp); // Use 90 degrees if out of range
    else
        euler.x = std::asin(sinp);

    // Yaw (z-axis rotation)
    float siny_cosp = 2 * (w * z + x * y);
    float cosy_cosp = 1 - 2 * (y * y + z * z);
    euler.y = std::atan2(siny_cosp, cosy_cosp);

    return euler;
}

// Create a quaternion from axis-angle representation
Quaternion Quaternion::fromAxisAngle(const Vector3& axis, float angle) {
    float halfAngle = angle * 0.5f;
    float sinHalfAngle = std::sin(halfAngle);
    return Quaternion(
        std::cos(halfAngle),
        axis.x * sinHalfAngle,
        axis.y * sinHalfAngle,
        axis.z * sinHalfAngle
    ).normalize();
}

// Create a quaternion from Euler angles (pitch, yaw, roll)
Quaternion Quaternion::fromEulerAngles(float pitch, float yaw, float roll) {
    float cy = std::cos(yaw * 0.5f);
    float sy = std::sin(yaw * 0.5f);
    float cp = std::cos(pitch * 0.5f);
    float sp = std::sin(pitch * 0.5f);
    float cr = std::cos(roll * 0.5f);
    float sr = std::sin(roll * 0.5f);

    return Quaternion(
        cr * cp * cy + sr * sp * sy,
        sr * cp * cy - cr * sp * sy,
        cr * sp * cy + sr * cp * sy,
        cr * cp * sy - sr * sp * cy
    ).normalize();
}

// Print the quaternion
void Quaternion::print() const {
    std::cout << "(" << w << ", " << x << ", " << y << ", " << z << ")" << std::endl;
}
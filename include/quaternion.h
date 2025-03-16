#ifndef QUATERNION_H
#define QUATERNION_H

#define M_PI 3.14159265358979323846

#include "vector3.h"
#include "matrix4.h"

class Quaternion {
public:
    float w, x, y, z; // Components of the quaternion

    // Constructors
    Quaternion();
    Quaternion(float w, float x, float y, float z);

    // Quaternion operations
    Quaternion operator*(const Quaternion& other) const;
    Quaternion conjugate() const;
    Quaternion normalize() const;
    Matrix4 toMatrix() const;
    Vector3 toEulerAngles() const;

    // Static functions for creating quaternions
    static Quaternion fromAxisAngle(const Vector3& axis, float angle);
    static Quaternion fromEulerAngles(float pitch, float yaw, float roll);

    // Utility
    void print() const;
};

#endif
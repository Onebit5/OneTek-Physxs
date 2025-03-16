#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector2.h"
#include "vector3.h"
#include "matrix3.h"
#include "matrix4.h"
#include "quaternion.h"

class Transform {
public:
    Vector3 position; // Position of the object in 3D space
    Quaternion rotation; // Rotation of the object represented as a quaternion
    Vector3 scale;    // Scale factors for the object in 3D space

    // Constructor
    Transform();

    // Transformation matrix for 2D
    Matrix3 getMatrix2D() const;

    // Transformation matrix for 3D
    Matrix4 getMatrix3D() const;

    // Static transformation functions for 2D
    static Matrix3 translation2D(float tx, float ty);
    static Matrix3 rotation2D(float angle);
    static Matrix3 scaling2D(float sx, float sy);

    // Static transformation functions for 3D
    static Matrix4 translation3D(const Vector3& translation);
    static Matrix4 rotation3D(const Quaternion& rotation);
    static Matrix4 scaling3D(const Vector3& scale);

    // Utility
    void print() const;
};

#endif
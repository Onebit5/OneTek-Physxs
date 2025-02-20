#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector3.h"
#include "matrix4.h"

class Transform {
public:
	Vector3 position; // Position of the object in 3D space
	Vector3 rotation; // Rotation of the object represented as Euler angles in degrees
	Vector3 scale;    // Scale factors for the object in 3D space

	// Constructor
	Transform();

	// Transformation matrix
	Matrix4 getMatrix() const;

	// Utility
	void print() const;
};

#endif
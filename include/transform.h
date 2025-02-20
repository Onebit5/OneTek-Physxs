#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector3.h"
#include "matrix4.h"

class Transform {
public:
	Vector3 position;
	Vector3 rotation; // Euler angles in degrees
	Vector3 scale;

	// Constructor
	Transform();

	// Transformation matrix
	Matrix4 getMatrix() const;

	// Utility
	void print() const;
};

#endif
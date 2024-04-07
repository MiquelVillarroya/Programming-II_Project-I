/* ----------------------------------------------------------------------- */
/*                          TYPE YOUR NAME HERE                            */
/* ----------------------------------------------------------------------- */
#ifndef EX3_H
#define EX3_H

#include <iostream>

// 3D vector class
class vec3 {
public:
	float x, y, z;
	vec3() : x(0), y(0), z(0) { }
	vec3(float v) : x(v), y(v), z(v) { }
	vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) { }
};

// Operator* must compute the dot product
// TODO

float operator*(const vec3 &v1, const vec3 &v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

#endif

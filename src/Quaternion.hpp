#pragma once

#include "humanGL.h"
#include "Matrix.hpp"

class Quaternion {
	public:
		Quaternion();
		Quaternion(float x, float y, float z, float w);
		Quaternion(float angle, Vector3 axis);
		Quaternion(Quaternion const &src);
		~Quaternion();

		Quaternion&	operator=(Quaternion const &src);

		Quaternion	normalize() const;

		Matrix4		toMatrix() const;
		Quaternion	interpolate(Quaternion const &q, float t) const;

		static Quaternion	interpolate(Quaternion const &q1, Quaternion const &q2, float blend);

	private:
		float		w;
		float		x;
		float		y;
		float		z;

};
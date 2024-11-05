#pragma once

#include "Vector.hpp"
#include <iostream>

class Vector3;
class Vector4;

class Matrix4 {
	public:
		Matrix4(void);
		Matrix4(float f, bool identity = true);
		Matrix4(float f[16]);
		Matrix4(Matrix4 const& copy);
		~Matrix4();

		Matrix4& operator=(Matrix4 const& copy);
		Matrix4& operator=(float tab[16]);
		float operator[](size_t n) const;

		Matrix4 operator*(float const& n) const;
		Matrix4 operator+(Matrix4 const& m) const;
		Matrix4 operator-(Matrix4 const& m) const;
		Matrix4 operator*(Matrix4 const& m) const;
		Matrix4 operator/(Matrix4 const& m) const;

		Matrix4	inverse() const;
		Matrix4	transpose() const;

		static Matrix4	perspective(float fov, float aspect, float near, float far);
		static Matrix4	orthographic(float left, float right, float bottom, float top, float near, float far);

		static Matrix4	translation(Vector3 const& v);
		static Matrix4	rotation(float angle, Vector3 const& v);
		static Matrix4	scaling(Vector3 const& v);
		static Matrix4	model(Matrix4 const& translation, Matrix4 const& rotation, Matrix4 const& scale);

		void	getMatrix(float fill[16]) const;

		void	print(void) const;

	private:
		float	matrix[16];
};
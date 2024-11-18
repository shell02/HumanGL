#pragma once

#include <cmath>
#include "Matrix.hpp"

class Matrix4;

class Vector2 {
	public:
		Vector2(float x = 0, float y = 0);
		Vector2(Vector2 const &copy);
		Vector2(float tab[2]);
		~Vector2();

		Vector2	&operator=(Vector2 const &copy);
		Vector2	&operator=(float tab[2]);
		float	operator[](size_t n) const;

		double	getLength(void) const;
		Vector2	unit(void) const;

		float	getX(void) const;
		float	getY(void) const;

	private:
		float	x;
		float	y;
};

class Vector3 {
	public:
		Vector3(float x = 0, float y = 0, float z = 0);
		Vector3(Vector3 const &copy);
		Vector3(float tab[3]);
		Vector3(Vector2 const &v, float z = 0);
		~Vector3();

		Vector3	&operator=(Vector3 const &copy);
		Vector3	&operator=(float tab[3]);
		float	operator[](size_t n) const;

		Vector3	operator+(Vector3 const &v) const;
		Vector3	operator-(Vector3 const &v) const;
		double	operator*(Vector3 const &v) const;
		Vector3	operator^(Vector3 const &v) const;

		Vector3	operator+(float const &n) const;
		Vector3	operator-(float const &n) const;
		Vector3	operator*(float const &n) const;
		Vector3	operator/(float const &n) const;

		double	getLength(void) const;
		Vector3	unit(void) const;

		float	getX(void) const;
		float	getY(void) const;
		float	getZ(void) const;

		static Vector3	interpolate(Vector3 const &v1, Vector3 const &v2, float time);

	private:
		float	x;
		float	y;
		float	z;
};

class Vector4 {
	public:
		Vector4(float x = 0, float y = 0, float z = 0, float w = 0);
		Vector4(Vector4 const& copy);
		Vector4(float tab[4]);
		Vector4(Vector3 const& v, float w = 1);
		~Vector4();

		Vector4&	operator=(Vector4 const &copy);
		Vector4&	operator=(float tab[4]);
		Vector4		operator*(Matrix4 const& m) const;
		float		operator[](size_t n) const;

		double	getLength(void) const;
		Vector4	unit(void) const;

		float	getX(void) const;
		float	getY(void) const;
		float	getZ(void) const;
		float	getW(void) const;

	private:
		float	x;
		float	y;
		float	z;
		float	w;
};
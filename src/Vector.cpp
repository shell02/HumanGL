#include "Vector.hpp"

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2::Vector2(Vector2 const &copy) : x(copy.x), y(copy.y) {}

Vector2::Vector2(float tab[2]) : x(tab[0]), y(tab[1]) {}

Vector2::~Vector2() {}

Vector2	&Vector2::operator=(Vector2 const &copy) {
	x = copy.x;
	y = copy.y;
	return *this;
}

Vector2	&Vector2::operator=(float tab[2]) {
	x = tab[0];
	y = tab[1];
	return *this;
}

float	Vector2::operator[](size_t n) const {
	if (n == 0)
		return x;
	else if (n == 1)
		return y;
	return 0;
}

double	Vector2::getLength(void) const {
	return sqrt(x * x + y * y);
}

Vector2	Vector2::unit(void) const {
	double length = getLength();
	return Vector2(x / length, y / length);
}

float	Vector2::getX(void) const {
	return x;
}

float	Vector2::getY(void) const {
	return y;
}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::Vector3(Vector3 const &copy) : x(copy.x), y(copy.y), z(copy.z) {}

Vector3::Vector3(float tab[3]) : x(tab[0]), y(tab[1]), z(tab[2]) {}

Vector3::Vector3(Vector2 const &v, float z) : x(v.getX()), y(v.getY()), z(z) {}

Vector3::~Vector3() {}

Vector3	&Vector3::operator=(Vector3 const &copy) {
	x = copy.x;
	y = copy.y;
	z = copy.z;
	return *this;
}

Vector3	&Vector3::operator=(float tab[3]) {
	x = tab[0];
	y = tab[1];
	z = tab[2];
	return *this;
}

float	Vector3::operator[](size_t n) const {
	if (n == 0)
		return x;
	else if (n == 1)
		return y;
	else if (n == 2)
		return z;
	return 0;
}

Vector3	Vector3::operator+(Vector3 const &v) const {
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3	Vector3::operator-(Vector3 const &v) const {
	return Vector3(x - v.x, y - v.y, z - v.z);
}

double	Vector3::operator*(Vector3 const &v) const {
	return x * v.x + y * v.y + z * v.z;
}

Vector3	Vector3::operator^(Vector3 const &v) const {
	return Vector3(
		(y * v.z) - (z * v.y),
		(z * v.x) - (x * v.z),
		(x * v.y) - (y * v.x)
	);
}

Vector3	Vector3::operator+(float const &n) const {
	return Vector3(x + n, y + n, z + n);
}

Vector3	Vector3::operator-(float const &n) const {
	return Vector3(x - n, y - n, z - n);
}

Vector3	Vector3::operator*(float const &n) const {
	return Vector3(x * n, y * n, z * n);
}

Vector3	Vector3::operator/(float const &n) const {
	if (n == 0) {
        throw std::invalid_argument("Division by zero");
    }
	return Vector3(x / n, y / n, z / n);
}

double	Vector3::getLength(void) const {
	return sqrt(x * x + y * y + z * z);
}

Vector3	Vector3::unit(void) const {
	if (x == 0 && y == 0 && z == 0) {
		return Vector3(0, 0, 0);
	}
	double length = getLength();
	if (length == 0) {
        throw std::invalid_argument("Cannot normalize a zero-length vector");
    }
	return Vector3(x / length, y / length, z / length);
}

float	Vector3::getX(void) const {
	return x;
}

float	Vector3::getY(void) const {
	return y;
}

float	Vector3::getZ(void) const {
	return z;
}

Vector3	Vector3::interpolate(Vector3 const &v1, Vector3 const &v2, float time) {
	float x = v1.getX() + (v2.getX() - v1.getX()) * time;
	float y = v1.getY() + (v2.getY() - v1.getY()) * time;
	float z = v1.getZ() + (v2.getZ() - v1.getZ()) * time;

	return Vector3(x, y, z);
}

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Vector4::Vector4(Vector4 const &copy) : x(copy.x), y(copy.y), z(copy.z), w(copy.w) {}

Vector4::Vector4(float tab[4]) : x(tab[0]), y(tab[1]), z(tab[2]), w(tab[3]) {}

Vector4::Vector4(Vector3 const &v, float w) : x(v.getX()), y(v.getY()), z(v.getZ()), w(w) {}

Vector4::~Vector4() {}

Vector4	&Vector4::operator=(Vector4 const &copy) {
	x = copy.x;
	y = copy.y;
	z = copy.z;
	w = copy.w;
	return *this;
}

Vector4	&Vector4::operator=(float tab[4]) {
	x = tab[0];
	y = tab[1];
	z = tab[2];
	w = tab[3];
	return *this;
}

Vector4	Vector4::operator*(Matrix4 const& m) const {
	Vector4 tmp(*this);
	float result;

	for (int i = 0; i < 4; i++) {
		result = 0;
		for (int j = 0; j < 4; j++) {
			float n = (j == 0 ? x : j == 1 ? y : j == 2 ? z : w);
			result += m[i * 4 + j] * n;
		}
		switch (i)
		{
			case 0:
				tmp.x = result;
				break;
			case 1:
				tmp.y = result;
				break;
			case 2:
				tmp.z = result;
				break;
			default:
				tmp.w = result;
				break;
		}
	}
	return tmp;
}

float	Vector4::operator[](size_t n) const {
	if (n == 0)
		return x;
	else if (n == 1)
		return y;
	else if (n == 2)
		return z;
	else if (n == 3)
		return w;
	return 0;
}

double	Vector4::getLength(void) const {
	return sqrt(x * x + y * y + z * z + w * w);
}

Vector4	Vector4::unit(void) const {
	double length = getLength();
	return Vector4(x / length, y / length, z / length, w / length);
}

float	Vector4::getX(void) const {
	return x;
}

float	Vector4::getY(void) const {
	return y;
}

float	Vector4::getZ(void) const {
	return z;
}

float	Vector4::getW(void) const {
	return w;
}

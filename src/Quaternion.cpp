#include "Quaternion.hpp"

Quaternion::Quaternion() : w(1.0f), x(0.0f), y(0.0f), z(0.0f) {}

Quaternion::Quaternion(float x, float y, float z, float w) : w(w), x(x), y(y), z(z) {}

Quaternion::Quaternion(float angle, Vector3 axis) {
    Vector3 normalizedAxis = axis.unit();
    
	angle = angle * (M_PI / 180);
    float halfAngle = angle / 2.0f;
    float sinHalfAngle = sin(halfAngle);

    w = cos(halfAngle);
    x = sinHalfAngle * normalizedAxis[0];
    y = sinHalfAngle * normalizedAxis[1];
    z = sinHalfAngle * normalizedAxis[2];
}


Quaternion::Quaternion(Quaternion const &src) {
	*this = src;
}

Quaternion::~Quaternion() {}

Quaternion&	Quaternion::operator=(Quaternion const &src) {
	if (this != &src) {
		w = src.w;
		x = src.x;
		y = src.y;
		z = src.z;
	}
	return *this;
}

Quaternion	Quaternion::normalize() const {
	float mag = sqrt(w * w + x * x + y * y + z * z);
	return Quaternion(x / mag, y / mag, z / mag, w / mag);
}

Matrix4	Quaternion::toMatrix() const {

	Quaternion q = normalize();

	float xy = q.x * q.y;
	float xz = q.x * q.z;
	float xw = q.x * q.w;
	float yz = q.y * q.z;
	float yw = q.y * q.w;
	float zw = q.z * q.w;
	float xSquared = q.x * q.x;
	float ySquared = q.y * q.y;
	float zSquared = q.z * q.z;

	float matrix[16] = {
		1 - 2 * (ySquared + zSquared), 2 * (xy - zw), 2 * (xz + yw), 0,
		2 * (xy + zw), 1 - 2 * (xSquared + zSquared), 2 * (yz - xw), 0,
		2 * (xz - yw), 2 * (yz + xw), 1 - 2 * (xSquared + ySquared), 0,
		0, 0, 0, 1
	};

	return Matrix4(matrix);
}

Quaternion	Quaternion::interpolate(Quaternion const &q, float blend) const {
	Quaternion q1 = normalize();
	Quaternion q2 = q.normalize();
	float dot = q1.w * q2.w + q1.x * q2.x + q1.y * q2.y + q1.z * q2.z;
	float blendI = 1.0f - blend;
	Quaternion res = Quaternion(
		blendI * q1.x + blend * q2.x,
		blendI * q1.y + blend * q2.y,
		blendI * q1.z + blend * q2.z,
		blendI * q1.w + blend * q2.w
	);
	if (dot < 0) {
		res.w = -res.w;
		res.x = -res.x;
		res.y = -res.y;
		res.z = -res.z;
	}
	return res.normalize();
}

Quaternion	Quaternion::interpolate(Quaternion const &q1, Quaternion const &q2, float blend) {
	return q1.interpolate(q2, blend);
}

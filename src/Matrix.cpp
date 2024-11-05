#include "Matrix.hpp"

Matrix4::Matrix4(void) {
	for (size_t i = 0; i < 16; i++)
		matrix[i] = 0;
}

Matrix4::Matrix4(float f, bool identity) {
	if (identity) {
		for (size_t i = 0; i < 16; i++)
			matrix[i] = 0;
		matrix[0] = matrix[5] = matrix[10] = matrix[15] = f;
	} else {
		for (size_t i = 0; i < 16; i++)
			matrix[i] = f;
	}
}

Matrix4::Matrix4(float f[16]) {
	for (size_t i = 0; i < 16; i++)
		matrix[i] = f[i];
}

Matrix4::Matrix4(Matrix4 const& copy) {
	for (size_t i = 0; i < 16; i++)
		matrix[i] = copy[i];
}

Matrix4::~Matrix4() {}

Matrix4& Matrix4::operator=(Matrix4 const& copy) {
	for (size_t i = 0; i < 16; i++)
		matrix[i] = copy[i];
	return *this;
}

Matrix4& Matrix4::operator=(float tab[16]) {
	for (size_t i = 0; i < 16; i++)
		matrix[i] = tab[i];
	return *this;
}

float Matrix4::operator[](size_t n) const {
	return matrix[n];
}

Matrix4 Matrix4::operator*(float const& n) const {
	Matrix4 m;
	for (size_t i = 0; i < 16; i++)
		m.matrix[i] = matrix[i] * n;
	return m;
}

Matrix4 Matrix4::operator+(Matrix4 const& m) const {
	Matrix4 res;
	for (size_t i = 0; i < 16; i++)
		res.matrix[i] = matrix[i] + m[i];
	return res;
}

Matrix4 Matrix4::operator-(Matrix4 const& m) const {
	Matrix4 res;
	for (size_t i = 0; i < 16; i++)
		res.matrix[i] = matrix[i] - m[i];
	return res;
}

Matrix4 Matrix4::operator*(Matrix4 const& m) const {
	Matrix4	newM;
	Vector4 v;
	Vector4	result;
	float	tmp[4];

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			tmp[i] = m[i * 4 + j];
		}
		v = tmp;
		result = v * (*this);
		for (int i = 0; i < 4; i++) {
			newM.matrix[i * 4 + j] = result[i];
		}
	}
	return newM;
}

Matrix4 Matrix4::operator/(Matrix4 const& m) const {
	Matrix4 invM = m.inverse();
	return *this * invM;
}

Matrix4	Matrix4::inverse() const {
	Matrix4	invM(1.0f);
	float	det = 0;
	float	tmpM[16];

	for (int i = 0; i < 16; i++)
		tmpM[i] = matrix[i];
	for (int i = 0; i < 4; i++) {
		det = tmpM[i * 4 + i];
		for (int j = 0; j < 4; j++) {
			tmpM[i * 4 + j] /= det;
			invM.matrix[i * 4 + j] /= det;
		}
		for (int j = 0; j < 4; j++) {
			if (i != j) {
				det = tmpM[j * 4 + i];
				for (int k = 0; k < 4; k++) {
					tmpM[j * 4 + k] -= tmpM[i * 4 + k] * det;
					invM.matrix[j * 4 + k] -= invM.matrix[i * 4 + k] * det;
				}
			}
		}
	}
	return invM;
}

Matrix4 Matrix4::transpose() const
{
	Matrix4 transposeM;
	int ij;
	int ji;

	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			ij = i * 4 + j;
			ji = j * 4 + i;
			transposeM.matrix[ij] = matrix[ji];
			transposeM.matrix[ji] = matrix[ij];
		}
	}
	return transposeM;
}

Matrix4 Matrix4::perspective(float fov, float aspect, float near, float far) {
	Matrix4 perspectiveM;
	fov = fov * M_PI / 180.0f;

	const float e = 1.0f / tan(fov / 2.0);
	const float range = near - far;

	perspectiveM.matrix[0] = e / aspect;
	perspectiveM.matrix[5] = e;
	perspectiveM.matrix[10] = (near + far) / range;
	perspectiveM.matrix[11] = (2.0f * near * far) / range;
	perspectiveM.matrix[14] = -1.0f;

	return perspectiveM;
};

Matrix4	Matrix4::orthographic(float left, float right, float bottom, float top, float near, float far)
{
	float matrix[16] = {
		2.0f / (right - left), 0, 0, 0,
		0, 2.0f / (top - bottom), 0, 0,
		0, 0, -2.0f / (far - near), 0,
		-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1.0f
	};

	return Matrix4(matrix);
}

Matrix4	Matrix4::translation(Vector3 const& v)
{
	Matrix4 translationM(1.0f);
	translationM.matrix[3] = v[0];
	translationM.matrix[7] = v[1];
	translationM.matrix[11] = v[2];
	return translationM;
}

Matrix4	Matrix4::rotation(float angle, Vector3 const& v)
{
	Matrix4 rotateM(1.0f);
	Vector3	tmp = v.unit();

	angle = angle * (M_PI / 180);
	float cosA = cosf(angle);
	float sinA = sinf(angle);

	rotateM.matrix[0] = pow(tmp[0], 2) * (1 - cosA) + cosA;
	rotateM.matrix[1] = tmp[0] * tmp[1] * (1 - cosA) - tmp[2] * sinA;
	rotateM.matrix[2] = tmp[0] * tmp[2] * (1 - cosA) + tmp[1] * sinA;
	rotateM.matrix[4] = tmp[1] * tmp[0] * (1 - cosA) + tmp[2] * sinA;
	rotateM.matrix[5] = pow(tmp[1], 2) * (1 - cosA) + cosA;
	rotateM.matrix[6] = tmp[1] * tmp[2] * (1 - cosA) - tmp[0] * sinA;
	rotateM.matrix[8] = tmp[2] * tmp[0] * (1 - cosA) - tmp[1] * sinA;
	rotateM.matrix[9] = tmp[2] * tmp[1] * (1 - cosA) + tmp[0] * sinA;
	rotateM.matrix[10] = pow(tmp[2], 2) * (1 - cosA) + cosA;

	return rotateM;
}

Matrix4	Matrix4::scaling(Vector3 const& v)
{
	Matrix4 scalingM(1.0f);
	scalingM.matrix[0] = v[0];
	scalingM.matrix[5] = v[1];
	scalingM.matrix[10] = v[2];
	return scalingM;
}

Matrix4	Matrix4::model(Matrix4 const& translation, Matrix4 const& rotation, Matrix4 const& scale)
{
	Matrix4 modelM = scale * rotation * translation;
	return modelM;
}

void	Matrix4::getMatrix(float fill[16]) const {
	for (size_t i = 0; i < 16; i++)
		fill[i] = matrix[i];
}

void	Matrix4::print(void) const {
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++)
			std::cout << matrix[i * 4 + j] << " ";
		std::cout << std::endl;
	}
}

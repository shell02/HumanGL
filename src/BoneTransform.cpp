#include "BoneTransform.hpp"

BoneTransform::BoneTransform() : _translation(Vector3(0.0f, 0.0f, 0.0f)), _rotation(Quaternion()) {}

BoneTransform::~BoneTransform() {}

void BoneTransform::setTranslation(Vector3 translation) {
	_translation = translation;
}

void BoneTransform::setRotation(Quaternion rotation) {
	_rotation = rotation;
}

Vector3 BoneTransform::getTranslation() const {
	return _translation;
}

Quaternion BoneTransform::getRotation() const {
	return _rotation;
}

Matrix4 BoneTransform::getTranslationMatrix() const {
	float matrix[16] = {
		1, 0, 0, _translation.getX(),
		0, 1, 0, _translation.getY(),
		0, 0, 1, _translation.getZ(),
		0, 0, 0, 1
	};

	return Matrix4(matrix);
}

Matrix4 BoneTransform::getRotationMatrix() const {
	return _rotation.toMatrix();
}

BoneTransform	BoneTransform::interpolate(BoneTransform const &bt1, BoneTransform const &bt2, float time) {
	BoneTransform result;

	result.setTranslation(Vector3::interpolate(bt1.getTranslation(), bt2.getTranslation(), time));
	result.setRotation(Quaternion::interpolate(bt1.getRotation(), bt2.getRotation(), time));

	return result;
}
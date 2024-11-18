#pragma once

#include "humanGL.h"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Quaternion.hpp"

class BoneTransform {
	public:
		BoneTransform();
		~BoneTransform();

		void setTranslation(Vector3 translation);
		void setRotation(Quaternion rotation);

		Vector3		getTranslation() const;
		Quaternion	getRotation() const;

		Matrix4	getTranslationMatrix() const;
		Matrix4	getRotationMatrix() const;

		static BoneTransform	interpolate(BoneTransform const &bt1, BoneTransform const &bt2, float time);

	private:

		Vector3		_translation;
		Quaternion	_rotation;
};
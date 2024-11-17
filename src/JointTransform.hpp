#pragma once

#include "humanGL.h"
#include "Vector.hpp"
#include "Matrix.hpp"

class JointTransform {
	public:
		JointTransform();
		~JointTransform();

		JointTransform& operator=(JointTransform const &copy);

		void clear();

	private:
		Vector3		_translation;
		//Quarternion	_rotation;
};
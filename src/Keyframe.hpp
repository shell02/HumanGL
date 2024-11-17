#pragma once

#include "humanGL.h"
#include "JointTransform.hpp"


class Keyframe {
	public:
		Keyframe();
		~Keyframe();

		Keyframe& operator=(Keyframe const &copy);

		void setTimestamp(float time);

		void clear();

	private:
		float		_timestamp;
		std::map<std::string, JointTransform>	_jointTransforms;

};
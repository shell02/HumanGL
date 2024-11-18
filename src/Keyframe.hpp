#pragma once

#include "humanGL.h"
#include "BoneTransform.hpp"


class Keyframe {
	public:
		Keyframe(std::map<std::string, BoneTransform> pose, float timestamp);
		~Keyframe();

		float getTimestamp() const;
		std::map<std::string, BoneTransform> getPose() const;

	private:
		float		_timestamp;
		std::map<std::string, BoneTransform>	_pose;
};
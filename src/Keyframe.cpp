#include "Keyframe.hpp"

Keyframe::Keyframe(std::map<std::string, BoneTransform> pose, float timestamp) : _timestamp(timestamp), _pose(pose)  {}

Keyframe::~Keyframe() {
	_pose.clear();
}

float	Keyframe::getTimestamp() const {
	return _timestamp;
}

std::map<std::string, BoneTransform>	Keyframe::getPose() const {
	return _pose;
}
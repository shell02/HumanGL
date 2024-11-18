#include "Animation.hpp"

Animation::Animation() : _duration(0.0f) {}

Animation::Animation(std::vector<Keyframe> keyframes, float duration) : _keyframes(keyframes), _duration(duration) {}

Animation::~Animation() {
	_keyframes.clear();
}

Animation&	Animation::operator=(Animation const &copy) {
	_keyframes = copy.getKeyframes();
	_duration = copy.getDuration();
	return *this;
}

float	Animation::getDuration() const {
	return _duration;
}

std::vector<Keyframe>	Animation::getKeyframes() const {
	return _keyframes;
}

void Animation::loadAnimation(std::string filename)
{
}

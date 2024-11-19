#include "Animator.hpp"

Animator::Animator(Model* model) : _model(model) {}

Animator::Animator(Animator const &src) {
	*this = src;
}

Animator::~Animator() {}

Animator&	Animator::operator=(Animator const &src) {
	if (this != &src) {
		_currentAnimation = src._currentAnimation;
		_currentTime = src._currentTime;
		_model = src._model;
	}
	return *this;
}

void	Animator::startAnimation(Animation const &animation) {
	_currentAnimation = animation;
	_currentTime = 0.0f;
}

void	Animator::update(float deltaTime) {
	if (_currentAnimation.getKeyframes().size() == 0) {
		return;
	}

	_currentTime += deltaTime;
	if (_currentTime > _currentAnimation.getDuration()) {
		_currentTime = fmod(_currentTime, _currentAnimation.getDuration());
	}

	std::map<std::string, BoneTransform> currentPose = calculateCurrentPose();

	_model->applyPoseToBones(currentPose);
}

std::map<std::string, BoneTransform> Animator::calculateCurrentPose()
{
	std::vector<Keyframe> keyframes = getPrevAndNextKeyframes();
	Keyframe prev = keyframes[0];
	Keyframe next = keyframes[1];
	float progression = getProgression(prev, next);
	return interpolatePoses(prev, next, progression);
}

std::map<std::string, BoneTransform> Animator::interpolatePoses(Keyframe const &prev, Keyframe const &next, float time)
{
	std::map<std::string, BoneTransform> currentPose;
	std::map<std::string, BoneTransform> prevPose = prev.getPose();
	std::map<std::string, BoneTransform> nextPose = next.getPose();

	for (std::map<std::string, BoneTransform>::iterator it = prevPose.begin(); it != prevPose.end(); it++) {
		std::string boneName = it->first;
		BoneTransform prevTransform = it->second;
		BoneTransform nextTransform = nextPose[boneName];
		BoneTransform currentTransform = BoneTransform::interpolate(prevTransform, nextTransform, time);
		currentPose[boneName] = currentTransform;
	}

	return currentPose;
}

float Animator::getProgression(Keyframe const &prev, Keyframe const &next)
{
	float totalTime = next.getTimestamp() - prev.getTimestamp();
	float currentTime = _currentTime - prev.getTimestamp();
	return currentTime / totalTime;
}

std::vector<Keyframe> Animator::getPrevAndNextKeyframes()
{
	std::vector<Keyframe> keyframes = _currentAnimation.getKeyframes();
	Keyframe prev = keyframes[0];
	Keyframe next = keyframes[0];

	for (size_t i = 1; i < keyframes.size(); i++) {
		next = keyframes[i];
		if (keyframes[i].getTimestamp() > _currentTime) {
			break;
		}
		prev = keyframes[i];
	}

	return {prev, next};
}
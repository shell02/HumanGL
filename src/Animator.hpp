#pragma once

#include "humanGL.h"
#include "Animation.hpp"
#include "Model.hpp"
#include "Keyframe.hpp"

class Animator {
	public:
		Animator(Model* model);
		Animator(Animator const &src);
		~Animator();

		Animator&	operator=(Animator const &src);
		
		void		startAnimation(Animation animation);
		void		update(float deltaTime);

	private:
		std::map<std::string, BoneTransform>	calculateCurrentPose();
		std::map<std::string, BoneTransform>	interpolatePoses(Keyframe const &current, Keyframe const &next, float time);
		float	getProgression(Keyframe const &current, Keyframe const &next);
		std::vector<Keyframe>	getPrevAndNextKeyframes();

		Animation	_currentAnimation;
		float		_currentTime;

		Model*		_model;
};
#pragma once

#include "humanGL.h"
#include "Keyframe.hpp"

class Animation {
	public:
		Animation();
		Animation(std::vector<Keyframe> keyframes, float duration);
		~Animation();

		Animation&	operator=(Animation const &copy);

		float	getDuration() const;

		std::vector<Keyframe>	getKeyframes() const;

		void	loadAnimation(std::string filename);
		int		getError() const;

	private:
		std::vector<Keyframe>	_keyframes;
		float					_duration;

		int						_error;

		void					_parseFile(std::string filename);
		std::map<std::string, BoneTransform>	getPose(std::stringstream &ss);
};
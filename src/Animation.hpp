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

	private:
		std::vector<Keyframe>	_keyframes;
		float					_duration;

		int						_error;

		void					_parseFile(std::string filename);
		void					_parseLine(std::string line);
		void					_parseKeyframe(std::string line);
		void					_parseBone(std::string line);
		void					_parseTranslation(std::string line);
		void					_parseRotation(std::string line);
};
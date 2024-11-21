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

void Animation::loadAnimation(std::string filename) {
	_keyframes.clear();
	_parseFile(filename);
}

void Animation::_parseFile(std::string filename) {
	std::ifstream	file(filename);
	std::string		line;

	float			timestamp;
	std::map<std::string, BoneTransform> pose;

	_error = 0;
	if (!file.is_open()) {
		std::cerr << "Could not open file: " << filename << std::endl;
		_error = 1;
		return;
	}

	while (std::getline(file, line)) {
		std::stringstream	ss(line);
		std::string			token;
		ss >> token;

		if (token == "duration") {
			ss >> _duration;
		} else if (token == "keyframe") {
			if (pose.size() > 0) {
				_keyframes.push_back(Keyframe(pose, timestamp));
			}
			ss >> timestamp;
			pose.clear();
		} else {
			std::string name = token;
			BoneTransform bone;

			std::string type;
			while (ss >> type) {
				if (type == "translate") {
					float x;
					float y;
					float z;
					ss >> x >> y >> z;
					bone.setTranslation(Vector3(x / 10, y / 10, z / 10));
				} else if (type == "rotation") {
					float angle, x, y, z;
					ss >> angle >> x >> y >> z;
					angle = 360 - angle;
					Quaternion rotation(angle, Vector3(x, y, z));
					bone.setRotation(rotation);
				} else {
					std::cerr << "Invalid token: " << type << std::endl;
					_error = 1;
					file.close();
					return;
				}
			}
			pose[name] = bone;
		}

	}

	if (pose.size() > 0) {
		_keyframes.push_back(Keyframe(pose, timestamp));
	}

	checkKeyframes();

	file.close();
}

bool	Animation::checkKeyframes() {
	if (_keyframes.size() == 0) {
		std::cerr << "No keyframes found" << std::endl;
		_error = 1;
		return false;
	}

	if (_keyframes[0].getTimestamp() != 0.0f) {
		std::cerr << "First keyframe timestamp is not 0" << std::endl;
		_keyframes.insert(_keyframes.begin(), Keyframe(_keyframes[0].getPose(), 0.0f));
		return true;
	}

	if (_keyframes[_keyframes.size() - 1].getTimestamp() != _duration) {
		std::cerr << "Last keyframe timestamp does not match duration" << std::endl;
		_keyframes.push_back(Keyframe(_keyframes[0].getPose(), _duration));
		return true;
	}

	return true;
}

int	Animation::getError() const {
	return _error;
}

void	Animation::clear() {
	_keyframes.clear();
	_duration = 0.0f;
	_error = 0;
}
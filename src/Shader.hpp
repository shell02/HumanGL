#pragma once

#include "humanGL.h"
#include "Vector.hpp"
#include "Matrix.hpp"

class Shader
{
	public:
		Shader(const char* vertexPath, const char* fragmentPath);

		void	clear() const;

		unsigned int getID() const;

		void use() const;

		void setBool(const std::string &name, bool value) const;
		void setInt(const std::string &name, int value) const;
		void setFloat(const std::string &name, float value) const;
		void set3Float(const std::string &name, Vector3 vec) const;
		void set4Float(const std::string &name, Vector4 vec) const;
		void setMat4(const std::string &name, Matrix4 mat, bool flip = true) const;
		

		void reloadShaderFiles(const char* vertexPath, const char* fragmentPath);

		int getErr() const;

	private:
		unsigned int ID;

		int err;

};
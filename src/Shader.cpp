#include "Shader.hpp"

std::string LoadShaderString(const char* fileName)
{
	std::fstream file;
	std::stringstream shaderText;

	file.open(fileName);
	if (file.is_open())
	{
		shaderText << file.rdbuf();
		file.close();
	}
	else
	{
		std::cerr << "Error opening file: " << fileName << std::endl;
	}
	return shaderText.str();
}

Shader::Shader(const char* vertexPath, const char* fragmentPath) : err(0)
{
	reloadShaderFiles(vertexPath, fragmentPath);
}

void Shader::clear() const
{
	glDeleteProgram(ID);
	return ;
}

unsigned int Shader::getID() const
{
	return ID;
}

void Shader::use() const
{
	glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::set3Float(const std::string &name, Vector3 vec) const
{
	glUniform3f(glGetUniformLocation(ID, name.c_str()), vec[0], vec[1], vec[3]);
}

void Shader::set4Float(const std::string &name, Vector4 vec) const
{
	glUniform4f(glGetUniformLocation(ID, name.c_str()), vec[0], vec[1], vec[3], vec[4]);
}

void Shader::setMat4(const std::string &name, Matrix4 mat, bool flip) const
{
	float tmp[16];
	mat.getMatrix(tmp);

	if (flip)
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_TRUE, tmp);
	else
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, tmp);
}

void Shader::reloadShaderFiles(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexShaderCode = LoadShaderString(vertexPath);
	std::string fragmentShaderCode = LoadShaderString(fragmentPath);

	unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);

	int success;
	char infoLog[512];
	const char* src = vertexShaderCode.c_str();

	glShaderSource(vertex, 1, &src, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cerr << infoLog << std::endl;
		err = 1;
	}

	src = fragmentShaderCode.c_str();
	glShaderSource(fragment, 1, &src, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cerr << infoLog << std::endl;
		err = 1;
	}

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cerr << infoLog << std::endl;
		err = 1;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

int Shader::getErr() const
{
	return err;
}

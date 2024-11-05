#pragma once

#ifndef TEXT_HPP
#define TEXT_HPP
#include "humanGL.h"
#include "Shader.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

#include <ft2build.h>
#include FT_FREETYPE_H

struct Character {
	unsigned int textureID;
	unsigned int sizeX;
	unsigned int sizeY;
	int bearingX;
	int bearingY;
	unsigned int advance;
};

class Text {
	public:
		Text(std::string fontPath = "fonts/Roboto-Medium.ttf", unsigned int fontSize = 48);
		~Text();

		bool getError() const;

		void renderText(std::string text, float x, float y, float scale = 1.0f, Vector3 color = Vector3(1.0f, 1.0f, 1.0f));
		void centerText(std::string text, float x, float y, float scale = 1.0f, Vector3 color = Vector3(1.0f, 1.0f, 1.0f));

		void clear();

	private:
		FT_Library ft;
		FT_Face face;

		bool error;

		std::map<char, Character> characters;

		unsigned int	VAO;
		unsigned int	VBO;
		Shader			textProgram;
		Matrix4			projection;
};

#endif
#include "Text.hpp"

Text::Text(std::string fontPath, unsigned int fontSize) : error(false), textProgram(Shader("shaders/textVertex.vs", "shaders/textFragment.fs")) {
	if (this->textProgram.getErr()) {
		this->error = true;
		return ;
	}

	if (FT_Init_FreeType(&this->ft)) {
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
		this->error = true;
		return ;
	}

	if (FT_New_Face(ft, fontPath.c_str(), 0, &this->face)) {
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
		this->error = true;
		return ;
	}

	FT_Set_Pixel_Sizes(this->face, 0, fontSize);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (unsigned char c = 0; c < 128; c++) {
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
			std::cout << "ERROR::FREETYPE: Failed to load Glyph" << std::endl;
			continue;
		}

		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			this->face->glyph->bitmap.width,
			this->face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			this->face->glyph->bitmap.buffer
		);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		Character	character = {
			texture,
			this->face->glyph->bitmap.width,
			this->face->glyph->bitmap.rows,
			this->face->glyph->bitmap_left,
			this->face->glyph->bitmap_top,
			(unsigned int)this->face->glyph->advance.x
		};
		this->characters.insert(std::pair<char, Character>(c, character));
	}

	FT_Done_Face(this->face);
	FT_Done_FreeType(this->ft);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);

	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	this->projection = Matrix4::orthographic(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f);
}

Text::~Text() {
	characters.clear();
}

bool Text::getError() const {
	return error;
}

void Text::renderText(std::string text, float x, float y, float scale, Vector3 color) {
	this->textProgram.use();
	this->textProgram.set3Float("textColor", color);
	this->textProgram.setMat4("projection", this->projection, false);

	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(this->VAO);

	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
    {
        Character ch = characters[*c];

        float xpos = x + ch.bearingX * scale;
        float ypos = y - (ch.sizeY - ch.bearingY) * scale;

        float w = ch.sizeX * scale;
        float h = ch.sizeY * scale;

        float vertices[6][4] = {
            { xpos,     ypos + h,   0.0f, 0.0f },            
            { xpos,     ypos,       0.0f, 1.0f },
            { xpos + w, ypos,       1.0f, 1.0f },

            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos + w, ypos,       1.0f, 1.0f },
            { xpos + w, ypos + h,   1.0f, 0.0f }           
        };

        glBindTexture(GL_TEXTURE_2D, ch.textureID);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); 
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        x += (ch.advance >> 6) * scale;
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void	Text::centerText(std::string text, float x, float y, float scale, Vector3 color) {
	float textWidth = 0.0f;
	float textHeight = 0.0f;

	for (std::string::const_iterator c = text.begin(); c != text.end(); c++) {
		Character ch = characters[*c];
		textWidth += (ch.advance >> 6) * scale;
		textHeight = ch.sizeY * scale;
	}

	this->renderText(text, x - textWidth / 2, y - textHeight / 2, scale, color);

}

void	Text::clear() {
	glDeleteProgram(this->textProgram.getID());
	glDeleteVertexArrays(1, &this->VAO);
	glDeleteBuffers(1, &this->VBO);

	for (std::map<char, Character>::iterator it = this->characters.begin(); it != this->characters.end(); it++) {
		glDeleteTextures(1, &it->second.textureID);
	}
}
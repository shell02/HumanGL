#include "GUI.hpp"

std::vector<float> buttonVertices({
	1.0f, 1.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f
});

std::vector<int> buttonIndices({
	0, 1, 3,
	1, 2, 3
});

GUI::GUI() : vertices(buttonVertices), indices(buttonIndices), shader("shaders/guiVertex.vs", "shaders/fragment.fs") {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	projection = Matrix4::orthographic(0.0f, (float)WINDOW_WIDTH, 0.0f, (float)WINDOW_HEIGHT, -1.0f, 1.0f);

}

GUI::GUI(GUI const &src) : shader("shaders/guiVertex.vs", "shaders/fragment.fs") {
	*this = src;
}

GUI::~GUI() {

}

void	GUI::clear() {
	glDeleteProgram(shader.getID());
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void	GUI::draw() {
	shader.use();
	bindVAO();
	bindEBO();
	bindVBO();
	
	for (std::vector<t_button>::iterator it = buttons.begin(); it != buttons.end(); it++) {
		t_button button = *it;

		Matrix4 model = Matrix4::translation(Vector3(button.x, button.y, 0.0f)) * Matrix4::scaling(Vector3(button.width, button.height, 1.0f));
		shader.setMat4("model", model);
		shader.setMat4("projection", projection, false);
		shader.set3Float("color", button.color);
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	}
	glBindVertexArray(0);
}

void	GUI::bindVAO() const {
	glBindVertexArray(VAO);
}

void	GUI::bindVBO() const {
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void	GUI::bindEBO() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

GUI&	GUI::operator=(GUI const &src) {
	if (this != &src) {
		clear();
		vertices = src.vertices;
		indices = src.indices;
		projection = src.projection;
		shader = src.shader;
		buttons = src.buttons;
	}
	return *this;
}

void	GUI::addButton(float x, float y, float width, float height, Vector3 color) {
	t_button button;

	button.x = x;
	button.y = y;
	button.width = width;
	button.height = height;
	button.color = color;

	buttons.push_back(button);
}

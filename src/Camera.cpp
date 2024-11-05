#include "Camera.hpp"

float toRadians(float degrees) {
	return degrees * M_PI / 180.0f;
}

Camera::Camera(Vector3 cameraPos, Vector3 cameraFront, Vector3 upVector)
	: cameraPos(cameraPos), cameraFront(cameraFront), upVector(upVector), deltatime(0), pitch(0.0f), yaw(-90.0f), moveSpeed(5.0f), rotateSpeed(10.0f)
{
	return ;
}

Camera::Camera(const Camera& copy)
	: cameraPos(copy.cameraPos), cameraFront(copy.cameraFront), upVector(copy.upVector), deltatime(copy.deltatime), pitch(copy.pitch), yaw(copy.yaw)
{
	return ;
}

Camera::~Camera()
{
	return ;
}

Camera& Camera::operator=(const Camera& copy)
{
	cameraPos = copy.cameraPos;
	cameraFront = copy.cameraFront;
	upVector = copy.upVector;
	deltatime = copy.deltatime;
	pitch = copy.pitch;
	yaw = copy.yaw;
	return *this;
}

Matrix4	Camera::LookAt(void) const {
	Vector3 cameraTarget = cameraPos + cameraFront;
	Vector3 cameraDirection = (cameraPos - cameraTarget).unit();
	Vector3 cameraRight = (upVector ^ cameraDirection).unit();
	Vector3 cameraUp = (cameraDirection ^ cameraRight);

	float rot[16] = {
		cameraRight[0], cameraRight[1], cameraRight[2], 0,
		cameraUp[0], cameraUp[1], cameraUp[2], 0,
		cameraDirection[0], cameraDirection[1], cameraDirection[2], 0,
		0, 0, 0, 1
	};

	float pos[16] = {
		1, 0, 0, -(cameraPos[0]),
		0, 1, 0, -(cameraPos[1]),
		0, 0, 1, -(cameraPos[2]),
		0, 0, 0, 1
	};

	Matrix4	lookAt = Matrix4(rot) * Matrix4(pos);
	
	return lookAt;
}

Matrix4	Camera::Projection(void) const {
	return Matrix4::perspective(45.0f, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
}

void	Camera::updateFront(void) {
	cameraFront = Vector3(
		cos(toRadians(yaw)) * cos(toRadians(pitch)),
		sin(toRadians(pitch)),
		sin(toRadians(yaw)) * cos(toRadians(pitch))
	).unit();
}

void	Camera::setYaw(float yaw) {
	this->yaw = yaw;
}

void	Camera::setPitch(float pitch) {
	this->pitch = pitch;
}

void	Camera::updatePos(Vector3 newPos) {
	cameraPos = newPos;
}

void	Camera::updateFront(Vector3 newFront) {
	cameraFront = newFront;
}

void	Camera::updateUp(Vector3 newUp) {
	upVector = newUp;
}

void	Camera::moveLeft() {
	cameraPos = cameraPos - (cameraFront ^ upVector).unit() * moveSpeed * deltatime;
}

void	Camera::moveRight() {
	cameraPos = cameraPos + (cameraFront ^ upVector).unit() * moveSpeed * deltatime;
}

void	Camera::moveFore() {
	cameraPos = cameraPos + cameraFront.unit() * moveSpeed * deltatime;
}

void	Camera::moveBack() {
	cameraPos = cameraPos - cameraFront.unit() * moveSpeed * deltatime;
}

void	Camera::rotateLeft() {
	yaw -= rotateSpeed * deltatime;
	updateFront();
}

void	Camera::rotateRight() {
	yaw += rotateSpeed * deltatime;
	updateFront();
}

void	Camera::rotateUp() {
	pitch += rotateSpeed * deltatime;
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;
	updateFront();
}

void	Camera::rotateDown() {
	pitch -= rotateSpeed * deltatime;
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;
	updateFront();
}

void	Camera::setDeltaTime(float d) {
	deltatime = d;
}

Vector3	Camera::getPos() const {
	return cameraPos;
}

void	Camera::setShader(Shader const &shader) const {
	shader.setMat4("view", LookAt());
	shader.setMat4("projection", Projection());
}
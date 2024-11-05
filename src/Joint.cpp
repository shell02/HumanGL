#include "Joint.hpp"

Joint::Joint() :
	translation(Matrix4(1.0f)),
	rotation(Matrix4(1.0f)),
	scale(Matrix4(1.0f))
{
	model = Matrix4::model(translation, rotation, scale);
}

Joint::Joint(Matrix4 translation, Matrix4 rotation, Matrix4 scale) :
	translation(translation),
	rotation(rotation),
	scale(scale)
{
	model = Matrix4::model(translation, rotation, scale);
}

Joint::~Joint()
{
	clear();
}

Joint& Joint::operator=(Joint const &copy)
{
	translation = copy.translation;
	rotation = copy.rotation;
	scale = copy.scale;
	model = copy.model;
	children = copy.children;
	return *this;
}

void Joint::clear()
{
	for (size_t i = 0; i < children.size(); i++)
	{
		children[i]->clear();
		delete children[i];
	}
	children.clear();
}

void Joint::addChild(Joint* child)
{
	children.push_back(child);
}

void Joint::updateModel()
{
	setHierarchy(modelStack);
}

void Joint::setHierarchy(std::vector<Matrix4> models)
{
	modelStack = models;
	modelStack.push_back(translation);
	modelStack.push_back(rotation);
	for (size_t i = 0; i < children.size(); i++)
	{
		children[i]->setHierarchy(modelStack);
	}
	modelStack.pop_back();
	modelStack.pop_back();
}

void Joint::setTranslation(Matrix4 translation)
{
	this->translation = translation;
	updateModel();
}

void Joint::setRotation(Matrix4 rotation)
{
	this->rotation = rotation;
	updateModel();
}

void Joint::setScale(Matrix4 scale)
{
	this->scale = scale;
	updateModel();
}

void Joint::setTranslation(Vector3 translation)
{
	this->translation = Matrix4::translation(translation);
	updateModel();
}


void Joint::setRotation(float angle, Vector3 rotation)
{
	this->rotation = Matrix4::rotation(angle, rotation);
	updateModel();
}

void Joint::setScale(Vector3 scale)
{
	this->scale = Matrix4::scaling(scale);
	updateModel();
}

Matrix4 Joint::getModel()
{
	Matrix4 stackedModel(1.0f);
	std::vector<Matrix4> divscaled;

	for (size_t i = 0; i < modelStack.size(); i++)
	{
		stackedModel = stackedModel * modelStack[i];
	}

	stackedModel = stackedModel * scale * rotation * translation;

	return stackedModel;
}

Vector3 Joint::getTranslation() const
{
	return Vector3(translation[3], translation[7], translation[11]);
}

Vector3 Joint::getScale() const
{
	return Vector3(scale[0], scale[5], scale[10]);
}
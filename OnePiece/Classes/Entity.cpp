#include "Entity.h"

Entity::Entity()
{
	m_sprite = NULL;
	m_frame = 1;
}

Entity::~Entity()
{
	
}

Sprite* Entity::getSprite()
{
	return this->m_sprite;
}

void Entity::bindSprite(Sprite* sprite)
{
	this->m_sprite = sprite;
	this->addChild(m_sprite);
}

void Entity::setController(Controller* controller)
{
	this->m_controller = controller;
	m_controller->setControllerListener(this);
}

void Entity::setTagPosition(int x, int y)
{
	setPosition(Point(x, y));
}

Point Entity::getTagPosition()
{
	return getPosition();
}

void Entity::setFrame(int frame)
{
	log("frame is changing!!!, the input is %d", frame);
	m_frame = frame;
}

int Entity::getFrame()
{
	return m_frame;
}
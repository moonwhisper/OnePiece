#include "Entity.h"

Entity::Entity()
{
	m_sprite = NULL;
	m_frame = 1;
	m_battleSerial = 0;
	m_jumpType = 0;
	isBattle = false;
	isJump = false;
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

	Size size = m_sprite->getContentSize();
	m_sprite->setPosition(Point(size.width*0.5f, size.height*0.5f));
	this->setContentSize(size);
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
	//log("frame is changing!!!, the input is %d", frame);
	m_frame = frame;
}

int Entity::getFrame()
{
	return m_frame;
}

void Entity::setBattle(int battleSerial)
{
	m_battleSerial = battleSerial;
}
int Entity::getBattle()
{
	return m_battleSerial;
}

void Entity::setJump(int jumpType)
{
	m_jumpType = jumpType;
}

int Entity::getJump()
{
	return m_jumpType;
}
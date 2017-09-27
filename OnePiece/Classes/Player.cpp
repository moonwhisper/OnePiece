#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

bool Player::init()
{
	//½«Í¼Æ¬¼ÓÔØµ½¾«ÁéÖ¡»º´æ³Ø
	SpriteFrameCache* lufeiCache11 = SpriteFrameCache::getInstance();
	lufeiCache11->addSpriteFramesWithFile("lufei-move.plist", "lufei-move.png");

	this->bindSprite(Sprite::createWithSpriteFrameName(StringUtils::format("move-%d.png", this->m_frame)));

	this->setPosition(Point(300, 200));

	this->schedule(schedule_selector(Player::playerUpdate), 0.01f);

	return true;
}

void Player::playerUpdate(float dt)
{
	log("player update time reached----%f",dt);
	
	this->m_sprite->setVisible(false);

	this->bindSprite(Sprite::createWithSpriteFrameName(StringUtils::format("move-%d.png", this->m_frame)));

	this->m_sprite->setVisible(true);
}
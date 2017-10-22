#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

bool Player::init()
{
	//��ͼƬ���ص�����֡�����
	SpriteFrameCache* lufeiCache11 = SpriteFrameCache::getInstance();
	lufeiCache11->addSpriteFramesWithFile("role.plist", "role.png");

	this->bindSprite(Sprite::createWithSpriteFrameName(StringUtils::format("move-%d.png", this->m_frame)));

	this->setPosition(Point(300, 150));

	this->schedule(schedule_selector(Player::playerUpdate), 0.01f);

	return true;
}

void Player::playerUpdate(float dt)
{
	//log("player update time reached----%f",dt);
	
	if (0 == m_battleSerial && false == isBattle && 0 ==m_jumpType &&false == isJump)
	{
		this->m_sprite->setVisible(false);

		this->bindSprite(Sprite::createWithSpriteFrameName(StringUtils::format("move-%d.png", this->m_frame)));

		this->m_sprite->setVisible(true);
	}
	else if (1 == m_battleSerial && false == isBattle && false == isJump)
	{
		log("punches");
		isBattle = true;

		this->m_sprite->setVisible(false);

		this->bindSprite(Sprite::createWithSpriteFrameName("battle-1.png"));

		this->m_sprite->setVisible(true);

		this->schedule(schedule_selector(Player::delayforBattle), 0.5f);

	}
	else if (1 == m_jumpType && false == isJump && false == isBattle)
	{
		

		log("jump");

		//�������Ϊ��Ծ״̬
		isJump = true;

		//������Ծ����,����Ϊ1�Σ��߶�Ϊ250pix��ԭ����Ծ����ʱ2s
		auto jump = JumpBy::create(1.0f, Point(0, 0), 100, 1);

		//�����ص�����
		auto callFunc = CallFunc::create([&](){
			isJump = false;
			m_jumpType = 0;
		});

		//������������
		auto JumpActions = Sequence::create(jump, callFunc, NULL);

		//ִ�ж���
		this->runAction(JumpActions);
	}
	else
	{
		;
	}

}

void Player::delayforBattle(float dt)
{

	log("after punchese");
	isBattle = false;
	m_battleSerial = 0;

	this->setFrame(1);

	this->unschedule(schedule_selector(Player::delayforBattle));
}

void Player::actJump(int jumpType)
{
	;
}
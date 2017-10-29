#include "WASD_Controller.h"

bool WASD_Controller::init()
{
	this->m_iSpeed = 0;

	auto key_press_listener = EventListenerKeyboard::create();

	key_press_listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
		keys[keyCode] = true;
		/*Point pos;
		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			pos = m_controllerListener->getTagPosition();
			pos.x -= m_iSpeed;
			m_controllerListener->setTagPosition(pos.x, pos.y);
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			pos = m_controllerListener->getTagPosition();
			pos.x += m_iSpeed;
			m_controllerListener->setTagPosition(pos.x, pos.y);
			break;
		default:
			break;
		}*/
	};

	key_press_listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
		keys[keyCode] = false;
	};
	

	_eventDispatcher->addEventListenerWithSceneGraphPriority(key_press_listener, this);


	//this->scheduleUpdate();
	this->schedule(schedule_selector(WASD_Controller::myupdate), 0.2f);
	return true;
}

void WASD_Controller::myupdate(float dt)
{
	if (m_controllerListener == NULL)
	{
		return;
	}
	
	/*增加移动对象的x坐标值*/
	//Point pos = m_controllerListener->getTagPosition();
	//pos.x += m_iSpeed;
	//m_controllerListener->setTagPosition(pos.x, pos.y);

	//avoid press multi keys
	if (isKeyPressed(EventKeyboard::KeyCode::KEY_UP_ARROW) && (isKeyPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW) || isKeyPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW)))
	{
		return;
	}


	if (isKeyPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW))
	{
		move(LEFT_DIR);
	}
	
	if (isKeyPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW))
	{
		move(RIGHT_DIR);
	}

	if (isKeyPressed(EventKeyboard::KeyCode::KEY_F) && 0 == m_controllerListener->getBattle())
	{
		battle(BATTLE_PUNCHES);
	}
	if (isKeyPressed(EventKeyboard::KeyCode::KEY_UP_ARROW) && 0 == m_controllerListener->getJump())
	{
		jumpControl(NORMAL_JUMP);
	}

}

void WASD_Controller::setiSpeed(int iSpeed)
{
	this->m_iSpeed = iSpeed;
}

bool WASD_Controller::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
	if (keys[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void WASD_Controller::move(int direction)
{
	Point pos;
	 
	int frame_now;

	switch(direction)
	{
	case LEFT_DIR:

		frame_now = m_controllerListener->getFrame();

		//log("frame:%d", m_controllerListener->getFrame());

		if (frame_now >= 1 && frame_now <= 4)
		{
			frame_now = 4;
		}

		if (8 == frame_now)
		{
			frame_now = 5;
		}
		m_controllerListener->setFrame(frame_now + 1);

		pos = m_controllerListener->getTagPosition();
		pos.x -= m_iSpeed;
		m_controllerListener->setTagPosition(pos.x, pos.y);

		//log("11");
		break;
	case RIGHT_DIR:

		frame_now = m_controllerListener->getFrame();

		//log("frame:%d", m_controllerListener->getFrame());

		if (frame_now >= 5 && frame_now <= 8)
		{
			frame_now = 0;
		}

		if (4 == frame_now)
		{
			frame_now = 0;
		}
		m_controllerListener->setFrame(frame_now + 1);


		pos = m_controllerListener->getTagPosition();
		pos.x += m_iSpeed;
		m_controllerListener->setTagPosition(pos.x, pos.y);

		break;
	default:
		break;
	}
}


void WASD_Controller::battle(int battle_serial)
{

	switch (battle_serial)
	{
	case BATTLE_PUNCHES:
		m_controllerListener->setBattle(BATTLE_PUNCHES);
		break;

	default:
		break;
	}

}

void WASD_Controller::jumpControl(int jumpType)
{
	log("jump ctr");

	switch (jumpType)
	{
	case NORMAL_JUMP:
		m_controllerListener->setJump(NORMAL_JUMP);
		break;

	default:
		break;
	}


}
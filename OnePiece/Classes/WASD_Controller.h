#ifndef _WASD_Controller_H_

#define _WASD_Controller_H_

#include "cocos2d.h"
#include "Controller.h"

#define LEFT_DIR 1
#define RIGHT_DIR 2
#define UP_DIR 3
#define DOWN_DIR 4

#define BATTLE_NONE 0
#define BATTLE_PUNCHES 1

#define NORMAL_JUMP 1

using namespace cocos2d;

class WASD_Controller : public Controller
{
public:
	CREATE_FUNC(WASD_Controller);
	virtual bool init();
	void myupdate(float dt);

	/*�����ƶ��ٶ�*/
	void setiSpeed(int iSpeed);

	/*��¼����״̬*/
	bool isKeyPressed(EventKeyboard::KeyCode keyCode);

	/*ִ��move����*/
	void move(int direction);

	/*ִ��ս������*/
	void battle(int battle_serial);

	void jumpControl(int jumpType);

private:
	int m_iSpeed;

	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

};




#endif
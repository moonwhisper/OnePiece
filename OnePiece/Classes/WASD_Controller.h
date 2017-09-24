#ifndef _WASD_Controller_H_

#define _WASD_Controller_H_

#include "cocos2d.h"
#include "Controller.h"

#define LEFT_DIR 1
#define RIGHT_DIR 2
#define UP_DIR 3
#define DOWN_DIR 4

using namespace cocos2d;

class WASD_Controller : public Controller
{
public:
	CREATE_FUNC(WASD_Controller);
	virtual bool init();
	virtual void update(float dt);

	/*设置移动速度*/
	void setiSpeed(int iSpeed);

	bool isKeyPressed(EventKeyboard::KeyCode keyCode);

	void move(int direction);

private:
	int m_iSpeed;

	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

};




#endif
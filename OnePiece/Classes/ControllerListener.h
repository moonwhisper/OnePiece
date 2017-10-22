#ifndef _ControllerListener_H_

#define _ControllerListener_H_

#include "cocos2d.h"
using namespace cocos2d;

class ControllerListener
{
public:
	/*����Ŀ������*/
	virtual void setTagPosition(int x, int y) = 0;

	/*��ȡĿ������*/
	virtual Point getTagPosition() = 0;

	/*����Ŀ��frame*/
	virtual void setFrame(int frame) = 0;

	/*��ȡĿ��frame*/
	virtual int getFrame() = 0;

	/*����battle���ͱ��*/
	virtual void setBattle(int battleSerial) = 0;

	/*��ȡbattle���ͱ��*/
	virtual int getBattle() = 0;

	/*����jump���ͱ��*/
	virtual void setJump(int jumpType) = 0;

	/*��ȡjump���ͱ��*/
	virtual int getJump() = 0;


};


#endif
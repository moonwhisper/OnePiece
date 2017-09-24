#ifndef _ControllerListener_H_

#define _ControllerListener_H_

#include "cocos2d.h"
using namespace cocos2d;

class ControllerListener
{
public:
	/*设置目标坐标*/
	virtual void setTagPosition(int x, int y) = 0;

	/*获取目标坐标*/
	virtual Point getTagPosition() = 0;

	/*设置目标frame*/
	virtual void setFrame(int frame) = 0;

	/*获取目标frame*/
	virtual int getFrame() = 0;

};


#endif
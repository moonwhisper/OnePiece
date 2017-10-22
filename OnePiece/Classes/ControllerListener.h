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

	/*设置battle类型标记*/
	virtual void setBattle(int battleSerial) = 0;

	/*获取battle类型标记*/
	virtual int getBattle() = 0;

	/*设置jump类型标记*/
	virtual void setJump(int jumpType) = 0;

	/*获取jump类型标记*/
	virtual int getJump() = 0;


};


#endif
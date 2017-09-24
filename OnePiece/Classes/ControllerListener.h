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

};


#endif
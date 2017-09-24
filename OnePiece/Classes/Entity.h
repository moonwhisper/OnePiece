#ifndef _Entity_H_

#define _Entity_H_


#include "cocos2d.h"
#include "ControllerListener.h"
#include "Controller.h"

using namespace cocos2d;
USING_NS_CC;

class Entity : public Node, public ControllerListener
{
public:

	Entity();
	~Entity();
	Sprite *getSprite();

	void bindSprite(Sprite* sprite);

	/*…Ë÷√øÿ÷∆∆˜*/
	void setController(Controller* controller);

	virtual void setTagPosition(int x, int y);
	virtual Point getTagPosition();
	virtual void setFrame(int frame);
	virtual int getFrame();

public:

	Sprite* m_sprite;
	int m_frame;
	Controller* m_controller;

};



#endif
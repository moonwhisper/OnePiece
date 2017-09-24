#ifndef _SecondScene_H_

#define _SecondScene_H_

#include "cocos2d.h"
#include "Player.h"
using namespace cocos2d;

class secondScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(secondScene);
private:
	Player* m_player;
};


#endif
#ifndef _First_Battle_Scene_H

#define _First_Battle_Scene_H

#include "cocos2d.h"
#include "Player.h"
#include "YaErLiTa.h"
#include "words.h"

using namespace cocos2d;


class firstBattleScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	//virtual void onEnter();
	CREATE_FUNC(firstBattleScene);

	virtual void update(float dt);


public:
	Player* m_player;

	YaErLiTa* m_YaErLiTa;


	float YaEr_x;
	float YaEr_y;

};



#endif

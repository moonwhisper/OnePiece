#ifndef _YaErLiTa_H_

#define _YaErLiTa_H_

#include "cocos2d.h"
#include "Player.h"
#include "Entity.h"

using namespace cocos2d;

class YaErLiTa : public Entity
{
public:

	CREATE_FUNC(YaErLiTa);
	virtual bool init();

	bool isCollideWithPlayer(Player* player);

};


#endif
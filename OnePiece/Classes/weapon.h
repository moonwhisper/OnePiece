#ifndef _Weapon_H_

#define _Weapon_H_

#include "Entity.h"
#include "cocos2d.h"
#include "Player.h"

using namespace cocos2d;

class Weapon : public Entity
{
public:
	Weapon();
	~Weapon();

	CREATE_FUNC(Weapon);
	virtual bool init();

	/*show the weapon*/
	void show();
	/*hide the weapon*/
	void hide();
	/*reset*/
	void reset();
	/*judge whether is alive*/
	bool isAlive();

	bool isCollideWithPlayer(Player* player);

private:
	bool m_isAlive;
};


#endif
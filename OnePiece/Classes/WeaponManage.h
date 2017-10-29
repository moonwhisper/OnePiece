#ifndef _WeaponManage_H_

#define _WeaponManage_H_

#include "weapon.h"
#include "cocos2d.h"

using namespace cocos2d;
USING_NS_CC;

#define MAX_WEAPON_NUM 2

class WeaponManage : public Node
{
public:

	virtual bool init();
	CREATE_FUNC(WeaponManage);

	virtual void update(float dt);

	void createWeapons();

	void bindPlayer(Player* player);

private:

	Vector<Weapon*> m_weaponArr;
	Player* m_player;

};


#endif
#include "WeaponManage.h"
#include "Player.h"

bool WeaponManage::init()
{
	createWeapons();
	this->scheduleUpdate();
	return true;
}


void WeaponManage::createWeapons()
{
	Weapon* weapon = NULL;
	Sprite* sprite = NULL;

	for (int i = 0; i < MAX_WEAPON_NUM; i++)
	{
		weapon = Weapon::create();
		weapon->bindSprite(Sprite::create("weaponForYaEr.png"));
		weapon->reset();

		this->addChild(weapon);

		m_weaponArr.pushBack(weapon);
	}
}

void WeaponManage::update(float dt)
{
	for (auto weapon : m_weaponArr)
	{
		if (weapon->isAlive())
		{
			weapon->setPositionX(weapon->getPositionX() - 6);

			if (weapon->getPositionX() < 0)
			{
				weapon->hide();
			}
			else if (weapon->isCollideWithPlayer(m_player))
			{
				m_player->hitedByWeapon();
				weapon->hide();
			}
		}
		else
		{
			weapon->show();
		}
	}

}

void WeaponManage::bindPlayer(Player* player)
{
	m_player = player;
}

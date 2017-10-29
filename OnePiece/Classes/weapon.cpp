#include "weapon.h"

Weapon::Weapon()
{
	m_isAlive = false;
}

Weapon::~Weapon()
{
	;
}

bool Weapon::init()
{
	return true;
}

void Weapon::show()
{
	if (NULL != getSprite())
	{
		setVisible(true);
		m_isAlive = true;
	}
}

void Weapon::hide()
{
	if (NULL != getSprite())
	{
		setVisible(false);
		reset();
		m_isAlive = false;
	}
}

void Weapon::reset()
{
	if (NULL != getSprite())
	{
		/*init the weapon coordinate*/
		setPosition(Point(1120 + CCRANDOM_0_1() * 2000, 140 - CCRANDOM_0_1() * 60));
	}
}

bool Weapon::isAlive()
{
	return m_isAlive;
}

bool Weapon::isCollideWithPlayer(Player* player)
{
	Rect entityRect = player->getBoundingBox();

	Point weaponPos = getPosition();

	return entityRect.containsPoint(weaponPos);
}
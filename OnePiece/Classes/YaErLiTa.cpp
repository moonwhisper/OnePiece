#include "YaErLiTa.h"


bool YaErLiTa::init()
{
	//��ͼƬ���ص�����֡�����
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("role.plist", "role.png");

	this->bindSprite(Sprite::createWithSpriteFrameName("YaErLiTa.png"));

	return true;
}

bool YaErLiTa::isCollideWithPlayer(Player* player)
{
	/*��ȡ�Լ���boundingBox*/
	Rect entityRect = this->getBoundingBox();

	//log("%f,%f,%f,%f", entityRect.getMinX(), entityRect.getMinY(), entityRect.getMaxX(), entityRect.getMaxY());

	/*��ȡ�������λ��*/
	Point pos = player->getPosition();

	//log("playerPos:%f,%f", pos.x, pos.y);

	/*�ж�boundingBox�͵������ĵ��Ƿ��н���*/
	return entityRect.containsPoint(pos);
}
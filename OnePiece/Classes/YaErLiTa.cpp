#include "YaErLiTa.h"


bool YaErLiTa::init()
{
	//将图片加载到精灵帧缓存池
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("role.plist", "role.png");

	this->bindSprite(Sprite::createWithSpriteFrameName("YaErLiTa.png"));

	return true;
}

bool YaErLiTa::isCollideWithPlayer(Player* player)
{
	/*获取自己的boundingBox*/
	Rect entityRect = this->getBoundingBox();

	//log("%f,%f,%f,%f", entityRect.getMinX(), entityRect.getMinY(), entityRect.getMaxX(), entityRect.getMaxY());

	/*获取检测对象的位置*/
	Point pos = player->getPosition();
	pos.y = pos.y + 10;   //this is beacuse the pos is left-below point coordinate,it may smaller than entityRect.getMinY()

	//log("playerPos:%f,%f", pos.x, pos.y);

	/*判断boundingBox和敌人中心点是否有交集*/
	return entityRect.containsPoint(pos);
}
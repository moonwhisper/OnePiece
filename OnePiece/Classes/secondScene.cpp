#include "secondScene.h"
#include "WASD_Controller.h"

Scene* secondScene::createScene()
{
	auto scene = Scene::create();

	auto layer = secondScene::create();

	scene->addChild(layer);

	return scene;
}

bool secondScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	TMXTiledMap* map = TMXTiledMap::create("secondScene.tmx");

	this->addChild(map);

	//将图片加载到精灵帧缓存池
	//SpriteFrameCache* lufeiCache = SpriteFrameCache::getInstance();
	//lufeiCache->addSpriteFramesWithFile("lufei-move.plist", "lufei-move.png");

	//创建主角
	m_player = Player::create();

	//m_player->bindSprite(Sprite::createWithSpriteFrameName("move-1.png"));
	//m_player->bindSprite(Sprite::createWithSpriteFrameName(StringUtils::format("move-%d.png", m_player->m_frame)));

	//m_player->setPosition(Point(300, 200));

	this->addChild(m_player);


	WASD_Controller* wasd_controller = WASD_Controller::create();

	/*设置移动速度*/
	wasd_controller->setiSpeed(12);

	this->addChild(wasd_controller);

	m_player->setController(wasd_controller);

	return true;

}


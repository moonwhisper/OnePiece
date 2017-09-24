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
	SpriteFrameCache* lufeiCache = SpriteFrameCache::getInstance();
	lufeiCache->addSpriteFramesWithFile("lufei-move.plist", "lufei-move.png");

	//依次创建动作分解图
	/*Sprite* lufeimove_1 = Sprite::createWithSpriteFrameName("move-1.png");
	lufeimove_1->setPosition(Point(100, 200));
	this->addChild(lufeimove_1);

	Sprite* lufeimove_2 = Sprite::createWithSpriteFrameName("move-2.png");
	lufeimove_2->setPosition(Point(300, 200));
	this->addChild(lufeimove_2);

	Sprite* lufeimove_3 = Sprite::createWithSpriteFrameName("move-3.png");
	lufeimove_3->setPosition(Point(500, 200));
	this->addChild(lufeimove_3);

	Sprite* lufeimove_4 = Sprite::createWithSpriteFrameName("move-4.png");
	lufeimove_4->setPosition(Point(700, 200));
	this->addChild(lufeimove_4);*/

	//创建主角
	m_player = Player::create();

	//m_player->bindSprite(Sprite::createWithSpriteFrameName("move-1.png"));
	m_player->bindSprite(Sprite::createWithSpriteFrameName(StringUtils::format("move-%d.png", m_player->m_frame)));

	m_player->setPosition(Point(300, 200));

	this->addChild(m_player);


	WASD_Controller* wasd_controller = WASD_Controller::create();

	/*设置移动速度*/
	wasd_controller->setiSpeed(5);

	this->addChild(wasd_controller);

	m_player->setController(wasd_controller);

	return true;

}

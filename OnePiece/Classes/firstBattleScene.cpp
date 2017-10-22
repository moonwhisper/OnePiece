#include "firstBattleScene.h"
#include "WASD_Controller.h"
#include "globalVar.h"

Scene* firstBattleScene::createScene()
{
	auto scene = Scene::create();

	auto layer = firstBattleScene::create();

	scene->addChild(layer);

	return scene;
}


bool firstBattleScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	//将图片加载到精灵帧缓存池
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("role.plist", "role.png");

	TMXTiledMap* map = TMXTiledMap::create("first_battle_scene.tmx");

	this->addChild(map);

	//获取对象层目标坐标
	TMXObjectGroup* objGroup = map->getObjectGroup("objects");

	//加载玩家坐标对象
	ValueMap playerPoint = objGroup->getObject("PlayerPoint");
	//加载克比坐标对象
	ValueMap YaErPoint = objGroup->getObject("YaErPoint");

	//亚尔丽塔出场
	//Sprite* YaEr = Sprite::createWithSpriteFrameName("YaErLiTa.png");
	//YaEr->setPosition(Point(YaErPoint.at("x").asFloat(), YaErPoint.at("y").asFloat()));
	//this->addChild(YaEr);
	m_YaErLiTa = YaErLiTa::create();
	m_YaErLiTa->setPosition(Point(YaErPoint.at("x").asFloat(), YaErPoint.at("y").asFloat()));
	this->addChild(m_YaErLiTa);


	YaEr_x = YaErPoint.at("x").asFloat();
	YaEr_y = YaErPoint.at("y").asFloat();


	//创建主角
	m_player = Player::create();

	m_player->setPosition(Point(playerPoint.at("x").asFloat(), playerPoint.at("y").asFloat()));


	this->addChild(m_player);


	WASD_Controller* wasd_controller = WASD_Controller::create();

	/*设置移动速度*/
	wasd_controller->setiSpeed(15);

	this->addChild(wasd_controller);

	m_player->setController(wasd_controller);


	this->scheduleUpdate();

}


void firstBattleScene::update(float dt)
{
	//log("%d",m_player->m_frame);

	if (m_YaErLiTa->isCollideWithPlayer(m_player))
	{
		log("hited");
	}
}

/*void firstBattleScene::onEnter()
{
	Layer::onEnter();
}*/
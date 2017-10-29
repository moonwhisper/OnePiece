#include "firstBattleScene.h"
#include "WASD_Controller.h"
#include "globalVar.h"
#include "WeaponManage.h"




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

	/*crete weapon manage*/
	WeaponManage* weaponMg = WeaponManage::create();

	weaponMg->bindPlayer(m_player);

	this->addChild(weaponMg);


	auto hpUI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("firstBattleUi_1.ExportJson");
	hpUI->setPosition(Point(0, 0));
	this->addChild(hpUI);

	m_hpLab = (Text*)Helper::seekWidgetByName(hpUI, "hpLab");
	m_hpLab_0 = (Text*)Helper::seekWidgetByName(hpUI, "hpLab_0");
	m_hpBar = (LoadingBar*)Helper::seekWidgetByName(hpUI, "hpBar");
	m_hpBgImg = (ImageView*)Helper::seekWidgetByName(hpUI, "hpBgImg");

	m_hpLab_0->setPosition(Point(visibleSize.width*0.07, visibleSize.height*0.9));
	m_hpLab->setPosition(Point(visibleSize.width*0.11, visibleSize.height*0.9));
	m_hpBar->setPosition(Point(visibleSize.width*0.105, visibleSize.height*0.95));
	m_hpBgImg->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.95));


/*	// 添加菜单
	Menu* menu = Menu::create();

	MenuItemFont* menuItem = MenuItemFont::create("popup", this, menu_selector(firstBattleScene::menuCallback));
	menuItem->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	menuItem->setColor(ccc3(255, 0, 0));
	menu->addChild(menuItem);


	menu->setPosition(Point::ZERO);
	this->addChild(menu);*/

	m_popIsOn = false;


	this->scheduleUpdate();

	return true;
}


void firstBattleScene::update(float dt)
{
	//log("%d",m_player->m_frame);

	//modify the hpbar
	m_hpBar->setPercent(m_player->getiHp()/100.0*100);

	//modify the hp value
	m_hpLab->setText(Value(m_player->getiHp()).asString());

	//deal with hp to 0 
	if (0 == m_player->getiHp() && false == m_popIsOn)
	{
		popupLayer(1);
	}

	//log("isBattle,%d", m_player->isBattle);

	/*if (m_YaErLiTa->isCollideWithPlayer(m_player))
	{
		log("hited!!!!!");
	}*/

	if (m_YaErLiTa->isCollideWithPlayer(m_player) && true == m_player->isBattle && false == m_popIsOn)
	{
		popupLayer(2);

		this->unscheduleUpdate();
		//log("congratulations! turn to next secne");
	}
}

/*void firstBattleScene::onEnter()
{
	Layer::onEnter();
}*/



void firstBattleScene::popupLayer(int pop_serial)
{

	m_popIsOn = true;
	

	switch (pop_serial)
	{
	case 1:
		// 定义一个弹出层，传入一张背景图
		pl = PopupLayer::create("pop-bg.png");
		// ContentSize 是可选的设置，可以不设置，如果设置把它当作 9 图缩放
		pl->setContentSize(CCSizeMake(640, 300));
		pl->setTitle(poem.FontToUTF8("任务失败"));
		pl->setContentText(poem.FontToUTF8("探险结束了，请注意躲避亚尔丽塔的飞锤，并尽快去攻击亚尔丽塔的本体，是否重新挑战？"), 20, 60, 250);
		// 设置回调函数，回调传回一个 CCNode 以获取 tag 判断点击的按钮
		// 这只是作为一种封装实现，如果使用 delegate 那就能够更灵活的控制参数了
		pl->setCallbackFunc(this, callfuncN_selector(firstBattleScene::buttonCallback));
		// 添加按钮，设置图片，文字，tag 信息
		pl->addButton("pop-ok.png", "pop-ok.png", poem.FontToUTF8("确定"), 0);
		pl->addButton("pop-ok.png", "pop-ok.png", poem.FontToUTF8("取消"), 1);
		// 添加到当前层
		this->addChild(pl);

		break;
	case 2:
		pl = PopupLayer::create("pop-success-bg.png");
		// ContentSize 是可选的设置，可以不设置，如果设置把它当作 9 图缩放
		pl->setContentSize(CCSizeMake(640, 300));
		pl->setTitle(poem.FontToUTF8("亚尔丽塔篇"));
		pl->setContentText(poem.FontToUTF8("恭喜你成功通关，新的征程，新的伙伴等待你去发掘，期待与你再次相见！"), 20, 60, 250);
		// 设置回调函数，回调传回一个 CCNode 以获取 tag 判断点击的按钮
		// 这只是作为一种封装实现，如果使用 delegate 那就能够更灵活的控制参数了
		pl->setCallbackFunc(this, callfuncN_selector(firstBattleScene::buttonCallback));
		// 添加按钮，设置图片，文字，tag 信息
		//pl->addButton("pop-ok.png", "pop-ok.png", poem.FontToUTF8("确定"), 0);
		pl->addButton("pop-ok.png", "pop-ok.png", poem.FontToUTF8("退出游戏"), 1);
		// 添加到当前层
		this->addChild(pl);

		break;
	}
		

}

/*void firstBattleScene::menuCallback(cocos2d::Object *pSender){
		popupLayer();
}*/

void firstBattleScene::buttonCallback(cocos2d::Node *pNode){
		log("button call back. tag: %d", pNode->getTag());

		switch (pNode->getTag())
		{
		case 0:
			enterSecondScene(this);
			break;
		case 1:
			#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
				MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
				return;
			#endif

			Director::getInstance()->end();

			#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
				exit(0);
			#endif
				
			break;
		default:
			break;
		}

		
}

void firstBattleScene::enterSecondScene(Ref* pSender)
{
	Director::getInstance()->popScene();
}
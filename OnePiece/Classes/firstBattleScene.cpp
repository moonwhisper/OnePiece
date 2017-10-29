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

	//��ͼƬ���ص�����֡�����
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("role.plist", "role.png");

	TMXTiledMap* map = TMXTiledMap::create("first_battle_scene.tmx");

	this->addChild(map);

	//��ȡ�����Ŀ������
	TMXObjectGroup* objGroup = map->getObjectGroup("objects");

	//��������������
	ValueMap playerPoint = objGroup->getObject("PlayerPoint");
	//���ؿ˱��������
	ValueMap YaErPoint = objGroup->getObject("YaErPoint");

	//�Ƕ���������
	//Sprite* YaEr = Sprite::createWithSpriteFrameName("YaErLiTa.png");
	//YaEr->setPosition(Point(YaErPoint.at("x").asFloat(), YaErPoint.at("y").asFloat()));
	//this->addChild(YaEr);
	m_YaErLiTa = YaErLiTa::create();
	m_YaErLiTa->setPosition(Point(YaErPoint.at("x").asFloat(), YaErPoint.at("y").asFloat()));
	this->addChild(m_YaErLiTa);


	YaEr_x = YaErPoint.at("x").asFloat();
	YaEr_y = YaErPoint.at("y").asFloat();


	//��������
	m_player = Player::create();

	m_player->setPosition(Point(playerPoint.at("x").asFloat(), playerPoint.at("y").asFloat()));


	this->addChild(m_player);


	WASD_Controller* wasd_controller = WASD_Controller::create();

	/*�����ƶ��ٶ�*/
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


/*	// ��Ӳ˵�
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
		// ����һ�������㣬����һ�ű���ͼ
		pl = PopupLayer::create("pop-bg.png");
		// ContentSize �ǿ�ѡ�����ã����Բ����ã�������ð������� 9 ͼ����
		pl->setContentSize(CCSizeMake(640, 300));
		pl->setTitle(poem.FontToUTF8("����ʧ��"));
		pl->setContentText(poem.FontToUTF8("̽�ս����ˣ���ע�����Ƕ������ķɴ���������ȥ�����Ƕ������ı��壬�Ƿ�������ս��"), 20, 60, 250);
		// ���ûص��������ص�����һ�� CCNode �Ի�ȡ tag �жϵ���İ�ť
		// ��ֻ����Ϊһ�ַ�װʵ�֣����ʹ�� delegate �Ǿ��ܹ������Ŀ��Ʋ�����
		pl->setCallbackFunc(this, callfuncN_selector(firstBattleScene::buttonCallback));
		// ��Ӱ�ť������ͼƬ�����֣�tag ��Ϣ
		pl->addButton("pop-ok.png", "pop-ok.png", poem.FontToUTF8("ȷ��"), 0);
		pl->addButton("pop-ok.png", "pop-ok.png", poem.FontToUTF8("ȡ��"), 1);
		// ��ӵ���ǰ��
		this->addChild(pl);

		break;
	case 2:
		pl = PopupLayer::create("pop-success-bg.png");
		// ContentSize �ǿ�ѡ�����ã����Բ����ã�������ð������� 9 ͼ����
		pl->setContentSize(CCSizeMake(640, 300));
		pl->setTitle(poem.FontToUTF8("�Ƕ�����ƪ"));
		pl->setContentText(poem.FontToUTF8("��ϲ��ɹ�ͨ�أ��µ����̣��µĻ��ȴ���ȥ�����ڴ������ٴ������"), 20, 60, 250);
		// ���ûص��������ص�����һ�� CCNode �Ի�ȡ tag �жϵ���İ�ť
		// ��ֻ����Ϊһ�ַ�װʵ�֣����ʹ�� delegate �Ǿ��ܹ������Ŀ��Ʋ�����
		pl->setCallbackFunc(this, callfuncN_selector(firstBattleScene::buttonCallback));
		// ��Ӱ�ť������ͼƬ�����֣�tag ��Ϣ
		//pl->addButton("pop-ok.png", "pop-ok.png", poem.FontToUTF8("ȷ��"), 0);
		pl->addButton("pop-ok.png", "pop-ok.png", poem.FontToUTF8("�˳���Ϸ"), 1);
		// ��ӵ���ǰ��
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
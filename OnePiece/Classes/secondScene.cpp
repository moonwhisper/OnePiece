#include "secondScene.h"
#include "WASD_Controller.h"
#include "globalVar.h"

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

	//��ȡ�����Ŀ������
	TMXObjectGroup* objGroup = map->getObjectGroup("objects");

	//��������������
	ValueMap playerPoint = objGroup->getObject("PlayerPoint");
	//���ؿ˱��������
	ValueMap kebiPoint = objGroup->getObject("kebiPoint");

	//��ͼƬ���ص�����֡�����
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("role.plist", "role.png");
	
	//�˱ȳ���
	Sprite* kebi = Sprite::createWithSpriteFrameName("kebi.png");
	kebi->setPosition(Point(kebiPoint.at("x").asFloat(), kebiPoint.at("y").asFloat()));
	this->addChild(kebi);

	kebi_x = kebiPoint.at("x").asFloat();
	kebi_y = kebiPoint.at("y").asFloat();

	//��ʼ״̬���Ի���û�д���
	for (int i = 0; i < DIALOG_TIMES; i++)
	{
		dialog_flag[i]=false;
	}

	//��������
	m_player = Player::create();


	this->addChild(m_player);


	WASD_Controller* wasd_controller = WASD_Controller::create();

	/*�����ƶ��ٶ�*/
	wasd_controller->setiSpeed(12);

	this->addChild(wasd_controller);

	m_player->setController(wasd_controller);


	//ע����Ļ�����¼�
	registeTouchEvent();

	//ע�������Ϣ�¼�
	registeKeyBoardEvent();

	this->schedule(schedule_selector(secondScene::seceneUpdate), 0.2f);

	return true;

}

void secondScene::registeKeyBoardEvent()
{
	//�����ո�ʱ���Ի��л�
	auto key_press_listener = EventListenerKeyboard::create();

	key_press_listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
	second_scene_key_check[keyCode] = true;
	};

	key_press_listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
	second_scene_key_check[keyCode] = false;
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(key_press_listener, this);
}

void secondScene::registeTouchEvent()
{
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [&](Touch* touch, Event* event)
	{
		return true;
	};

	listener->onTouchEnded = [&](Touch* touch, Event* event)
	{
		//log("test touch");

		//��ȡ���������
		Point touchPos = Director::getInstance()->convertToGL(touch->getLocationInView());

		if (touchPos.x > kebi_x - 70 && touchPos.x < kebi_x + 70 && touchPos.y > kebi_y - 70 && touchPos.y < kebi_y + 70 && false == dialog_flag[0])
		{
			dialog_flag[0] = true;

			dialog_bg = Sprite::create("dialog_blue-1.png");

			dialog_bg->setPosition(Point(560, 150));

			this->addChild(dialog_bg);


			kebi_dialog = Sprite::create("kebi-dialog.png");
			kebi_dialog->setPosition(Point(950, 200));
			kebi_dialog->setScale(0.5f);
			this->addChild(kebi_dialog);


			label = Label::create(myword.FontToUTF8("���գ��Ƕ�����С����ȥ�����̴��ˣ���ǧ���������Ƿ���������͵��"), "Arial", 24);

			label->setPosition(Point(560, 150));



			label->setLineBreakWithoutSpace(true);

			label->setWidth(500);

			label->setTextColor(Color4B::WHITE);
			//label->setMaxLineWidth(50);


			this->addChild(label);


		}
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


}

void secondScene::seceneUpdate(float dt)
{
	int index = -1;

	for (int i = 0; i < DIALOG_TIMES; i++)
	{
		if (true != dialog_flag[i])
		{
			index = i;
			break;
		}
	}


	if (isKeyPressed(EventKeyboard::KeyCode::KEY_SPACE) && 0 != index)
	{
		switch (index)
		{
		case 1:
			dialog_flag[1] = true;

			lufei_dialog = Sprite::create("lufei-dialog.png");
			lufei_dialog->setPosition(Point(150, 200));
			lufei_dialog->setScale(0.15f);
			this->addChild(lufei_dialog);

			kebi_dialog->setVisible(false);
			label->setString(myword.FontToUTF8("�ˣ���û�гԵģ��Ҷ��Ӻö�"));


			break;
		case 2:
			dialog_flag[2] = true;

			kebi_dialog->setVisible(true);
			lufei_dialog->setVisible(false);

			label->setString(myword.FontToUTF8("����˭? �Ͻ��ܰɣ��Ƕ�����С�������������Ҵ��������ֿ��ǻ�û����"));

			break;
		case 3:
			dialog_flag[3] = true;

			kebi_dialog->setVisible(false);
			lufei_dialog->setVisible(true);

			label->setString(myword.FontToUTF8("��������.D.·�ɣ��ں���Ư�ſ��治���װ������Ӻö���..."));

			break;

		case 4:
			dialog_flag[4] = true;

			YaErLiTa_dialog = Sprite::create("YaErLiTa-dialog.png");

			YaErLiTa_dialog->setPosition(Point(950, 200));
			YaErLiTa_dialog->setScale(0.15f);

			this->addChild(YaErLiTa_dialog);

			label->setString(myword.FontToUTF8("��~~��~~,���볢�����������������˰ɣ�"));

			lufei_dialog->setVisible(false);
			kebi_dialog->setVisible(false);
			break;

		case 5:
			dialog_flag[5] = true;

			kebi_dialog->setVisible(false);
			YaErLiTa_dialog->setVisible(false);
			lufei_dialog->setVisible(true);

			label->setString(myword.FontToUTF8("ѽ����п˱Ȱ��������³�Ĵ�����˭��"));
			break;

		case 6:
			dialog_flag[6] = true;

			kebi_dialog->setVisible(false);
			YaErLiTa_dialog->setVisible(true);
			lufei_dialog->setVisible(false);

			label->setString(myword.FontToUTF8("˵˭�Ǵ�³�Ĵ����أ������������ľ����"));
			break;
		case 7:

			//reset for init state  which is nesseary when return to this scene
			for (int k = 0; k < DIALOG_TIMES; k++)
			{
				dialog_flag[k] = false;
			}
			YaErLiTa_dialog->setVisible(false);
			label->setVisible(false);
			dialog_bg->setVisible(false);
			second_scene_key_check[EventKeyboard::KeyCode::KEY_SPACE] = false;

			//Director::getInstance()->replaceScene(TransitionFade::create(0.3f, firstBattleScene::createScene()));

			//push stack for when return to this scene,the data will not be lost
			Director::getInstance()->pushScene(TransitionFade::create(0.3f, firstBattleScene::createScene()));


			break;
		default:
			break;
		}
		
	}
}

bool secondScene::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
	if (second_scene_key_check[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    /*auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);*/

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    //auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    //label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                        origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    //this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("bg.png");

    // position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);

	auto bgUI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("StartScene_1.ExportJson");
	bgUI->setPosition(Point(0, 0));
	this->addChild(bgUI);
	
	//获取初始界面背景图片
	ImageView* bgPic = (ImageView*)Helper::seekWidgetByName(bgUI, "bgPic");
	bgPic->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    
	//获取开始游戏按钮
	Button* startBtn = (Button*)Helper::seekWidgetByName(bgUI, "startBtn");
	
	//添加开始游戏按钮监听
	startBtn->addTouchEventListener(this, toucheventselector(HelloWorld::startBtnOnClick));

	//获取退出游戏按钮
	Button* quitBtn = (Button*)Helper::seekWidgetByName(bgUI, "quitBtn");

	//添加退出游戏按钮监听
	quitBtn->addTouchEventListener(this, toucheventselector(HelloWorld::quitBtnOnClick));

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}


void HelloWorld::startBtnOnClick(Ref*, TouchEventType type)
{
	switch (type)
	{
		case TouchEventType::TOUCH_EVENT_BEGAN:
			break;
		case TouchEventType::TOUCH_EVENT_MOVED:
			break;
		case TouchEventType::TOUCH_EVENT_CANCELED:
			break;
		case TouchEventType::TOUCH_EVENT_ENDED:
			log("1223");
			break;
	}
}

void HelloWorld::quitBtnOnClick(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		//Close the cocos2d-x game scene and quit the application
		Director::getInstance()->end();

		#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
			exit(0);
		#endif

		break;
	}
}
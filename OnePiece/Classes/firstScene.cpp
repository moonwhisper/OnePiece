#include "firstScene.h"
#include "secondScene.h"
#include "words.h"


Scene* firstScene::createScene()
{
	auto scene = Scene::create();

	auto layer = firstScene::create();

	scene->addChild(layer);

	return scene;


}

bool firstScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto firstScene_bg = Sprite::create("firstScene.png");

	firstScene_bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(firstScene_bg);

	words myword;

	Label* label = Label::create(myword.FontToUTF8("东海的清晨，某个商船上正进行着party..."), "Arial", 24);
	label->setPosition(ccp(700, 450));
	this->addChild(label);

	//Sprite* lufei = Sprite::create("lufei.png");
	//lufei->setPosition(500, 300);
	//this->addChild(lufei);

	//Director::getInstance()->replaceScene(secondScene::createScene());

	this->schedule(schedule_selector(firstScene::myUpdate), 3.0f);
	return true;

}

/*char *firstScene::FontToUTF8(const char* font)
{
	int len = MultiByteToWideChar(CP_ACP, 0, font, -1, NULL, 0);
	wchar_t *wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);

	MultiByteToWideChar(CP_ACP, 0, font, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char *str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr)delete[] wstr;
	return str;
}*/

void firstScene::myUpdate(float dt)
{

	this->unschedule(schedule_selector(firstScene::myUpdate));

	Director::getInstance()->replaceScene(TransitionFade::create(0.3f, secondScene::createScene()));

}
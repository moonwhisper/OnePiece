#ifndef _SecondScene_H_

#define _SecondScene_H_

#include "cocos2d.h"
#include "Player.h"
#include "words.h"

#define DIALOG_TIMES 10

using namespace cocos2d;

class secondScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(secondScene);

	void seceneUpdate(float dt);
	bool isKeyPressed(EventKeyboard::KeyCode keyCode);

private:
	Player* m_player;

	float kebi_x;
	float kebi_y;

	words myword;

	std::map<cocos2d::EventKeyboard::KeyCode, bool> second_scene_key_check;   //记录键盘是否按过
	
	bool dialog_flag[DIALOG_TIMES];		//记录对话框进行状态，每个flag对应一个对话框是否执行过
	Sprite* dialog_bg;			//对话背景框
	Sprite* kebi_dialog;		//克比对话头像
	Sprite* lufei_dialog;		//路飞对话框头像
	Sprite* YaErLiTa_dialog;           //亚尔丽塔对话框头像

	Label* label;				//对话框，用于显示文字


	//注册屏幕触发事件，方便对话的触发和进行
	void registeTouchEvent();
	void registeKeyBoardEvent();
};


#endif
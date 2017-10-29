#ifndef _First_Battle_Scene_H

#define _First_Battle_Scene_H

#include "cocos2d.h"
#include "Player.h"
#include "YaErLiTa.h"
#include "words.h"
#include "PopupLayer.h"
#include "secondScene.h"

#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;

using namespace cocos2d;


class firstBattleScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	//virtual void onEnter();
	CREATE_FUNC(firstBattleScene);

	virtual void update(float dt);

	void popupLayer(int pop_serial);
	//void menuCallback(cocos2d::Object *pSender);
	void buttonCallback(cocos2d::Node *pNode);

	void enterSecondScene(Ref* pSender);


public:
	Player* m_player;

	YaErLiTa* m_YaErLiTa;


	float YaEr_x;
	float YaEr_y;

	int m_hp;   //the hp in the draw of first battle scene
	Text* m_hpLab;
	Text* m_hpLab_0;
	LoadingBar* m_hpBar;
	ImageView* m_hpBgImg;

	words poem;

	bool m_popIsOn;

	PopupLayer* pl;


};



#endif

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

	std::map<cocos2d::EventKeyboard::KeyCode, bool> second_scene_key_check;   //��¼�����Ƿ񰴹�
	
	bool dialog_flag[DIALOG_TIMES];		//��¼�Ի������״̬��ÿ��flag��Ӧһ���Ի����Ƿ�ִ�й�
	Sprite* dialog_bg;			//�Ի�������
	Sprite* kebi_dialog;		//�˱ȶԻ�ͷ��
	Sprite* lufei_dialog;		//·�ɶԻ���ͷ��
	Sprite* YaErLiTa_dialog;           //�Ƕ������Ի���ͷ��

	Label* label;				//�Ի���������ʾ����


	//ע����Ļ�����¼�������Ի��Ĵ����ͽ���
	void registeTouchEvent();
	void registeKeyBoardEvent();
};


#endif
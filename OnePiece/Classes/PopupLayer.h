#ifndef __PopupDemo__PopupLayer__

#define __PopupDemo__PopupLayer__

#include "cocos2d.h"
//#include "cocos-ext.h"

using namespace cocos2d;
//USING_NS_CC_EXT;
using namespace std;


class PopupLayer :public Layer
{
public:
	PopupLayer();
	~PopupLayer();

	virtual bool init();
	CREATE_FUNC(PopupLayer);

public:
	//��Ҫ��д����ע�ắ�������¸�����������
	//virtual void registerWithTouchDispatcher(void);

	//��д������������Զ���� true �����������㣬�ﵽ ��ģ̬�� Ч��
	bool onTouchBegan(Touch *touch, Event *event);

	//���죬�����öԻ��򱳾�ͼƬ
	static PopupLayer* create(const char* backgroundImage);

	//������ʾ�����������ݺʹ�С
	void setTitle(const char* title, int fontsize = 20);

	// �ı����ݣ�padding Ϊ���ֵ��Ի�������Ԥ���ľ��룬���ǿɿصģ����Ϸ��ľ����������
	void setContentText(const char* text, int fontsize = 20, int padding = 50, int paddintTop = 100);
	// �ص��������������ť�����ǹرյ������ͬʱ����Ҫһ���ص���������֪ͨ���ǵ�����ĸ���ť������ж����
	void setCallbackFunc(Object* target, SEL_CallFuncN callfun);
	// Ϊ����Ӱ�ť���㣬��װ��һ������������Щ��Ҫ�Ĳ���
	bool addButton(const char* normalImage, const char* selectedImage, const char* title, int tag = 0);

	//Ϊ������ʾ��ʱ֮ǰ��������Ч��ѡ����onEnter�ж�̬��ʾ
	virtual void onEnter();
	virtual void onExit();


public:
	void buttonCallback(Object* pSender);
	//void buttonCallback(Object* pSender);

	// �����������ߵĿհ���
	int m_contentPadding;
	int m_contentPaddingTop;

	Object* m_callbackListener;
	SEL_CallFuncN m_callback;
	
	CC_SYNTHESIZE_RETAIN(Menu*, m__pMenu, MenuButton);
	CC_SYNTHESIZE_RETAIN(Sprite*, m__sfBackGround, SpriteBackGround);
	CC_SYNTHESIZE_RETAIN(Sprite*, m__s9BackGround, Sprite9BackGround);
	CC_SYNTHESIZE_RETAIN(LabelTTF*, m__ltTitle, LabelTitle);
	CC_SYNTHESIZE_RETAIN(LabelTTF*, m__ltContentText, LabelContentText);



};


#endif
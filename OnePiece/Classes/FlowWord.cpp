#include "FlowWord.h"

bool FlowWord::init() 
{
	m_textLab = Label::create("", "Arial", 20);
	m_textLab->setColor(ccc3(255, 0, 0));
	m_textLab->setAnchorPoint(ccp(1, 0));
	m_textLab->setVisible(false);

	this->addChild(m_textLab);
	return true;
}

void FlowWord::showWord( const char* text, CCPoint pos ) 
{
	m_textLab->setString(text);
	m_textLab->setPosition(pos);
	m_textLab->setVisible(true);

	/* 组合两个动作，放大后缩小 */
    auto scaleLarge = ScaleTo::create(0.3f, 2.5f, 2.5f);
    auto scaleSmall = ScaleTo::create(0.5f, 0.5f, 0.5f);

    auto callFunc = CallFunc::create([&](){
        /* 动作结束，从父节点中删除自身 */
        m_textLab->setVisible(false);
        m_textLab->removeFromParentAndCleanup(true);
    });

    auto actions = Sequence::create(scaleLarge, scaleSmall, callFunc, NULL);

	m_textLab->runAction(actions);
}



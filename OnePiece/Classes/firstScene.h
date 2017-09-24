#ifndef _FirstScene_H_

#define _FirstScene_H_


#include "cocos2d.h"

using namespace cocos2d;
class firstScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(firstScene);

	char *FontToUTF8(const char* font);
	void myUpdate(float dt);

};




#endif
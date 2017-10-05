#ifndef _Words_H_

#define _Words_H_

#include "cocos2d.h"
using namespace cocos2d;

class words
{
public:
	words();
	~words();
	char * FontToUTF8(const char* font);

private:

	char *m_str;

};

#endif
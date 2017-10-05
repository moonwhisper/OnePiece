#include "words.h"


char* words::FontToUTF8(const char* font)
{

	int len = MultiByteToWideChar(CP_ACP, 0, font, -1, NULL, 0);
	wchar_t *wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);

	MultiByteToWideChar(CP_ACP, 0, font, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	m_str = new char[len + 1];
	memset(m_str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, m_str, len, NULL, NULL);
	if (wstr)delete[] wstr;
	return m_str;

}

words::words()
{
	m_str = NULL;
}

words::~words()
{
	if (NULL != m_str)
	{
		delete[] m_str;
	}

}
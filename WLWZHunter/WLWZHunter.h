// WLWZHunter.h: WLWZHunter DLL 的主标头文件
//

#pragma once
#include "HunterMain.h"
#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号
#define  _CRT_SECURE_NO_WARNINGS

// CWLWZHunterApp
// 有关此类实现的信息，请参阅 WLWZHunter.cpp
//

class CWLWZHunterApp : public CWinApp
{
public:
	CWLWZHunterApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

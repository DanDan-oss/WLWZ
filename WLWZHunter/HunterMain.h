#pragma once
#include "afxdialogex.h"
#include "GameBase.h"
#include "GameMoster.h"

#define _CRT_SECURE_NO_WARNINGS
// HunterMain 对话框
void __cdecl OutputDebugStringFA(const char* format, ...);
void __cdecl OutputDebugStringFW(const wchar_t* format, ...);

#ifdef _DEBUG
#define WinPrintA OutputDebugStringFA
#define WinPrintW OutputDebugStringFW
#else
#define WinPrintA
#define WinPrintW
#endif


class HunterMain : public CDialogEx
{
	DECLARE_DYNAMIC(HunterMain)

public:
	HunterMain(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~HunterMain();
	GameMoster pGameye;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLL_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
};

#pragma once
#include "afxdialogex.h"

// GameMoster 对话框

class GameMoster : public CDialogEx
{
	DECLARE_DYNAMIC(GameMoster)

public:
	GameMoster(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~GameMoster();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOSTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

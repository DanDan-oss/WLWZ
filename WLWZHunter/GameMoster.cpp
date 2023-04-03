// GameMoster.cpp: 实现文件
//

#include "pch.h"
#include "WLWZHunter.h"
#include "GameMoster.h"


// GameMoster 对话框

IMPLEMENT_DYNAMIC(GameMoster, CDialogEx)

GameMoster::GameMoster(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MOSTER, pParent)
{

}

GameMoster::~GameMoster()
{
}

void GameMoster::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GameMoster, CDialogEx)
END_MESSAGE_MAP()


// GameMoster 消息处理程序

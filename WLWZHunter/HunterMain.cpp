// HunterMain.cpp: 实现文件
//

#include "pch.h"
#include "WLWZHunter.h"
#include "HunterMain.h"
#define  _CRT_SECURE_NO_WARNINGS

VOID CALLBACK AutoRecovHP();
VOID CALLBACK AutoUseShorKey();

GAMEBASECALL GameCall;
AUTOCALL AutoCall;

// HunterMain 对话框

HANDLE hdApp;
//GAMEBASE GameAddre = {0};			// 游戏基址结构体
DWORD threadAutoHPID = NULL;		// 自动物品线程的ID
HANDLE ThreadAutoHand = NULL;		// 自动物品线程的句柄
DWORD ThreadADownKeyID = NULL;		// 自动打怪线程ID
HANDLE ThreadDownKeyHand = NULL;    // 自动打怪线程句柄

IMPLEMENT_DYNAMIC(HunterMain, CDialogEx)

HunterMain::HunterMain(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLL_MAIN, pParent)
{
}

HunterMain::~HunterMain()
{
	CloseHandle(hdApp);
	if (threadAutoHPID)
	{
		WinPrintA("GameHunter: 辅助正在剥离游戏进程, 关闭已开启的自动使用物品功能");
		TerminateThread(ThreadAutoHand, threadAutoHPID);
		CloseHandle(ThreadAutoHand);
		threadAutoHPID = NULL;
	}
	Sleep(1000);
	if (ThreadADownKeyID)
	{
		WinPrintA("GameHunter: 辅助正在剥离游戏进程, 关闭已开启的自动打怪功能");
		TerminateThread(ThreadDownKeyHand, ThreadADownKeyID);
		CloseHandle(ThreadDownKeyHand);
		ThreadADownKeyID = NULL;

		
	}
	Sleep(2000);

}

void HunterMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(HunterMain, CDialogEx)
END_MESSAGE_MAP()

// HunterMain 消息处理程序


VOID CALLBACK AutoUseShorKey()
{
//	AOTOCALL GameCall = { &GameAddre };
//	ROLE pRole = { &GameAddre };
//	while (true)
//	{
//		if (*pRole.HP < (*pRole.HPMax / 3))
//			GameCall.CallMeditat(&pRole);
//
//		if(!*pRole.SelecRoleState)
//			GameCall.CalltTabChoice();
//
//		while (*pRole.SelecRoleState)
//		{
//			if (!*pRole.HP)
//			{
//				float m_X = *pRole.CoorX;
//				float m_Y = *pRole.CoorY;
//				float m_H = *pRole.CoorZ;
//				WinPrintA("GameHunter: 角色已死亡,调用回城CALL！");
//				GameCall.CallOverHome();
//
//				GameCall.CallMeditat(&pRole);
//
//				GameCall.CallGoPlace(*pRole.CoorX + 100, *pRole.CoorY + 100);
//				WinPrintA("GameHunter: 自动走路开启, 前往死亡的地方\n");
//				BOOL CoorRun = GameCall.CallGoFindWay(&pRole, m_X, m_H, m_Y);
//				if (CoorRun)
//					break;
//
//				WinPrintA("GameHunter: 人为操作, 关闭自动打怪功能\n");
//				ThreadADownKeyID = NULL;
//				return;
//			}
//			GameCall.CallUseShorKey(&pRole);
//
//			if (!*pRole.SelecRoleState)
//				break;
//		}
//
//		for (int i = 0; i < 3; i++)
//			GameCall.CallPickUp();
//	}
}

VOID CALLBACK AutoRecovHP()
{
//	ROLE pRole = { &GameAddre };
//	AOTOCALL callBack = { &GameAddre };
//	while (true)
//	{
//		if (*pRole.HP < (*pRole.HPMax - *pRole.HPMax / 3))
//		{
//			WinPrintA("GameHunter: 血量低于70%\n");
//			if (!*pRole.HP)
//			{
//				if (ThreadADownKeyID)
//				{
//					WinPrintA("GameHunter: 角色已死亡,关闭自动打怪");
//					TerminateThread(ThreadDownKeyHand, ThreadADownKeyID);
//					CloseHandle(ThreadDownKeyHand);
//					ThreadADownKeyID = NULL;
//				}
//				WinPrintA("GameHunter: 角色已死亡,调用回城CALL");
//				callBack.CallOverHome();
//				continue;
//			}
//
//			KNAPARR pKnapArr = { &GameAddre };
//			for (int i = 0; i < 0x24; i++)
//			{
//				LPDWORD pKnaAddre = pKnapArr.KnapAddre + i;
//				if (!*pKnaAddre)
//					continue;
//
//				KNAPSACK pKnap = { pKnaAddre };
//
//				if (*pKnap.TypeID != 0x0C981B4)
//					continue;
//
//				callBack.CallUseKnapItem(i);
//				WinPrintA("GameHunter: %d位置的物品可以加血，药品剩余数量:%d \n", i, *pKnap.ItemNum);
//				Sleep(500);
//				break;
//			}
//
//		}
//		if (*pRole.MP * 3 < *pRole.MPMax)
//			WinPrintA("GameHunter: 蓝量低于33% \n");
//
//
//	}
}

void __cdecl OutputDebugStringFA(const char* format, ...)
{
	va_list v1Args;
	char* strBuffer = (char*)GlobalAlloc(GPTR, 4009);

	va_start(v1Args, format);
	_vsnprintf(strBuffer, 4096 - 1, format, v1Args);
	va_end(v1Args);
	strcat(strBuffer, "\n");
	OutputDebugStringA(strBuffer);
	GlobalFree(strBuffer);
	return;
}

void __cdecl OutputDebugStringFW(const wchar_t* format, ...)
{
	va_list v1Args;
	wchar_t* strBuffer = (wchar_t*)GlobalAlloc(GPTR, 4009);

	va_start(v1Args, format);
	_vswprintf_c(strBuffer, 4096 - 1, format, v1Args);
	va_end(v1Args);
	wcscat(strBuffer, L"\n");
	OutputDebugStringW(strBuffer);
	GlobalFree(strBuffer);
	return;
}

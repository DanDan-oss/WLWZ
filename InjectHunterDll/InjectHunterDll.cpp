#include <iostream>
#include <Windows.h>

#define DllPathA "D:/BaiduNetdiskDownload/GameHunter/WLWZ/WLWZHunter/Debug/WLWZHunter.dll"
#define GameClassNameA "QElementClient Window"
#define GameWndTitleA "Element Client"

int Inject();		// 游戏注入

int main()
{


	std::cout << addNumber(1, 2) << std::endl;

	system("title InjectDll testAdd=%x\n");
	system("color 02");

	int error = 0;
	if (error=Inject())
		printf(" Function return ERROR Code: %d\n", error);
	system("pause");
	return TRUE;
}


int Inject()
{
	HWND hwWindow = 0;		// 游戏窗口句柄
	DWORD dwProcID = 0;		// 游戏进程ID
	DWORD dwThreID = 0;		// 游戏主线程ID
	HANDLE hnProc = 0;		// 游戏进程句柄
	LPVOID pVirAdree = 0;	// 指向申请的远程空间
	HANDLE hnThre = NULL;
	int iStatus = 0;

	hwWindow = FindWindowA(GameClassNameA, GameWndTitleA);
	if (!hwWindow)
		return 1;

	dwThreID = GetWindowThreadProcessId(hwWindow, &dwProcID);
	if (!dwProcID)
		return 2;

	hnProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcID);
	if (!hnProc)
		return 3;

	do
	{
		pVirAdree = VirtualAllocEx(hnProc, NULL, MAX_PATH, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (!pVirAdree)
		{
			iStatus = 4;
			continue;
		}

		if (!WriteProcessMemory(hnProc, pVirAdree, DllPathA, strlen(DllPathA) + 1, NULL))
		{
			iStatus = 5;
			continue;
		}

		hnThre = CreateRemoteThread(hnProc, NULL, NULL, \
			(LPTHREAD_START_ROUTINE)LoadLibraryA, pVirAdree, NULL, NULL);
		if (!hnThre)
		{
			iStatus = 6;
			continue;
		}
			
		printf("   InjectDll:  OK\n");
		printf("游戏窗口句柄: %p  游戏进程ID: %d   游戏主线程ID %X  游戏进程句柄: %p\n",
		//	hwWindow, dwProcID, dwThreID, hnProc);

	} while (false);
	
	if(hnThre)
		CloseHandle(hnThre);
	if(pVirAdree)
		VirtualFreeEx(hnProc, pVirAdree, NULL, MEM_RELEASE);
	if(hnProc)
		CloseHandle(hnProc);

	return iStatus;
}

#pragma once
#include <Windows.h>

typedef struct _GAMEBASECALL
{
	/// [[elementclient.exe+A4B6D8]+0x1c]+0x2C]
	DWORD(CALLBACK* GetRoleBase)() = (DWORD(CALLBACK*)()) 0x055E3C0;	// 获取人物结构函数

	/// [elementclient.exe+A4B6D8]
	DWORD(CALLBACK* GetGameBase)() = (DWORD(CALLBACK*)()) 0x055E380;		// 获取游戏基址

	/// [[elementclient.exe+0xA4E478]+0x20]
	DWORD(CALLBACK* GetNpMoBase)() = (DWORD(CALLBACK*)())0x055E390;		// 获取游戏NPC/怪物/地面物品的基址函数

	/// [[elementclient.exe+0xA4E478]+0x24]
	DWORD(CALLBACK* GetFuncBase)() = (DWORD(CALLBACK*)())0x055E3A0;		// 获取游戏函数基址函数

}GAMEBASECALL, *PGAMEBASECALL;

// 人物结构体
typedef struct _ROLE
{
	//GAMEBASECALL GameBase;
	//LPVOID pRole= (void*)GameBase.GetRoleBase();		// 人物结构首地址
	LPVOID pRole = NULL;
	LPWSTR RoleName = (LPWSTR)(*(LPDWORD)((DWORD)pRole + 0x908)); // 当前角色名字
	PFLOAT CoorX = (PFLOAT)((DWORD)pRole + 0x3C);		// 人物当前X坐标
	PFLOAT CoorZ = (PFLOAT)((DWORD)pRole + 0x40);		// 人物当前Z坐标
	PFLOAT CoorY = (PFLOAT)((DWORD)pRole + 0x44);		// 人物当前Y坐标
	LPDWORD HP = (LPDWORD)((DWORD)pRole + 0x29C);		// 人物当前血量
	LPDWORD MP = (LPDWORD)((DWORD)pRole + 0x2A0);		// 人物当前蓝量
	LPDWORD HPMax = (LPDWORD)((DWORD)pRole + 0x2BD);
	LPDWORD MPMax = (LPDWORD)((DWORD)pRole + 0x2C1);
	LPDWORD KnapNum = (LPDWORD)(*(LPDWORD)((DWORD)pRole + 0x167C) + 0x10);			// 人物当前背包格数
	LPDWORD Knapsack = (LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pRole + 0x167C) + 0xC)); // 人物背包数组首地址
	LPDWORD SelecRoleState = (LPDWORD)(*(LPDWORD)((DWORD)pRole + 0x17B8) + 0x3C);		// 人物当前选中怪物是否死亡
	PFLOAT GoCoorX = (PFLOAT)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pRole + 0x1714) + 0x30) + 1 * 4) + 0x1c); // 要前往地点的X坐标
	PFLOAT GoCoorH = (PFLOAT)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pRole + 0x1714) + 0x30) + 1 * 4) + 0x20); // 要前往地点的Z坐标
	PFLOAT GoCoorY = (PFLOAT)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pRole + 0x1714) + 0x30) + 1 * 4) + 0x24); // 要前往地点的Y坐标
	LPDWORD SkilNum = (LPDWORD)((DWORD)pRole + 0x1764);			// 当前技能栏拥有技能数量
	LPDWORD Skill = (LPDWORD)((DWORD)pRole + 0x1760);			// 技能栏数组
}ROLE, *PROLE;

/// [[[[[[[[[elementclient.exe+A4F53C]+0x10]+0x38]+0x50]+0*4]+0xc]+0*4]+0]+0]
typedef struct _ERGNPCMOSTERARR
{
	//GAMEBASECALL GameBase;
	//LPDWORD pBaseAddre = (LPDWORD)GameBase.GetNpMoBase();
	LPDWORD pBaseAddre = NULL;

	LPDWORD playersNum = (LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x10) + 0x20) + 0x14);	// 周围玩家数量
	LPDWORD players = (LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x10) + 0x20) + 0xAC);		// 周围玩家数组

	LPDWORD ItemsNum = (LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x10) + 0x28) + 0x14);	// 当前附近地面物品数量
	LPDWORD ItemsMaxNum = (LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x10) + 0x28) + 0x18);// 当前附近物品最大显示
	LPDWORD NearbyItems = (LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x10) + 0x28) + 0x1c);// 附近物品数组(存储结构位置范围在起始地址到最大地址之间随机)
	
	LPDWORD NMNum = (LPDWORD)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x20) + 0x16C) + 0x24) + 0x5C);	// 附近NPC/怪物数量
	LPDWORD NpcMoster = (LPDWORD)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x20) + 0x16C) + 0x24) + 0x58);	// 附近NPC/怪物数组首地址

}ERGNPCMOSARR, *PERGNPCMOSARR;

//附近NPC/怪物结构
typedef struct _NpcMost
{
	LPDWORD pNpMoBase;
	LPDWORD NpMoTypeID = (LPDWORD)((DWORD)pNpMoBase + 0x0);		// 种类ID( 0xc9A7EC NPC   0xc9A530 怪物)
	LPDWORD NpMoID = (LPDWORD)((DWORD)pNpMoBase + 0xC);			// 怪物ID
	PFLOAT NpMoCoorX = (PFLOAT)((DWORD)pNpMoBase + 0x3C);		// X坐标
	PFLOAT NpMoCoorZ = (PFLOAT)((DWORD)pNpMoBase + 0x40);		// Z坐标
	PFLOAT NpMoCoorY = (PFLOAT)((DWORD)pNpMoBase + 0x44);		// Y坐标
	PFLOAT NpMoistan= (PFLOAT)((DWORD)pNpMoBase + 0x2F0);		// 与玩家的距离
	LPDWORD NpMoSysID = (LPDWORD)((DWORD)pNpMoBase + 0x114);	// 系统上的专属ID
	LPDWORD NpMoSysLV= (LPDWORD)((DWORD)pNpMoBase + 0x120);		// 等级
	LPDWORD NpMoHP = (LPDWORD)((DWORD)pNpMoBase + 0x130);	// 血量(只有选中过后才会从服务器请求血量信息)
	LPWSTR NpMoName = (LPWSTR)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pNpMoBase + 0x370) + 0xC) + 0) + 0);		// 名字
}NpcMost,*PNpcMost;


// 附近地面物品结构
typedef struct _ARTICLE
{
	LPDWORD ArtBase;
	LPDWORD ArtSysID = (LPDWORD)((DWORD)ArtBase + 0xC);		// 地面物品在系统上的ID
	PFLOAT ArtCoorX = (PFLOAT)(*(LPDWORD)((DWORD)ArtBase + 0x4) + 0x3C);	// 地面物品的X坐标
	PFLOAT ArtCoorZ = (PFLOAT)(*(LPDWORD)((DWORD)ArtBase + 0x4) + 0x40);	// 地面物品的H坐标
	PFLOAT ArtCoorY = (PFLOAT)(*(LPDWORD)((DWORD)ArtBase + 0x4) + 0x44);	// 地面物品的Y坐标
	PFLOAT ArtDistan = (PFLOAT)(*(LPDWORD)((DWORD)ArtBase + 0x4) + 0x1AC);	// 人与地面物品的距离
	LPDWORD ArtID = (LPDWORD)(*(LPDWORD)((DWORD)ArtBase + 0x4) + 0x108);	// 地面物品ID
	LPWSTR ArtName = (LPWSTR)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)ArtBase + 0x4) + 0x1DC) + 0xC) + 0) + 0);	// 地面物品的名字
}ARTICLE, *PARTICLE;


// 背包物品结构
/// [[[[[[elementclient.exe+0xA4B6D8]+0x1C]+0x2C]+0x167C]+0xC]+ebx*4
typedef struct _KNAPSACK
{
	LPDWORD KnapBase;
	LPDWORD TypeID = (LPDWORD)((DWORD)KnapBase + 0x0);		// 物品类型ID( 0x0C981B4药品  0x0C99650装备  0x0C9A11C 传送符)
	LPDWORD ItemID = (LPDWORD)((DWORD)KnapBase + 0xC);		// 物品ID
	LPDWORD ItemNum = (LPDWORD)((DWORD)KnapBase + 0x20);	// 物品数量
	LPDWORD ItemUseLV = (LPDWORD)((DWORD)KnapBase + 0x8C);	// 物品使用等级(消耗品)

	LPWSTR ItemNumOrName = (LPWSTR)(*(LPDWORD)((DWORD)KnapBase + 0x58) + 0xE); // 指向物品名字/说明
	LPWSTR ItemTypeName = (LPWSTR)(*(LPDWORD)((DWORD)KnapBase + 0x78) + 0x4);	// 物品类型名字
}KNAPSACK, * PKNAPSACK;


// 周围玩家信息结构
typedef struct _PLAYER
{
	LPDWORD PlayBase;
	PFLOAT PlayCoorX = (PFLOAT)((DWORD)PlayBase + 0x3C);		// 玩家X坐标
	PFLOAT PlayCoorZ = (PFLOAT)((DWORD)PlayBase + 0x40);		// 玩家Z坐标
	PFLOAT PlayCoorY = (PFLOAT)((DWORD)PlayBase + 0x44);		// 玩家Y坐标
	LPDWORD PlayLV = (LPDWORD)((DWORD)PlayBase + 0x28C);		// 玩家等级
	LPDWORD PlayHP = (LPDWORD)((DWORD)PlayBase + 0x29C);		// 玩家当前血量
	LPDWORD PlayMP = (LPDWORD)((DWORD)PlayBase + 0x2A0);		// 玩家当前蓝量
	LPDWORD PlayMaxHP = (LPDWORD)((DWORD)PlayBase + 0x2BD);		// 玩家最大血量
	LPDWORD PlayMaxMP = (LPDWORD)((DWORD)PlayBase + 0x2C1);		// 玩家最大蓝量
	LPWSTR PlayName = (LPWSTR)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)PlayBase + 0x9E0) + 0xC) + 0) + 0); // 玩家名字

}PLAYER, *PLAYERS;

typedef struct _AUTOCALL
{
	GAMEBASECALL GameBase;
	DWORD GetRoleCall = (DWORD)GameBase.GetRoleBase;		// 获取人物基址CALL
	DWORD GetGameCall = (DWORD)GameBase.GetGameBase;		// 获取游戏基址CALL
	DWORD GetNpMoCall = (DWORD)GameBase.GetNpMoBase;		// 获取游戏NPC/怪物/地面物品的基址CALL
	DWORD GetFuncCall = (DWORD)GameBase.GetFuncBase;		// 获取游戏函数基址CALL


	// 使用背包物品(物品在背包的下标)
	VOID CALLBACK UseKnapItem(UINT ItmeIndex)
	{
		DWORD CALLGetRole = GetRoleCall;
		DWORD CallBackOne = 0x48B920;

		__asm	call CALLGetRole			// 获取人物基址
		__asm	mov ecx, eax
		__asm	push ItmeIndex			// 物品在背包格数
		__asm	push 0					// 常量
		__asm	call CallBackOne

		Sleep(200);
	}

	// 移动背包物品(要移往的位置, 当前位置, 背包栏{ 普通背包物品 0   坐骑背包物品 7} )
	VOID CALLBACK MovKNAPItem(UINT NewIndex, UINT OldIndex, UINT KnapNum=0)
	{								
		DWORD CallBackOne = 0x7A4F40;
		__asm
		{
			push KnapNum
			push NewIndex
			push OldIndex
			mov ecx, dword ptr ds:[0xE52264]		// 指向ASCII "0菜"
			call CallBackOne
		}
		Sleep(200);
	}

	// 打坐()
	VOID CALLBACK Medita()
	{
		DWORD CallBackOne = 0x7E14A0;
		__asm
		{
			call CallBackOne;
		}
		Sleep(200);
	}

	// 取消打坐()
	VOID CALLBACK UnMedita()
	{
		DWORD CallBackOne = 0x7E1460;
		__asm
		{
			call CallBackOne
		}
		Sleep(200);
	}

	// 打开NPC对话框(NPC在系统上的ID)
	// 在NPC 5M的范围内打开
	VOID OpenNPCDialog(UINT NPC_ID)
	{
		DWORD CallGetFunc = GetFuncCall;
		DWORD CallBackOne = 0x790AF0;
		__asm
		{
			push NPC_ID
			call CallGetFunc
			lea ecx, dword ptr ds:[eax+0x2A0]
			call CallBackOne
		}
		Sleep(600);
	}

	// 关闭NPC对话框
	VOID CloseNPCDialog()
	{
		DWORD CallGetNpMo = GetNpMoCall;
		DWORD CallBackOne = 0x09FF6D0;
		__asm
		{
			call CallGetNpMo
			mov ecx, eax
			mov ecx, dword ptr ds:[ecx+0xC]
			mov ecx, dword ptr ds:[ecx+0x8]
			mov ecx, dword ptr ds:[ecx+0x26C]

			push 0x0d92e65
			call CallBackOne
		}
		Sleep(500);
	}

	// 购买商店物品（物品ID, 物品在商店格位置, 购买数量）  --- 需要打开NPC对话框后才能购买
	VOID CALLBACK ShopPing(UINT  ArtID, UINT ShopIndex, UINT Number)
	{
		DWORD CallBackOne = 0x07E2C20;
		__asm
		{
			push Number
			push ShopIndex
			push ArtID

			push esp
			push 1
			call CallBackOne
			add esp, 0x14
		}
		Sleep(500);
	}

	// 贩卖背包物品(物品ID, 物品在背包的下标, 贩卖数量)
	VOID CALLBACK Traffic(UINT  ArtID, UINT ShopIndex, UINT Number)
	{
		DWORD CallGetFunc = GetFuncCall;
		DWORD CallBackOne = 0x7A5290;
		__asm
		{
			push Number
			push ShopIndex
			push ArtID
			push esp
			push 0x1
			call CallGetFunc
			mov ecx, eax
			call CallBackOne
			add esp, 0xC
		}
		Sleep(500);
	}

	// 根据地上物品ID拾取物品(地面物品在服务器上的ID, 物品的ID)
	VOID CALLBACK  PickUpItem(UINT ItemSysID, UINT ItemID)
	{
		DWORD CallGetFunc = GetFuncCall;
		DWORD CallBackOne = 0x7906D0;
		__asm
		{
			push 0
			push ItemID
			push ItemSysID

			call CallGetFunc
			lea ecx, dword ptr ds:[eax+0x2A0]
			call CallBackOne
		}
		Sleep(500);
	}

	// 随机捡起地上物品()
	VOID CALLBACK PickUpItems()
	{
		DWORD CallGetRole = GetRoleCall;
		DWORD CallBackOne = 0x470050;
		__asm
		{
			call CallGetRole
			mov ecx, eax
			call CallBackOne
		}
		Sleep(500);
	}

	// 丢弃背包物品(物品在背包的位置, 丢弃数量)
	VOID CALLBACK GiveUpItem(UINT ItemIndex, UINT Number)
	{
		DWORD CallBackOne = 0x7A4F80;
		__asm
		{
			push Number
			push ItemIndex
			mov ecx, 0x6E04F00
			call CallBackOne
		}
		Sleep(500);
	}

	// 使用Tab键随机选怪
	VOID CALLBACK RandomTab()
	{
		DWORD CallGetRole = GetRoleCall;
		DWORD CallBackOne = 0x480570;
		__asm
		{
			call CallGetRole
			mov ecx, eax

			push 0x145
			push esp
			call CallBackOne
			add esp, 4
		}
		Sleep(500);
	}

	// 通过怪物ID选择怪物
	VOID CALLBACK MostIDSele(UINT MosterID)
	{
		DWORD CallGetFunc = GetFuncCall;
		DWORD CallBackOne = 0x78FC40;
		__asm 
		{
			call CallGetFunc
			lea ecx, dword ptr ds:[eax+0x2A0]

			push MosterID
			call CallBackOne
		}
		Sleep(500);
	}


}AUTOCALL, * PAUTOCALL;

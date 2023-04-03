#pragma once
#include <Windows.h>

typedef struct _GAMEBASECALL
{
	/// [[elementclient.exe+A4B6D8]+0x1c]+0x2C]
	DWORD(CALLBACK* GetRoleBase)() = (DWORD(CALLBACK*)()) 0x055E3C0;	// ��ȡ����ṹ����

	/// [elementclient.exe+A4B6D8]
	DWORD(CALLBACK* GetGameBase)() = (DWORD(CALLBACK*)()) 0x055E380;		// ��ȡ��Ϸ��ַ

	/// [[elementclient.exe+0xA4E478]+0x20]
	DWORD(CALLBACK* GetNpMoBase)() = (DWORD(CALLBACK*)())0x055E390;		// ��ȡ��ϷNPC/����/������Ʒ�Ļ�ַ����

	/// [[elementclient.exe+0xA4E478]+0x24]
	DWORD(CALLBACK* GetFuncBase)() = (DWORD(CALLBACK*)())0x055E3A0;		// ��ȡ��Ϸ������ַ����

}GAMEBASECALL, *PGAMEBASECALL;

// ����ṹ��
typedef struct _ROLE
{
	//GAMEBASECALL GameBase;
	//LPVOID pRole= (void*)GameBase.GetRoleBase();		// ����ṹ�׵�ַ
	LPVOID pRole = NULL;
	LPWSTR RoleName = (LPWSTR)(*(LPDWORD)((DWORD)pRole + 0x908)); // ��ǰ��ɫ����
	PFLOAT CoorX = (PFLOAT)((DWORD)pRole + 0x3C);		// ���ﵱǰX����
	PFLOAT CoorZ = (PFLOAT)((DWORD)pRole + 0x40);		// ���ﵱǰZ����
	PFLOAT CoorY = (PFLOAT)((DWORD)pRole + 0x44);		// ���ﵱǰY����
	LPDWORD HP = (LPDWORD)((DWORD)pRole + 0x29C);		// ���ﵱǰѪ��
	LPDWORD MP = (LPDWORD)((DWORD)pRole + 0x2A0);		// ���ﵱǰ����
	LPDWORD HPMax = (LPDWORD)((DWORD)pRole + 0x2BD);
	LPDWORD MPMax = (LPDWORD)((DWORD)pRole + 0x2C1);
	LPDWORD KnapNum = (LPDWORD)(*(LPDWORD)((DWORD)pRole + 0x167C) + 0x10);			// ���ﵱǰ��������
	LPDWORD Knapsack = (LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pRole + 0x167C) + 0xC)); // ���ﱳ�������׵�ַ
	LPDWORD SelecRoleState = (LPDWORD)(*(LPDWORD)((DWORD)pRole + 0x17B8) + 0x3C);		// ���ﵱǰѡ�й����Ƿ�����
	PFLOAT GoCoorX = (PFLOAT)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pRole + 0x1714) + 0x30) + 1 * 4) + 0x1c); // Ҫǰ���ص��X����
	PFLOAT GoCoorH = (PFLOAT)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pRole + 0x1714) + 0x30) + 1 * 4) + 0x20); // Ҫǰ���ص��Z����
	PFLOAT GoCoorY = (PFLOAT)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pRole + 0x1714) + 0x30) + 1 * 4) + 0x24); // Ҫǰ���ص��Y����
	LPDWORD SkilNum = (LPDWORD)((DWORD)pRole + 0x1764);			// ��ǰ������ӵ�м�������
	LPDWORD Skill = (LPDWORD)((DWORD)pRole + 0x1760);			// ����������
}ROLE, *PROLE;

/// [[[[[[[[[elementclient.exe+A4F53C]+0x10]+0x38]+0x50]+0*4]+0xc]+0*4]+0]+0]
typedef struct _ERGNPCMOSTERARR
{
	//GAMEBASECALL GameBase;
	//LPDWORD pBaseAddre = (LPDWORD)GameBase.GetNpMoBase();
	LPDWORD pBaseAddre = NULL;

	LPDWORD playersNum = (LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x10) + 0x20) + 0x14);	// ��Χ�������
	LPDWORD players = (LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x10) + 0x20) + 0xAC);		// ��Χ�������

	LPDWORD ItemsNum = (LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x10) + 0x28) + 0x14);	// ��ǰ����������Ʒ����
	LPDWORD ItemsMaxNum = (LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x10) + 0x28) + 0x18);// ��ǰ������Ʒ�����ʾ
	LPDWORD NearbyItems = (LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x10) + 0x28) + 0x1c);// ������Ʒ����(�洢�ṹλ�÷�Χ����ʼ��ַ������ַ֮�����)
	
	LPDWORD NMNum = (LPDWORD)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x20) + 0x16C) + 0x24) + 0x5C);	// ����NPC/��������
	LPDWORD NpcMoster = (LPDWORD)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pBaseAddre + 0x20) + 0x16C) + 0x24) + 0x58);	// ����NPC/���������׵�ַ

}ERGNPCMOSARR, *PERGNPCMOSARR;

//����NPC/����ṹ
typedef struct _NpcMost
{
	LPDWORD pNpMoBase;
	LPDWORD NpMoTypeID = (LPDWORD)((DWORD)pNpMoBase + 0x0);		// ����ID( 0xc9A7EC NPC   0xc9A530 ����)
	LPDWORD NpMoID = (LPDWORD)((DWORD)pNpMoBase + 0xC);			// ����ID
	PFLOAT NpMoCoorX = (PFLOAT)((DWORD)pNpMoBase + 0x3C);		// X����
	PFLOAT NpMoCoorZ = (PFLOAT)((DWORD)pNpMoBase + 0x40);		// Z����
	PFLOAT NpMoCoorY = (PFLOAT)((DWORD)pNpMoBase + 0x44);		// Y����
	PFLOAT NpMoistan= (PFLOAT)((DWORD)pNpMoBase + 0x2F0);		// ����ҵľ���
	LPDWORD NpMoSysID = (LPDWORD)((DWORD)pNpMoBase + 0x114);	// ϵͳ�ϵ�ר��ID
	LPDWORD NpMoSysLV= (LPDWORD)((DWORD)pNpMoBase + 0x120);		// �ȼ�
	LPDWORD NpMoHP = (LPDWORD)((DWORD)pNpMoBase + 0x130);	// Ѫ��(ֻ��ѡ�й���Ż�ӷ���������Ѫ����Ϣ)
	LPWSTR NpMoName = (LPWSTR)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)pNpMoBase + 0x370) + 0xC) + 0) + 0);		// ����
}NpcMost,*PNpcMost;


// ����������Ʒ�ṹ
typedef struct _ARTICLE
{
	LPDWORD ArtBase;
	LPDWORD ArtSysID = (LPDWORD)((DWORD)ArtBase + 0xC);		// ������Ʒ��ϵͳ�ϵ�ID
	PFLOAT ArtCoorX = (PFLOAT)(*(LPDWORD)((DWORD)ArtBase + 0x4) + 0x3C);	// ������Ʒ��X����
	PFLOAT ArtCoorZ = (PFLOAT)(*(LPDWORD)((DWORD)ArtBase + 0x4) + 0x40);	// ������Ʒ��H����
	PFLOAT ArtCoorY = (PFLOAT)(*(LPDWORD)((DWORD)ArtBase + 0x4) + 0x44);	// ������Ʒ��Y����
	PFLOAT ArtDistan = (PFLOAT)(*(LPDWORD)((DWORD)ArtBase + 0x4) + 0x1AC);	// ���������Ʒ�ľ���
	LPDWORD ArtID = (LPDWORD)(*(LPDWORD)((DWORD)ArtBase + 0x4) + 0x108);	// ������ƷID
	LPWSTR ArtName = (LPWSTR)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)ArtBase + 0x4) + 0x1DC) + 0xC) + 0) + 0);	// ������Ʒ������
}ARTICLE, *PARTICLE;


// ������Ʒ�ṹ
/// [[[[[[elementclient.exe+0xA4B6D8]+0x1C]+0x2C]+0x167C]+0xC]+ebx*4
typedef struct _KNAPSACK
{
	LPDWORD KnapBase;
	LPDWORD TypeID = (LPDWORD)((DWORD)KnapBase + 0x0);		// ��Ʒ����ID( 0x0C981B4ҩƷ  0x0C99650װ��  0x0C9A11C ���ͷ�)
	LPDWORD ItemID = (LPDWORD)((DWORD)KnapBase + 0xC);		// ��ƷID
	LPDWORD ItemNum = (LPDWORD)((DWORD)KnapBase + 0x20);	// ��Ʒ����
	LPDWORD ItemUseLV = (LPDWORD)((DWORD)KnapBase + 0x8C);	// ��Ʒʹ�õȼ�(����Ʒ)

	LPWSTR ItemNumOrName = (LPWSTR)(*(LPDWORD)((DWORD)KnapBase + 0x58) + 0xE); // ָ����Ʒ����/˵��
	LPWSTR ItemTypeName = (LPWSTR)(*(LPDWORD)((DWORD)KnapBase + 0x78) + 0x4);	// ��Ʒ��������
}KNAPSACK, * PKNAPSACK;


// ��Χ�����Ϣ�ṹ
typedef struct _PLAYER
{
	LPDWORD PlayBase;
	PFLOAT PlayCoorX = (PFLOAT)((DWORD)PlayBase + 0x3C);		// ���X����
	PFLOAT PlayCoorZ = (PFLOAT)((DWORD)PlayBase + 0x40);		// ���Z����
	PFLOAT PlayCoorY = (PFLOAT)((DWORD)PlayBase + 0x44);		// ���Y����
	LPDWORD PlayLV = (LPDWORD)((DWORD)PlayBase + 0x28C);		// ��ҵȼ�
	LPDWORD PlayHP = (LPDWORD)((DWORD)PlayBase + 0x29C);		// ��ҵ�ǰѪ��
	LPDWORD PlayMP = (LPDWORD)((DWORD)PlayBase + 0x2A0);		// ��ҵ�ǰ����
	LPDWORD PlayMaxHP = (LPDWORD)((DWORD)PlayBase + 0x2BD);		// ������Ѫ��
	LPDWORD PlayMaxMP = (LPDWORD)((DWORD)PlayBase + 0x2C1);		// ����������
	LPWSTR PlayName = (LPWSTR)(*(LPDWORD)(*(LPDWORD)(*(LPDWORD)((DWORD)PlayBase + 0x9E0) + 0xC) + 0) + 0); // �������

}PLAYER, *PLAYERS;

typedef struct _AUTOCALL
{
	GAMEBASECALL GameBase;
	DWORD GetRoleCall = (DWORD)GameBase.GetRoleBase;		// ��ȡ�����ַCALL
	DWORD GetGameCall = (DWORD)GameBase.GetGameBase;		// ��ȡ��Ϸ��ַCALL
	DWORD GetNpMoCall = (DWORD)GameBase.GetNpMoBase;		// ��ȡ��ϷNPC/����/������Ʒ�Ļ�ַCALL
	DWORD GetFuncCall = (DWORD)GameBase.GetFuncBase;		// ��ȡ��Ϸ������ַCALL


	// ʹ�ñ�����Ʒ(��Ʒ�ڱ������±�)
	VOID CALLBACK UseKnapItem(UINT ItmeIndex)
	{
		DWORD CALLGetRole = GetRoleCall;
		DWORD CallBackOne = 0x48B920;

		__asm	call CALLGetRole			// ��ȡ�����ַ
		__asm	mov ecx, eax
		__asm	push ItmeIndex			// ��Ʒ�ڱ�������
		__asm	push 0					// ����
		__asm	call CallBackOne

		Sleep(200);
	}

	// �ƶ�������Ʒ(Ҫ������λ��, ��ǰλ��, ������{ ��ͨ������Ʒ 0   ���ﱳ����Ʒ 7} )
	VOID CALLBACK MovKNAPItem(UINT NewIndex, UINT OldIndex, UINT KnapNum=0)
	{								
		DWORD CallBackOne = 0x7A4F40;
		__asm
		{
			push KnapNum
			push NewIndex
			push OldIndex
			mov ecx, dword ptr ds:[0xE52264]		// ָ��ASCII "0��"
			call CallBackOne
		}
		Sleep(200);
	}

	// ����()
	VOID CALLBACK Medita()
	{
		DWORD CallBackOne = 0x7E14A0;
		__asm
		{
			call CallBackOne;
		}
		Sleep(200);
	}

	// ȡ������()
	VOID CALLBACK UnMedita()
	{
		DWORD CallBackOne = 0x7E1460;
		__asm
		{
			call CallBackOne
		}
		Sleep(200);
	}

	// ��NPC�Ի���(NPC��ϵͳ�ϵ�ID)
	// ��NPC 5M�ķ�Χ�ڴ�
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

	// �ر�NPC�Ի���
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

	// �����̵���Ʒ����ƷID, ��Ʒ���̵��λ��, ����������  --- ��Ҫ��NPC�Ի������ܹ���
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

	// ����������Ʒ(��ƷID, ��Ʒ�ڱ������±�, ��������)
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

	// ���ݵ�����ƷIDʰȡ��Ʒ(������Ʒ�ڷ������ϵ�ID, ��Ʒ��ID)
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

	// ������������Ʒ()
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

	// ����������Ʒ(��Ʒ�ڱ�����λ��, ��������)
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

	// ʹ��Tab�����ѡ��
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

	// ͨ������IDѡ�����
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

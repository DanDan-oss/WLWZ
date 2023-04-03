;.380
.model flat, C

.data
GetRoleCall dword 0055E3C0h
GetGameCall dword 0055E380h
GetNpMoCall dword 0055E390h
GetFuncCall dword 0055E3A0h

.code

asmUseKnapItem proc	; 使用背包物品(物品在背包的下标)
	push ebp
	mov ebp, esp
	sub esp, 8h

	mov eax, GetRoleCall
	mov dword ptr ds:[ebp-4], eax
	mov dword ptr ds:[ebp-8], 0048B920h

	call dword ptr ds:[ebp-4]
	mov ecx, eax
	push dowrd ptr ds:[ebp+8]
	call dword ptr ds:[ebp-8]

	mov esp, ebp
	pop ebp
	ret 4
asmUseKnapItem endp


end
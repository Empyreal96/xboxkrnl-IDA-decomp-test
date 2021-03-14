char __usercall SwapContext@<al>(int *a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  unsigned int v3; // et0
  bool v4; // zf
  unsigned __int32 v5; // ebp
  int v6; // eax
  unsigned int v7; // ecx
  char result; // al
  int v9; // [esp-8h] [ebp-8h]
  unsigned int v10; // [esp-4h] [ebp-4h]

  *(_BYTE *)(a3 + 44) = 2;
  v3 = __readeflags();
  v10 = v3;
  v4 = a1[22] == 0;
  v9 = *a1;
  if ( !v4 )
    KeBugCheck(0xB8u);
  if ( KiDbgCtxSwapNotify )
    KiDbgCtxSwapNotify(*(void **)(a2 + 300), *(void **)(a3 + 300));
  v5 = __readcr0();
  _disable();
  *(_DWORD *)(a2 + 36) = &v9;
  v6 = *(_DWORD *)(a3 + 28) - 528;
  a1[2] = *(_DWORD *)(a3 + 32);
  a1[1] = v6;
  v7 = *(_DWORD *)(v6 + 512) | v5 & 0xFFFFFFF1 | *(unsigned __int8 *)(a3 + 48);
  if ( v5 != v7 )
  {
    JUMPOUT(*(_BYTE *)(a3 + 48) & 0xF5, 0, &sc_error);
    JUMPOUT(*(_DWORD *)(v6 + 512) & 0xFFFFFFF0, 0, &sc_error3);
    __writecr0(v7);
  }
  _enable();
  ++*(_DWORD *)(a3 + 76);
  ++a1[18];
  *a1 = v9;
  if ( *(_BYTE *)(a3 + 73) )
  {
    __writeeflags(v10);
    if ( v4 )
    {
      result = 1;
    }
    else
    {
      HalRequestSoftwareInterrupt(1);
      result = 0;
    }
  }
  else
  {
    __writeeflags(v10);
    result = 0;
  }
  return result;
}
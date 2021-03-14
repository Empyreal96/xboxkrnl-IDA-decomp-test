unsigned int __usercall KiRetireDpcList@<eax>(_DWORD *a1@<ebx>, _DWORD **a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  _DWORD *v5; // edx
  _DWORD *v6; // ecx
  int v7; // edx
  void (*v8)(void); // ecx
  unsigned __int32 v9; // eax
  unsigned int result; // eax
  unsigned __int32 v11; // eax
  void (*v12)(void); // esi
  int v13; // [esp-18h] [ebp-18h]
  int v14; // [esp-14h] [ebp-14h]
  int v15; // [esp-10h] [ebp-10h]
  int v16; // [esp-Ch] [ebp-Ch]
  int v17; // [esp-8h] [ebp-8h]
  int v18; // [esp-4h] [ebp-4h]
  void *retaddr; // [esp+0h] [ebp+0h]

  if ( !thread->NpxState )
  {
    _EAX = __readcr0();
    LOWORD(_EAX) = _EAX | 0xA;
    __asm { lmsw    ax }
  }
  do
  {
    dword_8004C604 = (int)&retaddr;
    do
    {
      v5 = *a2;
      v6 = (_DWORD *)**a2;
      *a2 = v6;
      v6[1] = a2;
      v7 = (int)(v5 - 1);
      v8 = *(void (**)(void))(v7 + 12);
      v18 = *(_DWORD *)(v7 + 12);
      v17 = a3;
      v16 = a4;
      v15 = *(_DWORD *)(v7 + 24);
      v14 = *(_DWORD *)(v7 + 20);
      v13 = *(_DWORD *)(v7 + 16);
      *(_BYTE *)(v7 + 2) = 0;
      unk_8004C5F0 = 0;
      _enable();
      if ( KiDpcDispatchNotify )
      {
        v12 = v8;
        ((void (__fastcall *)(void (*)(void), _DWORD, int, int, int, int))KiDpcDispatchNotify)(v8, 0, v7, v13, v14, v15);
        v12();
        ((void (__fastcall *)(void (*)(void), signed int))KiDpcDispatchNotify)(v12, 1);
      }
      else
      {
        ((void (__stdcall *)(int, int, int, int))v8)(v7, v13, v14, v15);
      }
      a4 = v16;
      v9 = __readcr0();
      if ( !(v9 & 8) )
      {
        DbgPrint(&v17, "\n*** DPC routine %p returned with the FPU enabled\n", v18);
        __debugbreak();
      }
      result = (unsigned __int8)dword_8004C5D0;
      if ( (_BYTE)dword_8004C5D0 != 2 )
        KeBugCheckEx(9u, (unsigned int)a1, (unsigned __int8)dword_8004C5D0, 0, 0);
      if ( &v17 != &v17 )
      {
        result = DbgPrint(&v17, "\n*** DPC routine %p trashed ESP\n", v18);
        __debugbreak();
      }
      a3 = v17;
      _disable();
    }
    while ( a2 != *a2 );
    a1[22] = 0;
    a1[19] = 0;
  }
  while ( a2 != *a2 );
  if ( !thread->NpxState )
  {
    v11 = __readcr0();
    result = *(_DWORD *)(a1[1] + 512) | v11 & 0xFFFFFFF1;
    __asm { lmsw    ax }
  }
  return result;
}
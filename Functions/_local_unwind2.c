int __usercall _local_unwind2@<eax>(unsigned int a1@<ebp>, int a2, int a3)
{
  int result; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // esi

  while ( 1 )
  {
    result = a2;
    v4 = *(_DWORD *)(a2 + 8);
    v5 = *(_DWORD *)(a2 + 12);
    if ( v5 == -1 || v5 == a3 )
      break;
    v6 = 3 * v5;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(v4 + 4 * v6);
    if ( !*(_DWORD *)(v4 + 4 * v6 + 4) )
    {
      _NLG_Notify(*(_DWORD *)(v4 + 4 * v6 + 8), a1, 0x101u);
      (*(void (**)(void))(v4 + 4 * v6 + 8))();
    }
  }
  return result;
}
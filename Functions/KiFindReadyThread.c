_KTHREAD *__fastcall KiFindReadyThread(int LowPriority)
{
  signed int v1; // eax
  signed int v2; // ecx
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx
  int v6; // esi
  int v7; // ecx
  signed int v8; // eax
  int *v9; // edi
  _KTHREAD *result; // eax
  int *v11; // ebx
  int v12; // ecx
  int *v13; // edx

  v1 = 1 << LowPriority;
  v2 = 16;
  v3 = KiReadySummary & ~(v1 - 1);
  v4 = v3 >> 16;
  if ( !(v3 >> 16) )
  {
    v2 = 0;
    v4 = v3;
  }
  if ( v4 & 0xFFFFFF00 )
    v2 += 8;
  v5 = v3 >> v2;
  if ( (v3 >> v2) & 0xF0 )
  {
    v5 >>= 4;
    v2 += 4;
  }
  v6 = v2 + (unsigned __int8)KiFindLeftNibbleBitTable[v5];
  v7 = 31 - v6;
  v8 = v3 << (31 - v6);
  v9 = (int *)(8 * v6 - 2147151840);
  if ( !v8 )
    return 0;
  while ( v8 >= 0 )
  {
    --v6;
    v9 -= 2;
    v8 *= 2;
    if ( !v8 )
      return 0;
  }
  v11 = (int *)*v9;
  if ( (int *)*v9 == v9 )
    RtlAssert(v5, v7, v9, v6, "NextEntry != ListHead", "d:\\xbox-apr03\\private\\ntos\\ke\\thredsup.c", 0x96u, 0);
  result = (_KTHREAD *)(v11 - 23);
  v12 = *v11;
  v13 = (int *)v11[1];
  *v13 = *v11;
  *(_DWORD *)(v12 + 4) = v13;
  if ( (int *)*v9 == v9 )
    KiReadySummary &= ~(1 << v6);
  return result;
}
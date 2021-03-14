int __stdcall RtlCompareMemoryUlong(char *a1, unsigned int a2, int a3)
{
  char *v3; // edi
  bool v4; // zf
  unsigned int v5; // ecx

  v3 = a1;
  if ( (unsigned __int8)a1 & 3 )
  {
    DbgPrint((int *)a1, "RTL: RtlCompare/FillMemoryUlong called with unaligned pointer (%x)\\n", a1);
    if ( KdDebuggerEnabled )
      DbgBreakPoint();
  }
  v5 = a2 >> 2;
  v4 = a2 >> 2 == 0;
  do
  {
    if ( !v5 )
      break;
    v4 = *(_DWORD *)v3 == a3;
    v3 += 4;
    --v5;
  }
  while ( v4 );
  if ( !v4 )
    v3 -= 4;
  return v3 - a1;
}
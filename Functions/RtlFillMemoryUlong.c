int __stdcall RtlFillMemoryUlong(int *a1, unsigned int a2, int a3)
{
  int result; // eax

  if ( (unsigned __int8)a1 & 3 )
  {
    DbgPrint(a1, "RTL: RtlCompare/FillMemoryUlong called with unaligned pointer (%x)\\n", a1);
    if ( KdDebuggerEnabled )
      DbgBreakPoint();
  }
  result = a3;
  memset32(a1, a3, a2 >> 2);
  return result;
}
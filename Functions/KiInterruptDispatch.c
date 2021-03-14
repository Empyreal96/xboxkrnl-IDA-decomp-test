int __usercall KiInterruptDispatch@<eax>(int *a1@<edi>)
{
  unsigned int v1; // eax
  int v2; // ebx
  unsigned int v3; // eax
  volatile unsigned int v4; // ebx

  ++unk_8004C5E4;
  (*(void (__fastcall **)(int, int))(4 * a1[2] - 2147173488))(a1[2], a1[3]);
  v1 = KeTickCount & 0xFFFFFFE0;
  v2 = 2 * a1[2];
  if ( (KeTickCount & 0xFFFFFFE0) == KiInterruptCounts[v2] )
  {
    v3 = KiISROverflow;
    if ( ++dword_80050DC4[v2] < v3 )
      goto kid_dbg2;
    DbgPrint(a1, "\n*** ISR at %lx - %d interrupts per .5 second\n", *a1, dword_80050DC4[v2]);
    __debugbreak();
    v1 = KeTickCount & 0xFFFFFFE0;
  }
  KiInterruptCounts[v2] = v1;
  dword_80050DC4[v2] = 0;
kid_dbg2:
  v4 = KeTickCount;
  ((void (__stdcall *)(int *, int))*a1)(a1, a1[1]);
  if ( KeTickCount >= KiISRTimeout + v4 )
  {
    DbgPrint(a1, "\n*** ISR at %lx took over .5 second\n", *a1);
    __debugbreak();
  }
  _disable();
  return HalEndSystemInterrupt(0);
}
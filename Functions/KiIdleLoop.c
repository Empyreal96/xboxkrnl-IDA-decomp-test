void __usercall __noreturn KiIdleLoop(int a1@<edi>, int a2@<esi>)
{
  unsigned int *v2; // ebp

  v2 = &KiPCR + 20;
  while ( 1 )
  {
    _enable();
    _disable();
    if ( v2 != (unsigned int *)*v2 )
    {
      HalClearSoftwareInterrupt(2);
      KiRetireDpcList(&KiPCR, (_DWORD **)v2, a1, a2);
    }
    if ( *(&KiPCR + 11) )
    {
      _enable();
      a2 = *(&KiPCR + 11);
      a1 = *(&KiPCR + 10);
      *(&KiPCR + 11) = 0;
      *(&KiPCR + 10) = a2;
      SwapContext((int *)&KiPCR, a1, a2);
      v2 = &KiPCR + 20;
    }
  }
}
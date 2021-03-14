void __usercall __noreturn KeRetireDpcListLoop(int a1@<edi>, int a2@<esi>)
{
  unsigned int *v2; // ebp

  v2 = &KiPCR + 20;
  *(&KiPCR + 22) = 0;
  while ( 1 )
  {
    do
    {
      _enable();
      _disable();
    }
    while ( v2 == (unsigned int *)*v2 );
    HalClearSoftwareInterrupt(2);
    KiRetireDpcList(&KiPCR, (_DWORD **)v2, a1, a2);
  }
}
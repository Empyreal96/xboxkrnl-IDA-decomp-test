void __stdcall KiEspToTrapFrame(_KTRAP_FRAME *TrapFrame, unsigned int Esp)
{
  unsigned int *v2; // eax
  _DWORD *v3; // edx
  int v4; // ecx

  v2 = KiEspFromTrapFrame(TrapFrame);
  if ( Esp < (unsigned int)v2 )
    KeBugCheck(0x30u);
  v4 = v3[16];
  if ( v4 & 0xFFF8 )
  {
    if ( v2 == (unsigned int *)Esp )
      return;
    v3[4] = v4;
    v3[16] = v4 & 0xFFFF0007;
  }
  v3[5] = Esp;
}
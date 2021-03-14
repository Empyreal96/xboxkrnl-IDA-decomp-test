void KiTrap08()
{
  unsigned __int8 (__stdcall *v0)(int); // eax
  int v1; // ST10_4
  unsigned int v2; // et0

  _disable();
  v0 = *(unsigned __int8 (__stdcall **)(int))&ListHead.Depth;
  if ( *(_DWORD *)&ListHead.Depth )
  {
    *(_DWORD *)&ListHead.Depth = 0;
    v1 = *(_DWORD *)&KiGDT[*(unsigned __int16 *)KiDoubleFaultTSS + 2];
    HIBYTE(v1) = KiGDT[*(unsigned __int16 *)KiDoubleFaultTSS + 7];
    if ( v0(v1) )
      __asm { iret }
  }
  byte_8005FBD5 = -119;
  v2 = __readeflags();
  __writeeflags(v2 & 0xFFFFBFFF);
  KeBugCheckEx(0x7Fu, 8u, 0, 0, 0);
}
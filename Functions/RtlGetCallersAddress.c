void __stdcall RtlGetCallersAddress(PVOID *CallersAddress, PVOID *CallersCaller)
{
  void *v2; // esi
  void *v3; // edi
  unsigned int v4; // edx
  unsigned int v5; // [esp-8h] [ebp-1Ch]
  void *v6; // [esp-4h] [ebp-18h]
  void **v7; // [esp+0h] [ebp-14h]
  unsigned int *v8; // [esp+4h] [ebp-10h]
  unsigned int *savedregs; // [esp+14h] [ebp+0h]

  v8 = (unsigned int *)thread->StackBase;
  v7 = (void **)&v8;
  v6 = &RgcaFault;
  v5 = KiPCR;
  KiPCR = (unsigned int)&v5;
  v2 = 0;
  v3 = 0;
  if ( savedregs > (unsigned int *)&savedregs )
  {
    if ( savedregs < v8 && savedregs >= thread->StackLimit
      || dword_8004C604
      && (v8 = (unsigned int *)dword_8004C608, (unsigned int)savedregs < dword_8004C608)
      && (unsigned int)savedregs > dword_8004C608 - 12288 )
    {
      v2 = (void *)savedregs[1];
      v4 = *savedregs;
      if ( *savedregs > (unsigned int)&savedregs && v4 < (unsigned int)v8 )
        v3 = *(void **)(v4 + 4);
    }
  }
  if ( CallersAddress )
    *CallersAddress = v2;
  if ( CallersCaller )
    *CallersCaller = v3;
  KiPCR = v5;
}
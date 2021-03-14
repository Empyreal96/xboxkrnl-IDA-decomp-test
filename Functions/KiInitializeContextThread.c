void __stdcall KiInitializeContextThread(_KTHREAD *Thread, unsigned int TlsDataSize, void (__stdcall *SystemRoutine)(void (__stdcall *)(void *), void *), void (__stdcall *StartRoutine)(void *), void *StartContext)
{
  _DWORD *v5; // edx
  unsigned int v6; // ecx
  char *v7; // edx
  char *v8; // eax

  v5 = (char *)Thread->StackBase - 528;
  memset(v5, 0, 0x210u);
  v6 = (TlsDataSize + 3) & 0xFFFFFFFC;
  *(_WORD *)v5 = 639;
  v5[6] = 8064;
  v7 = (char *)v5 - v6;
  Thread->NpxState = 10;
  if ( v6 )
  {
    Thread->TlsData = v7;
    memset(v7, 0, v6);
  }
  else
  {
    Thread->TlsData = 0;
  }
  *((_DWORD *)v7 - 1) = StartContext;
  *((_DWORD *)v7 - 2) = StartRoutine;
  v8 = v7 - 24;
  *((_DWORD *)v7 - 3) = SystemRoutine;
  *(_DWORD *)v8 = -1;
  *((_DWORD *)v8 + 2) = &KiThreadStartup;
  *((_DWORD *)v8 + 1) = 512;
  Thread->KernelStack = v7 - 24;
}
void __stdcall KeContextToKframes(_KTRAP_FRAME *TrapFrame, _CONTEXT *ContextFrame, unsigned int ContextFlags)
{
  unsigned int v3; // ebx
  int v4; // eax

  v3 = ContextFlags;
  if ( (ContextFlags & 0x10001) == 65537 )
  {
    TrapFrame->EFlags = ContextFrame->EFlags & 0x3E0FD7;
    TrapFrame->Ebp = ContextFrame->Ebp;
    TrapFrame->Eip = ContextFrame->Eip;
    KiEspToTrapFrame(TrapFrame, ContextFrame->Esp);
  }
  if ( (v3 & 0x10002) == 65538 )
  {
    TrapFrame->Edi = ContextFrame->Edi;
    TrapFrame->Esi = ContextFrame->Esi;
    TrapFrame->Ebx = ContextFrame->Ebx;
    TrapFrame->Ecx = ContextFrame->Ecx;
    TrapFrame->Edx = ContextFrame->Edx;
    TrapFrame->Eax = ContextFrame->Eax;
  }
  if ( (ContextFrame->ContextFlags & 0x10008) == 65544 || (ContextFrame->ContextFlags & 0x10020) == 65568 )
  {
    KiFlushNPXState();
    v4 = dword_8004C5B0;
    qmemcpy((void *)dword_8004C5B0, &ContextFrame->FloatSave, 0x204u);
    *(_DWORD *)(v4 + 512) &= 0xFFFFFFF1;
    *(_DWORD *)(v4 + 24) &= 0xFFBFu;
  }
}
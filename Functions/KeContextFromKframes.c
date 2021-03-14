void __stdcall KeContextFromKframes(_KTRAP_FRAME *TrapFrame, _CONTEXT *ContextFrame)
{
  unsigned int v2; // edx
  _KTRAP_FRAME *v3; // ecx
  unsigned int v4; // eax

  v2 = ContextFrame->ContextFlags;
  v3 = TrapFrame;
  if ( (ContextFrame->ContextFlags & 0x10001) == 65537 )
  {
    ContextFrame->Ebp = TrapFrame->Ebp;
    ContextFrame->Eip = TrapFrame->Eip;
    v4 = TrapFrame->SegCs;
    if ( !(v4 & 0xFFF8) && !(TrapFrame->EFlags & 0x20000) )
      v4 = TrapFrame->TempSegCs;
    ContextFrame->SegCs = (unsigned __int16)v4;
    ContextFrame->EFlags = TrapFrame->EFlags;
    ContextFrame->SegSs = 16;
    ContextFrame->Esp = (unsigned int)KiEspFromTrapFrame(TrapFrame);
  }
  if ( (v2 & 0x10002) == 65538 )
  {
    ContextFrame->Edi = v3->Edi;
    ContextFrame->Esi = v3->Esi;
    ContextFrame->Ebx = v3->Ebx;
    ContextFrame->Ecx = v3->Ecx;
    ContextFrame->Edx = v3->Edx;
    ContextFrame->Eax = v3->Eax;
  }
  if ( (v2 & 0x10008) == 65544 || (v2 & 0x10020) == 65568 )
  {
    KiFlushNPXState();
    qmemcpy(&ContextFrame->FloatSave, (const void *)dword_8004C5B0, sizeof(ContextFrame->FloatSave));
  }
}
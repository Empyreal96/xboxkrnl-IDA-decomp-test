void __stdcall KdpContextToNt5Context(_CONTEXT *Context, _X86_NT5_CONTEXT *Nt5Context)
{
  unsigned int v2; // ecx
  _DWORD *v3; // eax
  char *v4; // edx
  signed int v5; // ecx
  _WORD *v6; // edi
  _WORD *v7; // esi

  Nt5Context->ContextFlags = Context->ContextFlags;
  Nt5Context->Ebp = Context->Ebp;
  Nt5Context->Eip = Context->Eip;
  Nt5Context->SegCs = Context->SegCs;
  Nt5Context->EFlags = Context->EFlags;
  Nt5Context->Esp = Context->Esp;
  v2 = Context->SegSs;
  Nt5Context->SegGs = 0;
  Nt5Context->SegSs = v2;
  Nt5Context->SegFs = 32;
  Nt5Context->SegEs = 16;
  Nt5Context->SegDs = 16;
  Nt5Context->Edi = Context->Edi;
  Nt5Context->Esi = Context->Esi;
  Nt5Context->Ebx = Context->Ebx;
  Nt5Context->Edx = Context->Edx;
  Nt5Context->Ecx = Context->Ecx;
  Nt5Context->Eax = Context->Eax;
  qmemcpy(Nt5Context->ExtendedRegisters, &Context->FloatSave, sizeof(Nt5Context->ExtendedRegisters));
  Nt5Context->FloatSave.ControlWord = Context->FloatSave.ControlWord;
  Nt5Context->FloatSave.StatusWord = Context->FloatSave.StatusWord;
  Nt5Context->FloatSave.TagWord = Context->FloatSave.TagWord;
  Nt5Context->FloatSave.ErrorOffset = Context->FloatSave.ErrorOffset;
  Nt5Context->FloatSave.ErrorSelector = Context->FloatSave.ErrorSelector;
  Nt5Context->FloatSave.DataOffset = Context->FloatSave.DataOffset;
  Nt5Context->FloatSave.DataSelector = Context->FloatSave.DataSelector;
  Nt5Context->FloatSave.Cr0NpxState = Context->FloatSave.Cr0NpxState;
  v3 = Nt5Context->FloatSave.RegisterArea;
  v4 = Context->FloatSave.RegisterArea;
  v5 = 8;
  do
  {
    *v3 = *(_DWORD *)v4;
    v3[1] = *((_DWORD *)v4 + 1);
    v7 = v4 + 8;
    v6 = v3 + 2;
    v4 += 16;
    v3 = (_DWORD *)((char *)v3 + 10);
    --v5;
    *v6 = *v7;
  }
  while ( v5 );
}
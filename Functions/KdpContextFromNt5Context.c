void __stdcall KdpContextFromNt5Context(_CONTEXT *Context, _X86_NT5_CONTEXT *Nt5Context)
{
  char *v2; // ecx
  _DWORD *v3; // eax
  signed int v4; // edx
  _WORD *v5; // edi
  _WORD *v6; // esi

  Context->ContextFlags = Nt5Context->ContextFlags;
  Context->Ebp = Nt5Context->Ebp;
  Context->Eip = Nt5Context->Eip;
  Context->SegCs = Nt5Context->SegCs;
  Context->EFlags = Nt5Context->EFlags;
  Context->Esp = Nt5Context->Esp;
  Context->SegSs = Nt5Context->SegSs;
  Context->Edi = Nt5Context->Edi;
  Context->Esi = Nt5Context->Esi;
  Context->Ebx = Nt5Context->Ebx;
  Context->Edx = Nt5Context->Edx;
  Context->Ecx = Nt5Context->Ecx;
  Context->Eax = Nt5Context->Eax;
  qmemcpy(&Context->FloatSave, Nt5Context->ExtendedRegisters, 0x200u);
  Context->FloatSave.ControlWord = Nt5Context->FloatSave.ControlWord;
  Context->FloatSave.StatusWord = Nt5Context->FloatSave.StatusWord;
  Context->FloatSave.TagWord = Nt5Context->FloatSave.TagWord;
  Context->FloatSave.ErrorOffset = Nt5Context->FloatSave.ErrorOffset;
  Context->FloatSave.ErrorSelector = Nt5Context->FloatSave.ErrorSelector;
  Context->FloatSave.DataOffset = Nt5Context->FloatSave.DataOffset;
  Context->FloatSave.DataSelector = Nt5Context->FloatSave.DataSelector;
  Context->FloatSave.Cr0NpxState = Nt5Context->FloatSave.Cr0NpxState;
  v2 = Context->FloatSave.RegisterArea;
  v3 = Nt5Context->FloatSave.RegisterArea;
  v4 = 8;
  do
  {
    *(_DWORD *)v2 = *v3;
    *((_DWORD *)v2 + 1) = v3[1];
    v6 = v3 + 2;
    v5 = v2 + 8;
    v3 = (_DWORD *)((char *)v3 + 10);
    v2 += 16;
    --v4;
    *v5 = *v6;
  }
  while ( v4 );
}
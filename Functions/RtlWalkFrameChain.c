unsigned int __stdcall RtlWalkFrameChain(void **Callers, unsigned int Count, unsigned int Flags, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, int a48, int a49, int a50, int a51, int a52, int a53, int a54, int a55, int a56, int a57, int a58, int a59, int a60, int a61, int a62, int a63)
{
  unsigned int *v65; // esi
  unsigned int v66; // edi
  unsigned int i; // edx
  int *v68; // eax
  int savedregs; // [esp+34h] [ebp+0h]

  v65 = (unsigned int *)&savedregs;
  v66 = (unsigned int)thread->StackBase;
  if ( (unsigned int)&savedregs > v66 || (v66 & 0xFFFFF000) - ((unsigned int)&savedregs & 0xFFFFF000) > 0x1000 )
  {
    v66 = (unsigned int)&a65 & 0xFFFFF000;
    if ( MmIsAddressValid((void *)((unsigned int)&a65 & 0xFFFFF000)) )
      v66 += 4096;
  }
  for ( i = 0; i < Count; ++i )
  {
    if ( (unsigned int)(v65 + 1) >= v66 )
      break;
    v68 = (int *)v65[1];
    if ( (unsigned int)v65 >= *v65 || *v65 >= v66 || &savedregs < v68 && (unsigned int)v68 < v66 )
      break;
    if ( (unsigned int)v68 < 0x10000 )
      break;
    v65 = (unsigned int *)*v65;
    Callers[i] = v68;
  }
  return i;
}
int __userpurge NtContinue@<eax>(int a1@<esi>, _CONTEXT *ContextRecord, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34)
{
  int v34; // edx
  int v35; // ecx
  _KTRAP_FRAME *TrapFrame; // [esp+0h] [ebp+0h]

  if ( !KiContinue(ContextRecord, 0, TrapFrame) )
  {
    if ( (_BYTE)a3 )
      KeTestAlertThread(v34, v35, a1, 0);
    JUMPOUT(&KiServiceExit2);
  }
  return KiServiceExit(
           ContextRecord,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34);
}
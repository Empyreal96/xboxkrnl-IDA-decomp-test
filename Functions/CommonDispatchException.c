int __usercall CommonDispatchException@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<ebx>, _KTRAP_FRAME *a5@<ebp>, int a6@<edi>, int a7@<esi>, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25)
{
  int v26; // [esp+0h] [ebp-50h]
  int v27; // [esp+4h] [ebp-4Ch]
  int v28; // [esp+8h] [ebp-48h]
  int v29; // [esp+Ch] [ebp-44h]
  int v30; // [esp+10h] [ebp-40h]
  int v31; // [esp+14h] [ebp-3Ch]
  int v32; // [esp+18h] [ebp-38h]
  int v33; // [esp+1Ch] [ebp-34h]

  v26 = a1;
  v27 = 0;
  v28 = 0;
  v29 = a4;
  v30 = a3;
  if ( a3 )
  {
    v31 = a2;
    v32 = a7;
    v33 = a6;
  }
  KiDispatchException((_EXCEPTION_RECORD *)&v26, 0, a5, 1);
  return KiExceptionExit(a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25);
}
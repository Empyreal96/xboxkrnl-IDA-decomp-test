int __usercall KiRaiseExceptionService@<eax>(_CONTEXT *ContextRecord@<ecx>, int FirstChance@<edx>, _EXCEPTION_RECORD *a3@<eax>, int a4@<ebx>, int a5@<ebp>, int a6@<edi>, int a7@<esi>, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40)
{
  int v41; // [esp-3Ch] [ebp-3Ch]
  void *v42; // [esp-38h] [ebp-38h]
  signed int v43; // [esp-34h] [ebp-34h]
  int v44; // [esp-30h] [ebp-30h]
  unsigned int v45; // [esp-18h] [ebp-18h]
  int v46; // [esp-14h] [ebp-14h]
  int v47; // [esp-10h] [ebp-10h]
  int v48; // [esp-Ch] [ebp-Ch]
  int v49; // [esp-8h] [ebp-8h]
  int v50; // [esp-4h] [ebp-4h]
  void *retaddr; // [esp+0h] [ebp+0h]

  v50 = 0;
  v49 = a5;
  v48 = a4;
  v47 = a7;
  v46 = a6;
  v45 = KiPCR;
  KiPCR = -1;
  v44 = FirstChance;
  v43 = -1160049408;
  v41 = a5;
  v42 = retaddr;
  _enable();
  NtRaiseException(a3, ContextRecord, FirstChance);
  return KiServiceExit(
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
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40);
}
int __usercall KiTrap10@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<ebx>, int a5@<ebp>, int a6@<edi>, int a7@<esi>, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25)
{
  int v26; // [esp-3Ah] [ebp-3Ch]
  void *v27; // [esp-36h] [ebp-38h]
  signed int v28; // [esp-32h] [ebp-34h]
  int v29; // [esp-2Eh] [ebp-30h]
  int v30; // [esp-22h] [ebp-24h]
  int v31; // [esp-1Eh] [ebp-20h]
  int v32; // [esp-1Ah] [ebp-1Ch]
  unsigned int v33; // [esp-16h] [ebp-18h]
  int v34; // [esp-12h] [ebp-14h]
  int v35; // [esp-Eh] [ebp-10h]
  int v36; // [esp-Ah] [ebp-Ch]
  int v37; // [esp-6h] [ebp-8h]
  int v38; // [esp-2h] [ebp-4h]
  void *retaddr; // [esp+2h] [ebp+0h]

  v38 = 0;
  HIWORD(v38) = 0;
  v37 = a5;
  v36 = a4;
  v35 = a7;
  v34 = a6;
  v33 = KiPCR;
  v32 = a1;
  v31 = a3;
  v30 = a2;
  v29 = a2;
  v28 = -1160049408;
  v26 = a5;
  v27 = retaddr;
  JUMPOUT(BugCheckParameter2, thread, &Kt0710);
  *(_DWORD *)(*(_DWORD *)(BugCheckParameter2 + 28) - 528 + 512) |= 8u;
  return KiExceptionExit(a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25);
}
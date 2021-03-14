int __usercall KiTrap05@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<ebx>, int a5@<ebp>, int a6@<edi>, int a7@<esi>, int a8, int a9)
{
  int v10; // [esp-2Eh] [ebp-30h]
  int v11; // [esp-22h] [ebp-24h]
  int v12; // [esp-1Eh] [ebp-20h]
  int v13; // [esp-1Ah] [ebp-1Ch]
  unsigned int v14; // [esp-16h] [ebp-18h]
  int v15; // [esp-12h] [ebp-14h]
  int v16; // [esp-Eh] [ebp-10h]
  int v17; // [esp-Ah] [ebp-Ch]
  int v18; // [esp-6h] [ebp-8h]
  int v19; // [esp-2h] [ebp-4h]

  v19 = 0;
  HIWORD(v19) = 0;
  v18 = a5;
  v17 = a4;
  v16 = a7;
  v15 = a6;
  v14 = KiPCR;
  v13 = a1;
  v12 = a3;
  v11 = a2;
  v10 = a2;
  _enable();
  return CommonDispatchException0Args(a8, a9);
}
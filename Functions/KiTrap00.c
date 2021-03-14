int __usercall KiTrap00@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<ebx>, int a5@<ebp>, int a6@<edi>, int a7@<esi>, int a8, int a9)
{
  int v10; // [esp-3Ah] [ebp-3Ch]
  unsigned int v11; // [esp-36h] [ebp-38h]
  signed int v12; // [esp-32h] [ebp-34h]
  int v13; // [esp-2Eh] [ebp-30h]
  int v14; // [esp-22h] [ebp-24h]
  int v15; // [esp-1Eh] [ebp-20h]
  int v16; // [esp-1Ah] [ebp-1Ch]
  unsigned int v17; // [esp-16h] [ebp-18h]
  int v18; // [esp-12h] [ebp-14h]
  int v19; // [esp-Eh] [ebp-10h]
  int v20; // [esp-Ah] [ebp-Ch]
  int v21; // [esp-6h] [ebp-8h]
  int v22; // [esp-2h] [ebp-4h]
  unsigned int retaddr; // [esp+2h] [ebp+0h]

  v22 = 0;
  HIWORD(v22) = 0;
  v21 = a5;
  v20 = a4;
  v19 = a7;
  v18 = a6;
  v17 = KiPCR;
  v16 = a1;
  v15 = a3;
  v14 = a2;
  v13 = a2;
  v12 = -1160049408;
  v10 = a5;
  v11 = retaddr;
  if ( !(a9 & 0x200) )
    KeBugCheckEx(0xAu, 0, 0xFFFFFFFF, 0, retaddr);
  _enable();
  Ki386CheckDivideByZeroTrap((_KTRAP_FRAME *)&v10);
  return CommonDispatchException0Args(a8, a9);
}
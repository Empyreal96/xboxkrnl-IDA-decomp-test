void __fastcall WriteMVReg(int a1, int a2, void *RegisterBase, char Reg, char Val)
{
  int v5; // esi
  int v6; // edx
  int v7; // ecx
  int *v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // esi

  v5 = AvpDump;
  AvpDump = 0;
  HalWriteSMBusValue(a2, a1, (int *)(unsigned __int8)Reg, v5, TVEncoderSMBusID, 12, 1, (unsigned __int8)Reg);
  AvpDump = v5;
  if ( v5 )
    DbgPrint((int *)(unsigned __int8)Reg, "TV%04X = %04X\n", 12, (unsigned __int8)Reg);
  v8 = (int *)AvpDump;
  AvpDump = 0;
  HalWriteSMBusValue(v6, v7, v8, (unsigned __int8)Val, TVEncoderSMBusID, 13, 1, (unsigned __int8)Val);
  AvpDump = (unsigned int)v8;
  if ( v8 )
    DbgPrint(v8, "TV%04X = %04X\n", 13, (unsigned __int8)Val);
  v11 = AvpDump;
  AvpDump = 0;
  HalWriteSMBusValue(v9, v10, v8, v11, TVEncoderSMBusID, 14, 1, 1u);
  AvpDump = v11;
  if ( v11 )
    DbgPrint(v8, "TV%04X = %04X\n", 14, 1);
}
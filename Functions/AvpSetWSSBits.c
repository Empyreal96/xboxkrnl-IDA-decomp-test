void __userpurge AvpSetWSSBits(int a1@<edx>, int *a2@<edi>, int a3@<esi>, void *RegisterBase)
{
  int v4; // ecx
  unsigned int v5; // ebx
  void *v6; // esi
  char Val; // ST18_1
  int *v8; // edi
  unsigned int v9; // ebx
  int v10; // esi
  unsigned int v11; // ebx

  v4 = 0;
  if ( AvpCurrentMode & 0xC0000000 )
  {
    if ( (AvpCurrentMode & 0xC0000000) != 0x40000000 )
      return;
    v5 = (AvpCGMS << 12) | (8 - ((AvpCurrentMode & 0x10000000) != 0));
  }
  else
  {
    if ( AvpCurrentMode & 0x10000000 )
      v4 = 1;
    v5 = AvpCalcWSSCRC(v4 | ((AvpCGMS | 2 * (AvpMacrovisionMode & 2 | 4 * (AvpMacrovisionMode & 1))) << 6));
  }
  if ( TVEncoderSMBusID == -44 )
  {
    v6 = RegisterBase;
    Val = v5 & 0xF;
    SMB_WR(a2, (int)RegisterBase, RegisterBase, 133, v5 & 0xF);
    v8 = (int *)(v5 >> 4);
    SMB_WR((int *)(v5 >> 4), (int)v6, v6, 132, v5 >> 4);
    v9 = v5 >> 12;
    SMB_WR(v8, (int)v6, v6, 131, v9);
    SMB_WR(v8, (int)v6, v6, 136, Val);
    SMB_WR(v8, (int)v6, v6, 135, (char)v8);
    SMB_WR(v8, (int)v6, v6, 134, v9);
  }
  else if ( TVEncoderSMBusID == -32 )
  {
    v10 = AvpDump;
    AvpDump = 0;
    v11 = 2 * (v5 & 0xFFFFF | 0x1800000);
    HalWriteSMBusValue(a1, v4, a2, v10, 224, 7, 1, v11);
    AvpDump = v10;
    if ( v10 )
      DbgPrint(a2, "TV%04X = %04X\n", 7, v11);
  }
  else
  {
    SMB_WR(a2, a3, RegisterBase, 96, v5 & 0xF | 0xC0);
    SMB_WR(a2, a3, RegisterBase, 98, v5 >> 4);
    SMB_WR(a2, a3, RegisterBase, 100, v5 >> 12);
  }
}
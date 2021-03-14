void __userpurge AvpEnableSCART(int a1@<edx>, int a2@<ecx>, int a3@<esi>, void *RegisterBase, unsigned int iTV)
{
  int v5; // ecx
  char *v6; // esi
  int v7; // edx
  char *v8; // ecx
  int *v9; // edi
  char v10; // al
  unsigned int v11; // ebx
  unsigned int v12; // ebx
  unsigned int v13; // esi
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // esi
  int v20; // edx
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  int v24; // esi
  char *v25; // esi
  int *v26; // edi
  char *v27; // ebx
  const char *pByteMax; // [esp+Ch] [ebp-Ch]
  unsigned int DataValue; // [esp+10h] [ebp-8h]
  char CommandCode[4]; // [esp+14h] [ebp-4h]

  if ( TVEncoderSMBusID == -44 )
  {
    v5 = AvpTableRowSize[7];
    v6 = &AV_TABLE_SCARTENABLE_DATA[2 * v5];
    v7 = (int)&v6[v5];
    v8 = &AV_TABLE_SCARTENABLE_DATA[v5];
    pByteMax = (const char *)v7;
    v9 = (int *)AV_TABLE_SCARTENABLE_DATA;
    iTV = (unsigned int)v8;
    if ( (unsigned int)v6 < v7 )
    {
      do
      {
        v10 = *(_BYTE *)v9;
        v11 = AvpDump;
        AvpDump = 0;
        CommandCode[0] = v10;
        HalReadSMBusValue(v7, (int)v8, v9, (int)v6, TVEncoderSMBusID, v10, 0, &DataValue);
        AvpDump = v11;
        SMB_WR(v9, (int)v6, RegisterBase, *(_BYTE *)v9, *v6 | DataValue & ~*(_BYTE *)iTV);
        ++v6;
        v9 = (int *)((char *)v9 + 1);
        ++iTV;
      }
      while ( v6 < pByteMax );
    }
  }
  else if ( TVEncoderSMBusID == -32 )
  {
    v12 = AvpDump;
    AvpDump = 0;
    HalReadSMBusValue(a1, a2, (int *)1, a3, 224, 1, 1, (unsigned int *)&RegisterBase);
    AvpDump = 0;
    v13 = (unsigned int)RegisterBase & 0xFCFFFFFF | 0xC00008;
    HalWriteSMBusValue(v14, v15, (int *)1, v13, TVEncoderSMBusID, 1, 1, v13);
    AvpDump = v12;
    if ( v12 )
      DbgPrint((int *)1, "TV%04X = %04X\n", 1, v13);
    v18 = AvpDump;
    AvpDump = 0;
    iTV = v18;
    HalReadSMBusValue(v16, v17, (int *)1, v13, TVEncoderSMBusID, 96, 1, (unsigned int *)&RegisterBase);
    AvpDump = 0;
    v19 = (unsigned int)RegisterBase & 0xFEFFFFFF;
    HalWriteSMBusValue(
      v20,
      v21,
      (int *)1,
      (unsigned int)RegisterBase & 0xFEFFFFFF,
      TVEncoderSMBusID,
      96,
      1,
      (unsigned int)RegisterBase & 0xFEFFFFFF);
    AvpDump = iTV;
    if ( iTV )
      DbgPrint((int *)1, "TV%04X = %04X\n", 96, v19);
    v24 = AvpDump;
    AvpDump = 0;
    HalWriteSMBusValue(v22, v23, (int *)1, v24, TVEncoderSMBusID, 88, 1, 0);
    AvpDump = v24;
    if ( v24 )
      DbgPrint((int *)1, "TV%04X = %04X\n", 88, 0);
  }
  else
  {
    v25 = &AV_TABLE_SCARTENABLE_DATA[iTV * AvpTableRowSize[7]];
    v26 = (int *)&v25[AvpTableRowSize[7]];
    v27 = AV_TABLE_SCARTENABLE_DATA;
    while ( v25 < (char *)v26 )
    {
      SMB_WR(v26, (int)v25, RegisterBase, *v27, *v25);
      ++v25;
      ++v27;
    }
  }
}
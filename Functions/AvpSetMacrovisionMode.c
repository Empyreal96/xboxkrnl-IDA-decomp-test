void __fastcall AvpSetMacrovisionMode(unsigned int a1, int a2, void *RegisterBase, unsigned int MacrovisionMode)
{
  unsigned int v4; // eax
  char v5; // dl
  int v6; // ecx
  char *v7; // eax
  char *v8; // esi
  int v9; // esi
  char *v10; // edi
  int v11; // esi
  int v12; // ebx
  int *v13; // edi
  int v14; // esi
  int v15; // ebx
  int *v16; // edi
  int v17; // edx
  int v18; // ecx
  __int16 v19; // ax
  unsigned __int16 v20; // ax
  int v21; // ebx
  int v22; // eax
  int v23; // ecx
  char *v24; // edi
  int v25; // edi
  char *v26; // esi
  int v27; // edi
  int v28; // ebx
  char *v29; // esi
  int *v30; // edi
  int v31; // ebx
  unsigned int v32; // esi
  int *v33; // edi
  unsigned int DataValue; // [esp+0h] [ebp-4h]

  DataValue = a1;
  v4 = AvpCurrentMode & 0xC0000000;
  if ( AvpCurrentMode & 0xC0000000 && v4 != 0x40000000 )
    return;
  v5 = TVEncoderSMBusID;
  if ( TVEncoderSMBusID == -32 && !MacrovisionMode )
  {
    WriteMVReg(a1, TVEncoderSMBusID, RegisterBase, 15, 0);
    return;
  }
  if ( v4 )
  {
    v23 = AvpTableRowSize[4];
    v24 = &AV_TABLE_MACROVISIONPAL_DATA[2 * v23];
    if ( !MacrovisionMode )
      v24 = &AV_TABLE_MACROVISIONPAL_DATA[v23];
    if ( TVEncoderSMBusID == -32 )
    {
      v25 = (int)&v24[-v23];
      if ( AvpTableRowSize[4] )
      {
        v26 = AV_TABLE_MACROVISIONPAL_DATA;
        v27 = v25 - (_DWORD)AV_TABLE_MACROVISIONPAL_DATA;
        v28 = AvpTableRowSize[4];
        do
        {
          WriteMVReg(v23, v5, RegisterBase, *v26, v26[v27]);
          ++v26;
          --v28;
        }
        while ( v28 );
      }
    }
    else if ( AvpTableRowSize[4] )
    {
      v29 = AV_TABLE_MACROVISIONPAL_DATA;
      v30 = (int *)(v24 - AV_TABLE_MACROVISIONPAL_DATA);
      v31 = AvpTableRowSize[4];
      do
      {
        SMB_WR(v30, (int)v29, RegisterBase, *v29, *((_BYTE *)v30 + (_DWORD)v29));
        ++v29;
        --v31;
      }
      while ( v31 );
    }
    v22 = 3;
    goto LABEL_40;
  }
  if ( MacrovisionMode )
  {
    if ( MacrovisionMode == 1 )
    {
      v6 = AvpTableRowSize[3];
      v7 = AV_TABLE_MACROVISION_DATA;
      v8 = &AV_TABLE_MACROVISION_DATA[2 * v6];
    }
    else
    {
      v6 = AvpTableRowSize[3];
      v7 = AV_TABLE_MACROVISION_DATA;
      if ( MacrovisionMode == 2 )
        v8 = &AV_TABLE_MACROVISION_DATA[2 * v6 + v6];
      else
        v8 = &AV_TABLE_MACROVISION_DATA[4 * v6];
    }
  }
  else
  {
    v6 = AvpTableRowSize[3];
    v7 = AV_TABLE_MACROVISION_DATA;
    v8 = &AV_TABLE_MACROVISION_DATA[v6];
  }
  if ( TVEncoderSMBusID != -32 )
  {
    if ( v6 )
    {
      v13 = (int *)v7;
      v14 = v8 - v7;
      v15 = v6;
      do
      {
        SMB_WR(v13, v14, RegisterBase, *(_BYTE *)v13, *((_BYTE *)v13 + v14));
        v13 = (int *)((char *)v13 + 1);
        --v15;
      }
      while ( v15 );
    }
    goto LABEL_22;
  }
  v9 = (int)&v8[-v6];
  if ( v6 )
  {
    v10 = v7;
    v11 = v9 - (_DWORD)v7;
    v12 = v6;
    do
    {
      WriteMVReg(v6, v5, RegisterBase, *v10, v10[v11]);
      ++v10;
      --v12;
    }
    while ( v12 );
LABEL_22:
    if ( TVEncoderSMBusID == -44 )
    {
      v16 = (int *)AvpDump;
      AvpDump = 0;
      HalReadSMBusValue(v5, v6, v16, 178, 212, 178, 1, &DataValue);
      v19 = DataValue & 0xC000;
      v20 = MacrovisionMode ? v19 | 0x34D : v19 | 0x555;
      AvpDump = 0;
      v21 = v20;
      HalWriteSMBusValue(v17, v18, v16, 178, TVEncoderSMBusID, 178, 1, v20);
      AvpDump = (unsigned int)v16;
      if ( v16 )
        DbgPrint(v16, "TV%04X = %04X\n", 178, v21);
    }
  }
  v22 = (XboxGameRegion == 2) + 1;
LABEL_40:
  if ( TVEncoderSMBusID == -44 )
  {
    v32 = 0;
    if ( !MacrovisionMode )
      v22 += 3;
    v33 = (int *)(6 * v22 - 2147379332 - (_DWORD)"NOPQ^_8");
    do
    {
      SMB_WR(v33, v32, RegisterBase, Focus_MacrovisionHamp[0][v32], Focus_MacrovisionHamp[0][v32 + (_DWORD)v33]);
      ++v32;
    }
    while ( v32 < 6 );
  }
}
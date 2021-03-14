void __userpurge SMB_WR(int *a1@<edi>, int a2@<esi>, void *Ptr, char Reg, char Val)
{
  unsigned int v5; // eax
  int v6; // edx
  char v7; // al
  _FILTER_TABLES *v8; // ecx
  signed int v9; // ebx
  unsigned int v10; // eax
  signed int v11; // ebx
  unsigned int v12; // eax
  signed int v13; // ebx
  unsigned int v14; // eax
  unsigned int v15; // eax
  int v16; // edx
  _FILTER_TABLES *v17; // ecx
  unsigned int v18; // eax
  int v19; // ecx
  unsigned int v20; // eax
  _FILTER_TABLES *v21; // edx
  unsigned int v22; // eax
  unsigned int v23; // eax
  char v24; // [esp-Ch] [ebp-18h]
  char v25; // [esp-8h] [ebp-14h]
  unsigned int v26; // [esp-4h] [ebp-10h]
  unsigned int Store; // [esp+8h] [ebp-4h]

  v5 = AvpDump;
  v6 = 0;
  AvpDump = 0;
  Store = v5;
  v7 = TVEncoderSMBusID;
  v8 = (_FILTER_TABLES *)224;
  if ( TVEncoderSMBusID != -32 )
  {
    v19 = (unsigned __int8)Val;
    v26 = (unsigned __int8)Val;
    v25 = 0;
    v24 = Reg;
    goto LABEL_57;
  }
  if ( AvpCurrentMode & 0x20000000 )
    v6 = 2;
  a2 = 1;
  if ( AvpLumaFilter )
    v6 |= 1u;
  if ( (signed int)(unsigned __int8)Reg > 61 )
  {
    if ( (signed int)(unsigned __int8)Reg < 67 )
      goto LABEL_55;
    if ( (signed int)(unsigned __int8)Reg <= 68 )
    {
      v21 = (_FILTER_TABLES *)(v6 & 1);
      if ( (_FILTER_TABLES *)((unsigned __int8)Reg - 67) != v21 )
        goto LABEL_58;
      if ( Val )
      {
        v21 = AV_TABLE_FILTER_DATA;
        v22 = AV_TABLE_FILTER_DATA->BandpassChromaTable[4][2 * (unsigned __int8)Val + 1];
      }
      else
      {
        v22 = 0;
      }
      HalWriteSMBusValue((int)v21, 224, a1, 1, 224, 67, 1, v22);
      if ( Val )
      {
        v19 = (int)AV_TABLE_FILTER_DATA;
        v23 = AV_TABLE_FILTER_DATA->BandpassChromaTable[4][2 * (unsigned __int8)Val + 2];
      }
      else
      {
        v23 = 0;
      }
      v26 = v23;
      v25 = 1;
      v24 = 68;
    }
    else
    {
      if ( Reg != 70 )
        goto LABEL_55;
      if ( Val )
      {
        v6 = (int)AV_TABLE_FILTER_DATA;
        v15 = AV_TABLE_FILTER_DATA->BandpassChromaTable[(unsigned __int8)Val - 1][0];
      }
      else
      {
        v15 = 0;
      }
      HalWriteSMBusValue(v6, 224, a1, 1, 224, 70, 1, v15);
      if ( Val )
      {
        v17 = AV_TABLE_FILTER_DATA;
        v18 = AV_TABLE_FILTER_DATA->BandpassChromaTable[(unsigned __int8)Val][-2];
      }
      else
      {
        v18 = 0;
      }
      HalWriteSMBusValue(v16, (int)v17, a1, 1, TVEncoderSMBusID, 71, 1, v18);
      if ( Val )
      {
        v19 = (int)AV_TABLE_FILTER_DATA;
        v20 = AV_TABLE_FILTER_DATA->BandpassChromaTable[(unsigned __int8)Val][-1];
      }
      else
      {
        v20 = 0;
      }
      v26 = v20;
      v25 = 1;
      v24 = 72;
    }
    v7 = TVEncoderSMBusID;
LABEL_57:
    HalWriteSMBusValue(v6, v19, a1, a2, v7, v24, v25, v26);
    goto LABEL_58;
  }
  if ( (signed int)(unsigned __int8)Reg >= 58 )
  {
    if ( (unsigned __int8)Reg - 58 == v6 )
    {
      v13 = 0;
      do
      {
        if ( Val )
        {
          v8 = AV_TABLE_FILTER_DATA;
          v14 = AV_TABLE_FILTER_DATA->BasebandChromaTable[6][v13 + 8 * (unsigned __int8)Val];
        }
        else
        {
          v14 = 0;
        }
        HalWriteSMBusValue(v6, (int)v8, a1, 1, TVEncoderSMBusID, v13++ + 58, 1, v14);
      }
      while ( v13 < 8 );
    }
  }
  else
  {
    if ( (signed int)(unsigned __int8)Reg < 32 )
      goto LABEL_55;
    if ( (signed int)(unsigned __int8)Reg > 35 )
    {
      if ( (signed int)(unsigned __int8)Reg > 48 && (signed int)(unsigned __int8)Reg <= 52 )
      {
        if ( (unsigned __int8)Reg - 49 == v6 )
        {
          v9 = 0;
          do
          {
            if ( Val )
            {
              v8 = AV_TABLE_FILTER_DATA;
              v10 = AV_TABLE_FILTER_DATA->ComponentChromaTable[9][v9 + 8 * (unsigned __int8)Val];
            }
            else
            {
              v10 = 0;
            }
            HalWriteSMBusValue(v6, (int)v8, a1, 1, TVEncoderSMBusID, v9++ + 49, 1, v10);
          }
          while ( v9 < 8 );
        }
        goto LABEL_58;
      }
LABEL_55:
      HalWriteSMBusValue((int)AV_TABLE_LOOKUP_DATA, 224, a1, 1, 224, Reg, 1, AV_TABLE_LOOKUP_DATA[(unsigned __int8)Val]);
      goto LABEL_58;
    }
    if ( (unsigned __int8)Reg - 32 == v6 )
    {
      v11 = 0;
      do
      {
        if ( Val )
        {
          v8 = AV_TABLE_FILTER_DATA;
          v12 = AV_TABLE_FILTER_DATA->ComponentLumaTable[14][v11 + 16 * (unsigned __int8)Val];
        }
        else
        {
          v12 = 0;
        }
        HalWriteSMBusValue(v6, (int)v8, a1, 1, TVEncoderSMBusID, v11++ + 32, 1, v12);
      }
      while ( v11 < 16 );
    }
  }
LABEL_58:
  AvpDump = Store;
  if ( Store )
    DbgPrint(a1, "TV%02X = %02X\n", (unsigned __int8)Reg, (unsigned __int8)Val);
}
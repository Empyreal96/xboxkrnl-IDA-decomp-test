char *__usercall AvpInitCurrentTVEncoder@<eax>(int *a1@<edi>)
{
  char *v1; // esi
  int v2; // edi
  char *v3; // edi
  unsigned __int16 *v4; // eax
  unsigned int v5; // edx
  char *v6; // ecx
  char *v7; // ecx
  char *v8; // ecx
  char *v9; // ecx
  char *v10; // ecx
  char *v11; // ecx
  char *v12; // ecx
  char *v13; // ecx
  char *v14; // ecx
  unsigned int *v15; // edi
  char *result; // eax
  unsigned int TableSize; // [esp+8h] [ebp-8h]
  unsigned int v18; // [esp+Ch] [ebp-4h]

  v1 = (char *)MmMapAvTables(a1, &TableSize);
  if ( XboxHardwareInfo.Flags & 0x20 )
  {
    DbgPrint(a1, "AV: Focus TV encoder\n");
    TVEncoderSMBusID = -44;
    v2 = *((_DWORD *)v1 + 1);
  }
  else if ( XboxHardwareInfo.Flags & 0x400 )
  {
    DbgPrint(a1, "AV: XCalibur TV encoder\n");
    TVEncoderSMBusID = -32;
    v2 = *((_DWORD *)v1 + 2);
  }
  else
  {
    DbgPrint(a1, "AV: Conexant TV encoder\n");
    TVEncoderSMBusID = -118;
    v2 = *(_DWORD *)v1;
  }
  v3 = &v1[v2];
  v4 = (unsigned __int16 *)&v1[*((_DWORD *)v3 + 10)];
  AvpTableRowSize = (unsigned __int16 *)&v1[*((_DWORD *)v3 + 10)];
  AV_TABLE_COMMONTVREGISTERS_DATA = &v1[*(_DWORD *)v3];
  if ( AV_TABLE_COMMONTVREGISTERS_DATA < v1 )
    goto LABEL_49;
  v5 = (unsigned int)&v1[TableSize];
  v18 = (unsigned int)&v1[TableSize];
  if ( AV_TABLE_COMMONTVREGISTERS_DATA > &v1[TableSize] )
    goto LABEL_49;
  v6 = &AV_TABLE_COMMONTVREGISTERS_DATA[*v4 + 2];
  if ( v6 < v1 )
    goto LABEL_49;
  if ( (unsigned int)v6 > v5 )
    goto LABEL_49;
  AV_TABLE_TVREGISTERS_DATA = &v1[*((_DWORD *)v3 + 1)];
  if ( AV_TABLE_TVREGISTERS_DATA < v1 )
    goto LABEL_49;
  if ( (unsigned int)AV_TABLE_TVREGISTERS_DATA > v5 )
    goto LABEL_49;
  v7 = &AV_TABLE_TVREGISTERS_DATA[(TVEncoderSMBusID != -32 ? 30 : 36) + v4[1]];
  if ( v7 < v1 )
    goto LABEL_49;
  if ( (unsigned int)v7 > v18 )
    goto LABEL_49;
  AV_TABLE_HDTVREGISTERS_DATA = &v1[*((_DWORD *)v3 + 2)];
  if ( AV_TABLE_HDTVREGISTERS_DATA < v1 )
    goto LABEL_49;
  if ( (unsigned int)AV_TABLE_HDTVREGISTERS_DATA > v18 )
    goto LABEL_49;
  v8 = &AV_TABLE_HDTVREGISTERS_DATA[v4[2] + 4];
  if ( v8 < v1 )
    goto LABEL_49;
  if ( (unsigned int)v8 > v18 )
    goto LABEL_49;
  AV_TABLE_MACROVISION_DATA = &v1[*((_DWORD *)v3 + 3)];
  if ( AV_TABLE_MACROVISION_DATA < v1 )
    goto LABEL_49;
  if ( (unsigned int)AV_TABLE_MACROVISION_DATA > v18 )
    goto LABEL_49;
  v9 = &AV_TABLE_MACROVISION_DATA[v4[3] + 5];
  if ( v9 < v1 )
    goto LABEL_49;
  if ( (unsigned int)v9 > v18 )
    goto LABEL_49;
  AV_TABLE_MACROVISIONPAL_DATA = &v1[*((_DWORD *)v3 + 4)];
  if ( AV_TABLE_MACROVISIONPAL_DATA < v1 )
    goto LABEL_49;
  if ( (unsigned int)AV_TABLE_MACROVISIONPAL_DATA > v18 )
    goto LABEL_49;
  v10 = &AV_TABLE_MACROVISIONPAL_DATA[v4[4] + 3];
  if ( v10 < v1 )
    goto LABEL_49;
  if ( (unsigned int)v10 > v18 )
    goto LABEL_49;
  AV_TABLE_DACREGISTERS_DATA = &v1[*((_DWORD *)v3 + 5)];
  if ( AV_TABLE_DACREGISTERS_DATA < v1 )
    goto LABEL_49;
  if ( (unsigned int)AV_TABLE_DACREGISTERS_DATA > v18 )
    goto LABEL_49;
  v11 = &AV_TABLE_DACREGISTERS_DATA[v4[5] + 19];
  if ( v11 < v1 )
    goto LABEL_49;
  if ( (unsigned int)v11 > v18 )
    goto LABEL_49;
  AV_TABLE_CRTCREGISTERS_DATA = &v1[*((_DWORD *)v3 + 6)];
  if ( AV_TABLE_CRTCREGISTERS_DATA < v1 )
    goto LABEL_49;
  if ( (unsigned int)AV_TABLE_CRTCREGISTERS_DATA > v18 )
    goto LABEL_49;
  v12 = &AV_TABLE_CRTCREGISTERS_DATA[v4[6] + 17];
  if ( v12 < v1
    || (unsigned int)v12 > v18
    || (AV_TABLE_SCARTENABLE_DATA = &v1[*((_DWORD *)v3 + 7)], AV_TABLE_SCARTENABLE_DATA < v1)
    || (unsigned int)AV_TABLE_SCARTENABLE_DATA > v18
    || (v13 = &AV_TABLE_SCARTENABLE_DATA[(TVEncoderSMBusID != -118 ? 3 : 30) + v4[7]], v13 < v1)
    || (unsigned int)v13 > v18
    || (AV_TABLE_FILTER_DATA = (_FILTER_TABLES *)&v1[*((_DWORD *)v3 + 8)], AV_TABLE_FILTER_DATA < (_FILTER_TABLES *)v1)
    || (unsigned int)AV_TABLE_FILTER_DATA > v18
    || (v14 = (char *)&AV_TABLE_FILTER_DATA->BandpassChromaTable[0][0] + v4[8] + 1, v14 < v1)
    || (unsigned int)v14 > v18
    || (v15 = (unsigned int *)&v1[*((_DWORD *)v3 + 9)], AV_TABLE_LOOKUP_DATA = v15, v15 < (unsigned int *)v1)
    || (unsigned int)v15 > v18
    || (result = (char *)v15 + v4[9] + 1, result < v1)
    || (unsigned int)result > v18 )
  {
LABEL_49:
    KeBugCheck(0);
  }
  return result;
}
void __userpurge AvpCommitMacrovisionMode(int a1@<edx>, int a2@<ecx>, const char *a3@<esi>, void *RegisterBase, unsigned int MacrovisionMode)
{
  int *v5; // edi
  bool v6; // zf
  int v7; // esi
  int v8; // edx
  int v9; // ecx
  unsigned __int16 v10; // ax
  unsigned int v11; // edi
  unsigned int DataValue; // [esp+Ch] [ebp-8h]
  int ModeIs480p; // [esp+10h] [ebp-4h]

  v5 = (int *)(AvpCurrentMode & 0xC0000000);
  ModeIs480p = (AvpCurrentMode & 0xFF0000FF) == -2013265919;
  if ( TVEncoderSMBusID == -44 )
  {
    a3 = (const char *)AvpDump;
    AvpDump = 0;
    HalReadSMBusValue(a1, a2, v5, (int)a3, 212, 52, 1, &DataValue);
    v6 = (DataValue & 0x8000) == 0;
  }
  else
  {
    if ( TVEncoderSMBusID != -118 )
      goto LABEL_10;
    a3 = (const char *)AvpDump;
    AvpDump = 0;
    HalReadSMBusValue(a1, a2, v5, (int)a3, 138, 0, 0, &DataValue);
    v6 = (DataValue & 0xE0) == 64;
  }
  AvpDump = (unsigned int)a3;
  if ( v6 )
  {
    *((_BYTE *)RegisterBase + 787396) = 1;
    a3 = "%08X = %08X\n";
    if ( AvpDump )
      DbgPrint(v5, "%08X = %08X\n", 787396, 1);
    *((_BYTE *)RegisterBase + 787397) = 33;
    if ( AvpDump )
      DbgPrint(v5, "%08X = %08X\n", 787397, 33);
  }
LABEL_10:
  if ( TVEncoderSMBusID == -44 )
  {
    if ( !v5 || v5 == (int *)0x40000000 || ModeIs480p )
    {
      v7 = AvpDump;
      AvpDump = 0;
      HalReadSMBusValue(a1, a2, v5, v7, 212, 14, 1, (unsigned int *)&RegisterBase);
      AvpDump = 0;
      if ( MacrovisionMode )
        v10 = (unsigned __int16)RegisterBase | 0x8000;
      else
        v10 = (unsigned __int16)RegisterBase & 0x7FFF;
      v11 = v10;
      HalWriteSMBusValue(v8, v9, (int *)v11, v7, TVEncoderSMBusID, 14, 1, v11);
      AvpDump = v7;
      if ( v7 )
        DbgPrint((int *)v11, "TV%04X = %04X\n", 14, v11);
    }
  }
  else if ( TVEncoderSMBusID == -32 )
  {
    if ( !v5 || v5 == (int *)0x40000000 || ModeIs480p )
    {
      if ( MacrovisionMode )
      {
        if ( MacrovisionMode == 1 )
          LOBYTE(MacrovisionMode) = 54;
        else
          LOBYTE(MacrovisionMode) = 62;
        if ( ModeIs480p )
          LOBYTE(MacrovisionMode) = 36;
      }
      else
      {
        LOBYTE(MacrovisionMode) = 0;
      }
      WriteMVReg(a2, a1, RegisterBase, 15, MacrovisionMode);
    }
  }
  else if ( !v5 || ModeIs480p )
  {
    if ( MacrovisionMode )
    {
      if ( MacrovisionMode == 1 )
        LOBYTE(MacrovisionMode) = 99;
      else
        LOBYTE(MacrovisionMode) = -29;
      if ( ModeIs480p )
        LOBYTE(MacrovisionMode) = 66;
    }
    else
    {
      LOBYTE(MacrovisionMode) = 0;
    }
    SMB_WR(v5, (int)a3, RegisterBase, 252, MacrovisionMode);
  }
}
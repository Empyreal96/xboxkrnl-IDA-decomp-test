void __fastcall IdexDiskSecurityUnlock(int a1, int a2, char *Password)
{
  int *v3; // edi
  int v4; // esi
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // ST1C_4
  int v9; // edx
  int v10; // ecx
  unsigned __int8 v11; // al
  int *v12; // [esp+0h] [ebp-418h]
  signed int v13; // [esp+4h] [ebp-414h]
  _IDE_IDENTIFY_DATA IdentifyData; // [esp+8h] [ebp-410h]
  _IDE_SECURITY_DATA SecurityData; // [esp+208h] [ebp-210h]
  _ATA_PASS_THROUGH AtaPassThrough; // [esp+408h] [ebp-10h]

  memset(&SecurityData, 0, sizeof(SecurityData));
  qmemcpy(SecurityData.Password, Password, sizeof(SecurityData.Password));
  *(_DWORD *)&AtaPassThrough.IdeReg.bFeaturesReg = 0;
  *(_DWORD *)&AtaPassThrough.IdeReg.bCylHighReg = 0;
  v3 = (int *)&AtaPassThrough.DataBufferSize;
  v4 = 0;
  AtaPassThrough.DataBuffer = &SecurityData;
  AtaPassThrough.IdeReg.bCommandReg = -14;
  AtaPassThrough.IdeReg.bHostSendsData = 1;
  AtaPassThrough.DataBufferSize = 512;
  v5 = IoSynchronousDeviceIoControlRequest(
         0,
         a2,
         0x4D028u,
         IdexDiskPartitionArray[0],
         &AtaPassThrough,
         0x10u,
         &AtaPassThrough,
         0x10u,
         0,
         0);
  if ( v5 >= 0 )
  {
    if ( !(AtaPassThrough.IdeReg.bCommandReg & 1) )
    {
      IdexDiskSecurityUnlocked = 1;
      goto LABEL_7;
    }
    v5 = -1073741435;
  }
  DbgPrint((int *)&AtaPassThrough.DataBufferSize, "IDEX: hard disk failed to unlock (status=%08x).\n", v5);
  v7 = v8;
  if ( (XboxGameRegion & 0x80000000) == 0 )
LABEL_10:
    IdexDiskFatalError(v3, v4, v13);
LABEL_7:
  v3 = v12;
  v4 = v13;
  if ( (signed int)IdexChannelIdentifyDevice(v6, v7, (int *)&AtaPassThrough.DataBufferSize, 0, 0, 236, &IdentifyData) < 0
    || (signed int)IdexDiskSetDeviceParameters(v9, v10, v12, v13) < 0 )
  {
    v11 = __inbyte(0x1F7u);
    DbgPrint(v12, "IDEX: hard disk not found (status=%02x).\n", v11);
    v13 = 8;
    goto LABEL_10;
  }
}
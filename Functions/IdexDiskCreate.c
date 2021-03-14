void __usercall IdexDiskCreate(_LARGE_INTEGER *a1@<edi>)
{
  int v1; // edx
  int v2; // ecx
  int v3; // edx
  int v4; // ecx
  unsigned __int8 v5; // al
  int v6; // edx
  int v7; // ecx
  unsigned __int8 v8; // al
  int v9; // edx
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  unsigned __int8 v13; // al
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  _IDE_IDENTIFY_DATA IdentifyData; // [esp+8h] [ebp-228h]
  char Password[32]; // [esp+208h] [ebp-28h]
  _LARGE_INTEGER Interval; // [esp+228h] [ebp-8h]

  HalPulseHardwareMonitorPin();
  if ( !(XboxBootFlags & 1) )
  {
    a1 = (_LARGE_INTEGER *)600;
    do
    {
      if ( IdexDiskPollResetComplete() )
        break;
      Interval.QuadPart = -500000i64;
      KeDelayExecutionThread(v2, v1, 0, 0, &Interval);
      a1 = (_LARGE_INTEGER *)((char *)a1 - 1);
    }
    while ( a1 );
    if ( !a1 )
    {
      DbgPrint(0, "IDEX: hard disk timed out during reset.\n");
      IdexDiskFatalError(0, 0, 7u);
    }
  }
  HalPulseHardwareMonitorPin();
  if ( (signed int)IdexChannelSetTransferMode(v3, v4, (int *)a1, 0, 0, 12) < 0 )
  {
    v5 = __inbyte(0x1F7u);
    DbgPrint((int *)a1, "IDEX: hard disk not PIO configured (status=%02x).\n", v5);
    goto LABEL_18;
  }
  HalPulseHardwareMonitorPin();
  if ( (signed int)IdexChannelSetTransferMode(v6, v7, (int *)a1, 0, 0, 66) < 0 )
  {
    v8 = __inbyte(0x1F7u);
    DbgPrint((int *)a1, "IDEX: hard disk not DMA configured (status=%02x).\n", v8);
LABEL_18:
    IdexDiskFatalError((int *)a1, 0, 9u);
  }
  HalPulseHardwareMonitorPin();
  if ( (signed int)IdexChannelIdentifyDevice(v9, v10, (int *)a1, 0, 0, 236, &IdentifyData) < 0 )
  {
    v13 = __inbyte(0x1F7u);
    DbgPrint((int *)a1, "IDEX: hard disk not found (status=%02x).\n", v13);
    IdexDiskFatalError((int *)a1, 0, 8u);
  }
  IdexDiskInitIdentifierString(
    v11,
    v12,
    (int *)a1,
    0,
    IdentifyData.ModelNumber,
    IdexDiskModelNumberBuffer,
    0x28u,
    &HalDiskModelNumber);
  IdexDiskInitIdentifierString(
    v14,
    v15,
    (int *)a1,
    0,
    IdentifyData.SerialNumber,
    IdexDiskSerialNumberBuffer,
    0x14u,
    &HalDiskSerialNumber);
  if ( IdentifyData.UserAddressableSectors < 0xEE8AB0 )
  {
    DbgPrint((int *)a1, "IDEX: hard disk too small.\n");
    goto LABEL_18;
  }
  IdexDiskUserAddressableSectors = IdentifyData.UserAddressableSectors;
  IdexDiskCreateQuick((int *)a1);
  HalPulseHardwareMonitorPin();
  if ( *((_BYTE *)&IdentifyData + 256) & 2 )
  {
    if ( *((_BYTE *)&IdentifyData + 256) & 4 )
    {
      memset(Password, 0, sizeof(Password));
      a1 = &Interval;
      XcHMAC(
        XboxHDKey,
        0x10u,
        HalDiskModelNumber.Buffer,
        HalDiskModelNumber.Length,
        HalDiskSerialNumber.Buffer,
        HalDiskSerialNumber.Length,
        Password);
      IdexDiskSecurityUnlock(v17, v16, Password);
    }
    else
    {
      IdexDiskSecurityUnlocked = 1;
    }
  }
  else
  {
    DbgPrint((int *)a1, "IDEX: hard disk is not locked.\n");
  }
  HalPulseHardwareMonitorPin();
  IdexDiskIncrementPowerCycleCount(v18, v19, (int *)a1);
}
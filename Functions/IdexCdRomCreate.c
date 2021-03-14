void __usercall IdexCdRomCreate(int *a1@<edi>, int a2@<esi>)
{
  int v2; // edx
  int v3; // ecx
  int v4; // edx
  int v5; // ecx
  unsigned __int8 v6; // al
  int v7; // edx
  int v8; // ecx
  unsigned __int8 v9; // al
  int v10; // edx
  int v11; // ecx
  unsigned __int8 v12; // al
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // esi
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  _IDE_IDENTIFY_DATA IdentifyData; // [esp+8h] [ebp-208h]
  _LARGE_INTEGER Interval; // [esp+208h] [ebp-8h]

  HalPulseHardwareMonitorPin();
  if ( !(XboxBootFlags & 1) )
  {
    a2 = 600;
    do
    {
      if ( IdexCdRomPollResetComplete() )
        break;
      Interval.QuadPart = -500000i64;
      KeDelayExecutionThread(v3, v2, 0, 0, &Interval);
      --a2;
    }
    while ( a2 );
    if ( !a2 )
    {
      DbgPrint(a1, "IDEX: CD-ROM timed out during reset.\n");
      IdexCdRomFatalError(a1, 0, 0xAu);
    }
  }
  HalPulseHardwareMonitorPin();
  if ( (signed int)IdexChannelSetTransferMode(v4, v5, a1, a2, 1, 12) < 0 )
  {
    v6 = __inbyte(0x1F7u);
    DbgPrint(a1, "IDEX: CD-ROM not PIO configured (status=%02x).\n", v6);
    goto LABEL_10;
  }
  HalPulseHardwareMonitorPin();
  if ( (signed int)IdexChannelSetTransferMode(v7, v8, a1, a2, 1, 66) < 0 )
  {
    v9 = __inbyte(0x1F7u);
    DbgPrint(a1, "IDEX: CD-ROM not DMA configured (status=%02x).\n", v9);
LABEL_10:
    IdexCdRomFatalError(a1, a2, 0xCu);
  }
  HalPulseHardwareMonitorPin();
  if ( (signed int)IdexChannelIdentifyDevice(v10, v11, a1, a2, 1, 161, &IdentifyData) < 0 )
  {
    v12 = __inbyte(0x1F7u);
    DbgPrint(a1, "IDEX: CD-ROM not found (status=%02x).\n", v12);
    IdexCdRomFatalError(a1, a2, 0xBu);
  }
  IdexCdRomCreateQuick(a1);
  HalPulseHardwareMonitorPin();
  if ( !KeHasQuickBooted && !(XboxBootFlags & 0x40) )
  {
    v15 = 0;
    do
    {
      v16 = IoSynchronousDeviceIoControlRequest(v14, v13, 0x24800u, IdexCdRomDeviceObject, 0, 0, 0, 0, 0, 0);
      if ( v16 == -1073741435 )
      {
        ++v15;
      }
      else if ( v16 != -1073741661 )
      {
        return;
      }
      Interval.QuadPart = -2000000i64;
      KeDelayExecutionThread(v18, v17, 0, 0, &Interval);
    }
    while ( v15 < 5 );
  }
}
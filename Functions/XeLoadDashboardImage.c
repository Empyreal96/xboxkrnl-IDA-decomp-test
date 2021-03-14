int *__usercall XeLoadDashboardImage@<eax>(int *a1@<edi>, int a2@<esi>)
{
  int *result; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  int v6; // ecx

  if ( unk_8004C824 )
    *(_DWORD *)(unk_8004C824 + 8) |= 8u;
  result = XeLoadAlternateDashboardImage(a1, a2);
  if ( (signed int)result < 0 )
  {
    result = XeLoadImage(a1, "\\Device\\Harddisk0\\Partition2\\xboxdash.xbe", 1, 0);
    if ( (signed int)result < 0 )
    {
      DbgPrint(a1, "INIT: Failed to launch an XBE (status=%08x).\n", result);
      DbgBreakPoint();
      if ( !KeHasQuickBooted )
      {
        HalWriteSMCLEDStates(v3, v4, a1, a2, 0xE1u);
        v6 = 13;
        if ( LaunchDataPage && LaunchDataPage->Header.dwLaunchDataType == 1 )
        {
          v6 = *(_DWORD *)LaunchDataPage->LaunchData + 13;
        }
        else if ( IdexCdRomDVDX2Authenticated )
        {
          v6 = 20;
        }
        ExDisplayFatalError(v5, v6, a2, v6);
      }
      HalReturnToFirmware(v3, v4, a1, a2, HalFatalErrorRebootRoutine);
    }
  }
  return result;
}
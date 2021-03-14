void __usercall XeLoadImageAfterTrayEjectBoot(int a1@<edx>, int *a2@<edi>, int a3@<esi>)
{
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  _LARGE_INTEGER Interval; // [esp+4h] [ebp-Ch]
  unsigned int TrayState; // [esp+Ch] [ebp-4h]

  AniBlockOnAnimation(a1, a2, a3);
  while ( HalReadSMBusValue(v3, v4, a2, 0, 32, 3, 0, &TrayState) >= 0 )
  {
    TrayState &= 0x70u;
    if ( TrayState != 80 && TrayState )
      goto LABEL_7;
    Interval.QuadPart = -2500000i64;
    KeDelayExecutionThread(v6, v5, 0, 0, &Interval);
  }
  TrayState = 16;
LABEL_7:
  if ( TrayState == 96 )
  {
    IoDismountVolume(IdexCdRomDeviceObject);
    XeLoadTitleImage(v8, v7, 0);
  }
  else
  {
    XeLoadDashboardImage(a2, 0);
  }
}
void __fastcall XeLoadTitleImage(int a1, int a2, unsigned int SettingsError)
{
  int *v3; // edi
  _LAUNCH_DATA_PAGE *v4; // eax
  _LAUNCH_DATA_PAGE *v5; // ST0C_4
  _LAUNCH_DATA_PAGE *v6; // eax
  int *v7; // esi
  char v8; // bl
  char *v9; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  unsigned int v15; // eax
  int v16; // [esp-4h] [ebp-18Ch]
  char CapturedLaunchPath[361]; // [esp+Ch] [ebp-17Ch]
  unsigned int TrayStateChangeCount1; // [esp+178h] [ebp-10h]
  _STRING LinkTarget; // [esp+17Ch] [ebp-Ch]
  unsigned int TrayStateChangeCount2; // [esp+184h] [ebp-4h]

  v3 = (int *)SettingsError;
  if ( SettingsError )
    goto LABEL_38;
  v4 = LaunchDataPage;
  if ( !LaunchDataPage )
    goto LABEL_38;
  if ( LaunchDataPage->Header.dwFlags & 1 )
  {
    v5 = LaunchDataPage;
    LaunchDataPage = 0;
    MmFreeContiguousMemory(a2, a1, (int *)SettingsError, v5);
    v4 = LaunchDataPage;
  }
  if ( !v4 )
  {
LABEL_38:
    HalReadSMCTrayState(&SettingsError, &TrayStateChangeCount1);
    v7 = XeLoadImage(v3, "\\Device\\CdRom0\\default.xbe", 0, (unsigned int)v3);
    if ( (signed int)v7 >= 0 )
      return;
    if ( v3 )
    {
      XeLoadDashboardImageWithReason(v12, v13, v3, 3u, (unsigned int)v3);
      return;
    }
    HalReadSMCTrayState(&SettingsError, &TrayStateChangeCount2);
    if ( SettingsError == 96 )
    {
      v11 = TrayStateChangeCount1;
      if ( TrayStateChangeCount1 != TrayStateChangeCount2 )
        v7 = (int *)-1073741661;
      if ( v7 != (int *)-1073741808
        && v7 != (int *)-1073741805
        && v7 != (int *)-1073741803
        && v7 != (int *)-1073741772
        && v7 != (int *)-1073741766
        && v7 != (int *)-1073741661
        && v7 != (int *)-1073741489 )
      {
        goto LABEL_28;
      }
    }
LABEL_35:
    XeLoadDashboardImage(v3, (int)v7);
    return;
  }
  v4->Header.dwFlags |= 1u;
  v6 = LaunchDataPage;
  qmemcpy(CapturedLaunchPath, LaunchDataPage->Header.szLaunchPath, 0x168u);
  v7 = (int *)&LaunchDataPage->Header.szLaunchPath[360];
  v3 = (int *)&CapturedLaunchPath[360];
  CapturedLaunchPath[360] = 0;
  if ( LaunchDataPage->Header.dwLaunchDataType == -1 )
  {
    LaunchDataPage = 0;
    MmFreeContiguousMemory(a2, 0, (int *)&CapturedLaunchPath[360], v6);
  }
  if ( !CapturedLaunchPath[0] )
    goto LABEL_35;
  v8 = 0;
  v9 = strchr(CapturedLaunchPath, 59);
  v3 = (int *)&XepLaunchDosDevice;
  if ( v9 )
  {
    *v9 = 92;
    LinkTarget.Length = (_WORD)v9 - (unsigned int)CapturedLaunchPath;
    LinkTarget.MaximumLength = (_WORD)v9 - (unsigned int)CapturedLaunchPath;
    LinkTarget.Buffer = CapturedLaunchPath;
    if ( (signed int)IoCreateSymbolicLink((int *)&XepLaunchDosDevice, (int)v7, &XepLaunchDosDevice, &LinkTarget) >= 0 )
      v8 = 1;
  }
  v7 = XeLoadImage((int *)&XepLaunchDosDevice, CapturedLaunchPath, 0, 0);
  if ( (signed int)v7 < 0 )
  {
    if ( v8 )
      IoDeleteSymbolicLink((int *)&XepLaunchDosDevice, (int)v7, &XepLaunchDosDevice);
LABEL_28:
    if ( (signed int)v7 >= 0 )
      RtlAssert(
        v10,
        v11,
        v3,
        (int)v7,
        "!NT_SUCCESS(status)",
        "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
        0xA59u,
        0);
    DbgPrint(v3, "LDRX: failed to load title image (status=%08x).\n", v7);
    if ( v7 == (int *)-1073414143 )
      v15 = 3;
    else
      v15 = 4 * ((int *)((char *)v7 + 1073414142) == 0) + 1;
    XeLoadDashboardImageWithReason(v14, v16, v3, 1u, v15);
  }
}
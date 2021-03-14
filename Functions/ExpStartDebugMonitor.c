int *__usercall ExpStartDebugMonitor@<eax>(int a1@<esi>)
{
  int *v1; // edi
  _STRING *v2; // eax
  int v3; // edx
  int v4; // ecx
  int *v5; // esi
  int *v6; // eax
  int v7; // edx
  int v8; // ecx
  unsigned int v9; // ecx
  int v10; // edx
  int v11; // ecx
  _IMAGE_NT_HEADERS *v13; // eax
  _FILE_NETWORK_OPEN_INFORMATION fni; // [esp+Ch] [ebp-B8h]
  _DMINIT dminit; // [esp+44h] [ebp-80h]
  int st; // [esp+84h] [ebp-40h]
  _OBJECT_ATTRIBUTES oa; // [esp+88h] [ebp-3Ch]
  _IO_STATUS_BLOCK iosb; // [esp+94h] [ebp-30h]
  void *pvBase; // [esp+9Ch] [ebp-28h]
  void *h; // [esp+A4h] [ebp-20h]
  char fLoadCanFail; // [esp+ABh] [ebp-19h]
  CPPEH_RECORD ms_exc; // [esp+ACh] [ebp-18h]

  memset(&dminit, 0, sizeof(dminit));
  v1 = &st;
  if ( XboxBootFlags & 2 )
  {
    fLoadCanFail = 0;
  }
  else
  {
    if ( XboxBootFlags & 4 )
    {
      dminit.Flags |= 0x10u;
      fLoadCanFail = 0;
      v2 = &ExpDVDXbdmDLL;
      goto LABEL_7;
    }
    fLoadCanFail = 1;
  }
  v2 = &ExpHDXbdmDLL;
LABEL_7:
  oa.RootDirectory = 0;
  oa.Attributes = 64;
  oa.ObjectName = v2;
  v5 = NtOpenFile(&st, a1, &h, 0x20u, &oa, &iosb, 0, 0x20u);
  if ( (signed int)v5 >= 0 )
  {
    v5 = NtQueryInformationFile(v3, v4, &st, (int)v5, h, &iosb, &fni, 0x38u, FileNetworkOpenInformation);
    if ( (signed int)v5 >= 0 )
    {
      v6 = (int *)MmDbgAllocateMemory(&st, fni.EndOfFile.LowPart, 4u);
      v1 = v6;
      pvBase = v6;
      if ( v6 )
      {
        v5 = (int *)NtReadFile(v7, v8, (int)v5, h, 0, 0, 0, &iosb, v6, fni.EndOfFile.LowPart, 0);
        if ( (signed int)v5 >= 0 )
        {
          ms_exc.registration.TryLevel = 0;
          v5 = (int *)LdrRelocateImage(v9, v1, (int)v5, v1, "xbdm", 0, 0xC0000018, 0xC000007B);
          st = (int)v5;
          ms_exc.registration.TryLevel = -1;
          if ( (signed int)v5 >= 0 )
          {
            NtClose(v1, h);
            dminit.DebugRoutine = &KiDebugRoutine;
            dminit.LoadedModuleList = &KdLoadedModuleList;
            dminit.CtxSwapNotifyRoutine = (void **)&KiDbgCtxSwapNotify;
            dminit.DpcDispatchNotifyRoutine = &KiDpcDispatchNotify;
            dminit.XProfpDataPtr = &ExpCallAttributedProfileData;
            dminit.ClockIntRoutine = &KiDbgClockInt;
            dminit.ProfIntRoutine = &KiDbgProfInt;
            dminit.HalStartProfileRoutine = (void (__stdcall *)(unsigned int))HalStartProfileInterrupt;
            dminit.HalStopProfileRoutine = (void (__stdcall *)(unsigned int))HalStopProfileInterrupt;
            dminit.HalProfileIntervalRoutine = (void (__stdcall *)(unsigned int))HalSetProfileInterval;
            dminit.DisallowXbdm = &ExpDisableDebugMonitor;
            v13 = RtlImageNtHeader(v1);
            return (int *)((int (__stdcall *)(int *, _DMINIT *, _DWORD))((char *)v1
                                                                       + v13->OptionalHeader.AddressOfEntryPoint))(
                            v1,
                            &dminit,
                            0);
          }
          MmDbgFreeMemory(v11, v10, v1, fni.EndOfFile.LowPart);
        }
      }
      else
      {
        v5 = (int *)-1073741801;
      }
    }
    NtClose(v1, h);
  }
  if ( !fLoadCanFail )
    return v5;
  DbgPrint(v1, "INIT: failed to load the debug monitor.\n");
  return 0;
}
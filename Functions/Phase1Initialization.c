void __userpurge __noreturn Phase1Initialization(int *a1@<edi>, int a2@<esi>, void *Context)
{
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int *v13; // eax
  unsigned int v14; // esi
  signed int v15; // eax
  int v16; // edx
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  int v23; // [esp+0h] [ebp-30h]
  int v24; // [esp+4h] [ebp-2Ch]
  _TIME_FIELDS TimeFields; // [esp+8h] [ebp-28h]
  _LARGE_INTEGER OldTime; // [esp+18h] [ebp-18h]
  _LARGE_INTEGER UniversalTime; // [esp+20h] [ebp-10h]
  _LARGE_INTEGER CmosTime; // [esp+28h] [ebp-8h]
  int savedregs; // [esp+30h] [ebp+0h]

  HalInitSystemPhase1(a1);
  if ( HalQueryRealTimeClock((unsigned __int16 *)&TimeFields) )
  {
    if ( TimeFields.Year < 2000 || TimeFields.Year > 2100 || !RtlTimeFieldsToTime(&TimeFields, &CmosTime) )
      CmosTime.QuadPart = 2305843013508661248i64;
    UniversalTime = CmosTime;
    KeSetSystemTime(v3, v4, a1, a2, &UniversalTime, &OldTime);
    KeBootTime = UniversalTime;
    KeBootTimeBias = 0i64;
  }
  AvpInitCurrentTVEncoder(a1);
  if ( !KeHasQuickBooted )
  {
    HalPulseHardwareMonitorPin();
    ExpDecryptEEPROM(v5, v6, (_XBOX_ENCRYPTED_SETTINGS *)a1);
    HalPulseHardwareMonitorPin();
    HalBlockIfNoAVPack(a1);
    if ( XboxBootFlags & 0x20 )
    {
      HalWriteSMCLEDStates(v7, v8, a1, a2, 0xE1u);
      ExDisplayFatalError(v9, v10, a2, 0x15u);
    }
    if ( !(XboxBootFlags & 1) )
    {
      HalPulseHardwareMonitorPin();
      AniStartAnimation(a1, (XboxBootFlags >> 4) & 1);
    }
  }
  IdexChannelCreate(a1, a2);
  if ( !KeHasQuickBooted && !(XboxBootFlags & 1) )
    ExpTryToBootMediaROM(a1);
  if ( !ExpDisableDebugMonitor )
  {
    v13 = ExpStartDebugMonitor(a2);
    v14 = (unsigned int)v13;
    if ( (signed int)v13 < 0 )
    {
      DbgPrint(a1, "INIT: debug monitor failed to start (status=%08x).\n", v13);
      KeBugCheckEx(0x32u, v14, 0, 0, 0);
    }
  }
  if ( KeHasQuickBooted || XboxBootFlags & 4 || XboxGameRegion & 0x80000000 )
    goto LABEL_40;
  HalPulseHardwareMonitorPin();
  v15 = ExpDetectSettingsError(a1);
  if ( v15 )
  {
    XeLoadTitleImage(v12, v11, v15);
    goto LABEL_32;
  }
  if ( (XboxBootFlags & 0x80u) != 0 )
  {
    XeLoadDashboardImageWithReason(v11, v12, a1, 5u, 0);
    goto LABEL_32;
  }
  if ( XboxBootFlags & 0x40 )
  {
    XeLoadImageAfterTrayEjectBoot(v11, a1, 2147483648);
    goto LABEL_32;
  }
  if ( !(XboxBootFlags & 8) )
LABEL_40:
    XeLoadTitleImage(v12, v11, 0);
  else
    XeLoadDashboardImage(a1, 2147483648);
LABEL_32:
  if ( !KeHasQuickBooted )
  {
    HalPulseHardwareMonitorPin();
    HalWriteSMBusValue(v17, v18, a1, 2147483648, 32, 26, 0, 1u);
    AniTerminateAnimation(v19, v20, a1, 2147483648);
    if ( XboxGameRegion & 0x80000000 )
      ExpCopyLastUEMError(v21, v22, a1);
    MmDiscardInitSection();
  }
  MmRelocatePersistentMemory(v16, a1);
  MEMORY[0x10128](
    v23,
    v24,
    *(_DWORD *)&TimeFields.Year,
    *(_DWORD *)&TimeFields.Day,
    *(_DWORD *)&TimeFields.Minute,
    *(_DWORD *)&TimeFields.Milliseconds,
    OldTime.LowPart,
    OldTime.HighPart,
    UniversalTime.LowPart,
    UniversalTime.HighPart,
    CmosTime.LowPart,
    CmosTime.HighPart,
    savedregs);
  PsTerminateSystemThread((unsigned int)a1, 2147483648, 0);
  __debugbreak();
  JUMPOUT(*(_DWORD *)IoAllocateIrp);
}
char __userpurge HalpHandleNextSMCInterruptReason@<al>(int *a1@<edi>, int a2@<esi>, int SMBusStatus)
{
  char v3; // al
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx

  v3 = HalpSMCInterruptReason;
  if ( HalpSMCInterruptReason & 1 )
  {
    HalpSMCInterruptReason &= 0xFEu;
    HalpSMCResetOrShutdownCommandCode = 13;
    HalpSMCResetOrShutdownDataValue = 1;
    HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpCommonResetOrShutdownComplete;
    HalpKickoffWriteSMBus(32, 13, 1, 2u);
    KeRetireDpcListLoop((int)a1, a2);
  }
  if ( HalpSMCInterruptReason & 0x10 )
  {
    v3 = HalpSMCInterruptReason & 0xEF;
    HalpSMCInterruptReason &= 0xEFu;
    if ( !(XboxGameRegion & 0x80000000) )
    {
      HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpHandleNextSMCInterruptReason;
      if ( XboxHardwareInfo.Flags & 0x400 )
      {
        HalpKickoffWriteSMBus(224, 4, 4, 0xFu);
      }
      else if ( XboxHardwareInfo.Flags & 0x20 )
      {
        HalpKickoffWriteSMBus(212, 160, 2, 0x20Fu);
      }
      else
      {
        HalpKickoffWriteSMBus(138, 186, 1, 0x3Fu);
      }
      return 1;
    }
  }
  if ( v3 & 8 )
  {
    v3 &= 0xF7u;
    HalpSMCInterruptReason = v3;
    if ( !(XboxGameRegion & 0x80000000) )
    {
      HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpReadSMCVideoModeComplete;
      HalpKickoffReadSMBus(32, 4, 1);
      return 1;
    }
  }
  if ( v3 & 0x20 )
  {
    HalpTrayEjectCompleteEvent.Header.SignalState = 0;
    ++HalpTrayStateChangeCount;
    HalpSMCInterruptReason = v3 & 0xDF;
    HalpTrayState = 32;
    HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpTrayEjectWriteSMCResumeComplete;
LABEL_18:
    HalpKickoffWriteSMBus(32, 13, 1, 4u);
    return 1;
  }
  if ( v3 & 4 )
  {
    HalpSMCInterruptReason = v3 & 0xFB;
    KeSetEvent(XboxGameRegion, 2147483648, &HalpTrayEjectCompleteEvent, 1, 0);
    ++HalpTrayStateChangeCount;
    HalpTrayState = -1;
    IdexCdRomTrayOpenNotification(v5, v6, a1, a2);
    XeCdRomMediaTimeDateStamp = 0;
    if ( !(XboxBootFlags & 8) && HalpTrayEjectRequiresReboot )
    {
      HalpSMCResetOrShutdownCommandCode = 13;
      HalpSMCResetOrShutdownDataValue = 8;
      HalpCommonResetOrShutdown(v7, v8, a1);
    }
    HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpTrayOpenWriteSMCResumeComplete;
    goto LABEL_18;
  }
  if ( v3 & 0x40 )
  {
    v3 &= 0xBFu;
    ++HalpTrayStateChangeCount;
    HalpTrayState = 0;
    HalpSMCInterruptReason = v3;
  }
  if ( v3 & 2 )
  {
    ++HalpTrayStateChangeCount;
    HalpTrayState = -1;
    HalpSMCInterruptReason = v3 & 0xFD;
  }
  return 0;
}
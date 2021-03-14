char __userpurge HalpReadSMCVideoModeComplete@<al>(int *a1@<edi>, int a2@<esi>, int SMBusStatus)
{
  unsigned __int8 v3; // al
  int v4; // eax
  int v6; // eax
  signed int v7; // eax
  int v8; // eax

  if ( SMBusStatus < 0 )
    return HalpHandleNextSMCInterruptReason(a1, a2, 0);
  v3 = __inbyte(0xC006u);
  v4 = v3 & 7;
  if ( v4 == 7 )
    return HalpHandleNextSMCInterruptReason(a1, a2, SMBusStatus);
  if ( v4 != HalBootSMCVideoMode )
  {
    HalpSMCResetOrShutdownCommandCode = 2;
    HalpSMCResetOrShutdownDataValue = 1;
    HalpCommonResetOrShutdown(-16378, 0, a1);
  }
  if ( !AvpCapabilities )
    return HalpHandleNextSMCInterruptReason(a1, a2, 0);
  HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpHandleNextSMCInterruptReason;
  if ( XboxHardwareInfo.Flags & 0x400 )
  {
    if ( AvpCurrentMode )
      v6 = HIBYTE(AvpCurrentMode) & 0xF;
    else
      v6 = 15;
    HalpKickoffWriteSMBus(224, 4, 4, v6);
  }
  else if ( XboxHardwareInfo.Flags & 0x20 )
  {
    if ( AvpCurrentMode )
      v7 = (HIBYTE(AvpCurrentMode) & 0xF) != 15 ? 0 : 15;
    else
      v7 = 15;
    HalpKickoffWriteSMBus(212, 160, 2, v7 | 0x200);
  }
  else
  {
    if ( AvpCurrentMode )
      v8 = HIBYTE(AvpCurrentMode) & 0xF;
    else
      v8 = 15;
    HalpKickoffWriteSMBus(138, 186, 1, v8 | 0x20);
  }
  return 1;
}
char __stdcall HalpWriteSMCAudioClampComplete(int SMBusStatus)
{
  HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpDisableVideoDACsComplete;
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
    __outbyte(0x80D3u, 5u);
    HalpKickoffWriteSMBus(138, 186, 1, 0x3Fu);
  }
  return 1;
}
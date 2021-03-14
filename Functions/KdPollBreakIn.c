char __stdcall KdPollBreakIn()
{
  unsigned __int8 Enable; // [esp+7h] [ebp-5h]
  char BreakIn; // [esp+Bh] [ebp-1h]

  BreakIn = 0;
  if ( !KdDebuggerEnabled )
    return BreakIn;
  Enable = KiDisableInterrupts();
  if ( KdpControlCPending )
  {
    KdpControlCPending = 0;
LABEL_5:
    BreakIn = 1;
    KdpControlCPressed = 1;
    goto LABEL_6;
  }
  if ( !KdPhysicalPort->ReceivePacket(8u, 0, 0, 0) )
    goto LABEL_5;
LABEL_6:
  KiRestoreInterrupts(Enable);
  if ( BreakIn )
  {
    KdDebuggerNotPresent = 0;
    if ( unk_8004C824 )
      (*(void (__stdcall **)(signed int, _DWORD))(unk_8004C824 + 20))(1, 0);
  }
  return BreakIn;
}
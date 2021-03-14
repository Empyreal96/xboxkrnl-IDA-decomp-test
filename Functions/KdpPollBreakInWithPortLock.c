char __stdcall KdpPollBreakInWithPortLock()
{
  char v0; // bl

  v0 = 0;
  if ( KdDebuggerEnabled )
  {
    if ( KdpControlCPending )
    {
      KdpControlCPending = 0;
      return 1;
    }
    if ( !KdPhysicalPort->ReceivePacket(8u, 0, 0, 0) )
      return 1;
  }
  return v0;
}
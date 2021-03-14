unsigned __int16 __stdcall KdpSerialReceivePacketLeader(unsigned int PacketType, unsigned int *PacketLeader)
{
  char v2; // bl
  unsigned int v3; // esi
  unsigned int v4; // eax
  char Input; // [esp+Ah] [ebp-2h]
  char BreakinDetected; // [esp+Bh] [ebp-1h]

  v2 = 0;
  BreakinDetected = 0;
LABEL_2:
  v3 = 0;
  do
  {
    while ( 1 )
    {
      v4 = KdPortGetByte(&Input);
      if ( v4 == 1 )
      {
        if ( !BreakinDetected )
          return 1;
        KdpControlCPending = 1;
        return 2;
      }
      if ( v4 == 2 )
        goto LABEL_2;
      if ( Input != 48 && Input != 105 )
      {
        BreakinDetected = Input == 98;
        goto LABEL_2;
      }
      if ( v3 )
        break;
      v2 = Input;
      v3 = 1;
    }
    if ( Input == v2 )
    {
      ++v3;
    }
    else
    {
      v2 = Input;
      v3 = 1;
    }
  }
  while ( v3 < 4 );
  if ( BreakinDetected )
    KdpControlCPending = 1;
  *PacketLeader = Input != 48 ? 1768515945 : 808464432;
  KdDebuggerNotPresent = 0;
  return 0;
}
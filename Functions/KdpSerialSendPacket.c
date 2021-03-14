void __stdcall KdpSerialSendPacket(unsigned int PacketType, _STRING *MessageHeader, _STRING *MessageData)
{
  unsigned int v3; // ebx
  unsigned __int16 v4; // di
  bool v5; // zf
  unsigned int v6; // eax
  _KD_PACKET PacketHeader; // [esp+Ch] [ebp-10h]

  v3 = 0;
  if ( MessageData )
  {
    v3 = MessageData->Length;
    PacketHeader.Checksum = KdpComputeChecksum(MessageData->Buffer, v3);
  }
  else
  {
    PacketHeader.Checksum = 0;
  }
  v4 = MessageHeader->Length;
  PacketHeader.Checksum += KdpComputeChecksum(MessageHeader->Buffer, MessageHeader->Length);
  PacketHeader.ByteCount = v3 + v4;
  PacketHeader.PacketLeader = 808464432;
  PacketHeader.PacketType = PacketType;
  KdpNumberRetries = KdpRetryCount;
  while ( 1 )
  {
    if ( !KdpNumberRetries )
    {
      if ( PacketType == 3 )
      {
        v5 = *(_DWORD *)MessageHeader->Buffer == 12848;
        goto LABEL_10;
      }
      if ( PacketType == 7 )
        break;
    }
LABEL_11:
    PacketHeader.PacketId = KdpNextPacketIdToSend;
    KdpSerialSendString((char *)&PacketHeader, 0x10u);
    KdpSerialSendString(MessageHeader->Buffer, MessageHeader->Length);
    if ( v3 )
      KdpSerialSendString(MessageData->Buffer, MessageData->Length);
    KdPortPutByte(170);
    v6 = KdpSerialReceivePacket(4u, 0, 0, 0);
    if ( v6 == 1 )
      --KdpNumberRetries;
    if ( !v6 )
    {
      BYTE1(KdpNextPacketIdToSend) &= 0xF7u;
      KdpRetryCount = 20;
      return;
    }
  }
  v5 = *(_DWORD *)MessageHeader->Buffer == 12337;
LABEL_10:
  if ( !v5 )
    goto LABEL_11;
  KdDebuggerNotPresent = 1;
  KdpNextPacketIdToSend = -2139092992;
  KdpPacketIdExpected = -2139095040;
}
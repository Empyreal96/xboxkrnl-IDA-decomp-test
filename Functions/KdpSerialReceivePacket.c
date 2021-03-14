unsigned int __stdcall KdpSerialReceivePacket(unsigned int PacketType, _STRING *MessageHeader, _STRING *MessageData, unsigned int *DataLength)
{
  unsigned int result; // eax
  unsigned int *v5; // ebx
  _STRING *v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  int v11; // esi
  unsigned int v12; // ST04_4
  _STRING *v13; // esi
  unsigned int v14; // esi
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // [esp-10h] [ebp-20h]
  _KD_PACKET PacketHeader; // [esp+0h] [ebp-10h]

  if ( PacketType != 8 )
  {
    v5 = DataLength;
    v6 = MessageHeader;
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              result = KdpSerialReceivePacketLeader(PacketType, &PacketHeader.PacketLeader);
              if ( (unsigned __int16)result != 1 )
                KdpNumberRetries = KdpRetryCount;
              if ( result )
                return result;
              v7 = KdpSerialReceiveString((char *)&PacketHeader.PacketType, 2u);
              if ( v7 == 1 )
                return 1;
              if ( v7 != 2 )
              {
                if ( PacketHeader.PacketLeader == 1768515945 && PacketHeader.PacketType == 5 )
                  return 2;
                v8 = KdpSerialReceiveString((char *)&PacketHeader.ByteCount, 2u);
                if ( v8 == 1 )
                  return 1;
                if ( v8 != 2 )
                {
                  v9 = KdpSerialReceiveString((char *)&PacketHeader.PacketId, 4u);
                  if ( v9 == 1 )
                    return 1;
                  if ( v9 != 2 )
                  {
                    v10 = KdpSerialReceiveString((char *)&PacketHeader.Checksum, 4u);
                    if ( v10 == 1 )
                      return 1;
                    if ( v10 != 2 )
                      break;
                  }
                }
              }
              if ( PacketHeader.PacketLeader != 1768515945 )
                goto SendResendPacket;
            }
            if ( PacketHeader.PacketLeader != 1768515945 )
              break;
            switch ( PacketHeader.PacketType )
            {
              case 4u:
                if ( PacketHeader.PacketId == (KdpNextPacketIdToSend & 0xFFFFF7FF) && PacketType == 4 )
                  goto LABEL_54;
                break;
              case 6u:
                KdpNextPacketIdToSend = -2139095040;
                KdpPacketIdExpected = -2139095040;
                KdpSerialSendControlPacket(6u, 0);
                return 2;
              case 5u:
                return 2;
            }
          }
          if ( PacketType != 4 )
            break;
          if ( PacketHeader.PacketId == KdpPacketIdExpected )
          {
            KdpSerialSendControlPacket(5u, 0);
LABEL_54:
            KdpNextPacketIdToSend ^= 1u;
            return 0;
          }
          KdpSerialSendControlPacket(4u, PacketHeader.PacketId);
        }
        v11 = v6->MaximumLength;
        if ( PacketHeader.ByteCount <= 0xFA0u && PacketHeader.ByteCount >= (unsigned __int16)v11 )
        {
          v12 = v6->MaximumLength;
          *v5 = PacketHeader.ByteCount - v11;
          if ( !KdpSerialReceiveString(v6->Buffer, v12) )
          {
            v6->Length = v11;
            v13 = MessageData;
            if ( !KdpSerialReceiveString(MessageData->Buffer, *v5) )
            {
              v13->Length = *(_WORD *)v5;
              if ( !KdPortGetByte((char *)&MessageHeader + 3) && HIBYTE(MessageHeader) == -86 )
              {
                if ( PacketType != PacketHeader.PacketType )
                {
                  v17 = PacketHeader.PacketId;
                  goto LABEL_45;
                }
                v14 = PacketHeader.PacketId;
                if ( PacketHeader.PacketId == -2139095040 || PacketHeader.PacketId == -2139095039 )
                  break;
              }
            }
          }
        }
SendResendPacket:
        KdpSerialSendControlPacket(5u, 0);
      }
      if ( PacketHeader.PacketId == KdpPacketIdExpected )
      {
        v15 = KdpComputeChecksum(v6->Buffer, v6->Length);
        v16 = KdpComputeChecksum(MessageData->Buffer, MessageData->Length);
        if ( v16 + v15 == PacketHeader.Checksum )
        {
          KdpSerialSendControlPacket(4u, v14);
          KdpPacketIdExpected ^= 1u;
          return 0;
        }
        v5 = DataLength;
        goto SendResendPacket;
      }
      v17 = PacketHeader.PacketId;
LABEL_45:
      KdpSerialSendControlPacket(4u, v17);
    }
  }
  result = KdPortPollByte((char *)&MessageHeader + 3);
  if ( result || HIBYTE(MessageHeader) != 98 )
    result = 1;
  return result;
}
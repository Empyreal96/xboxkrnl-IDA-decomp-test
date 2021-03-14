void __stdcall KdpSerialSendControlPacket(unsigned __int16 PacketType, unsigned int PacketId)
{
  _KD_PACKET PacketHeader; // [esp+0h] [ebp-10h]

  PacketHeader.PacketLeader = 1768515945;
  if ( PacketId )
    PacketHeader.PacketId = PacketId;
  PacketHeader.ByteCount = 0;
  PacketHeader.Checksum = 0;
  PacketHeader.PacketType = PacketType;
  KdpSerialSendString((char *)&PacketHeader, 0x10u);
}
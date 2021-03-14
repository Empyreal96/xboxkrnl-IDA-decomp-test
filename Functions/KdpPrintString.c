char __stdcall KdpPrintString(_STRING *Output)
{
  signed int v1; // eax
  _DBGKD_DEBUG_IO DebugIo; // [esp+4h] [ebp-20h]
  _STRING MessageHeader; // [esp+14h] [ebp-10h]
  _STRING MessageData; // [esp+1Ch] [ebp-8h]

  v1 = KdpMoveMemory(KdpMessageBuffer, Output->Buffer, Output->Length, 1);
  if ( (unsigned int)(v1 + 16) > 0xFA0 )
    v1 = 3984;
  DebugIo.Processor = 0;
  DebugIo.u.PrintString.LengthOfString = v1;
  MessageData.Length = v1;
  DebugIo.ApiNumber = 12848;
  DebugIo.ProcessorLevel = 6;
  MessageHeader.Length = 16;
  MessageHeader.Buffer = (char *)&DebugIo;
  MessageData.Buffer = KdpMessageBuffer;
  KdPhysicalPort->SendPacket(3u, &MessageHeader, &MessageData);
  return KdpPollBreakInWithPortLock();
}
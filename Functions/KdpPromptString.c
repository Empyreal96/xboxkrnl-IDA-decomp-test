char __stdcall KdpPromptString(_STRING *Output, _STRING *Input)
{
  _STRING *v2; // eax
  _STRING *v3; // edi
  unsigned int v4; // ecx
  unsigned int v5; // eax
  _DBGKD_DEBUG_IO DebugIo; // [esp+8h] [ebp-20h]
  _STRING MessageHeader; // [esp+18h] [ebp-10h]
  _STRING MessageData; // [esp+20h] [ebp-8h]

  v2 = (_STRING *)KdpMoveMemory(KdpMessageBuffer, Output->Buffer, Output->Length, 1);
  Output = v2;
  if ( (unsigned int)&v2[2] > 0xFA0 )
  {
    v2 = (_STRING *)3984;
    Output = (_STRING *)3984;
  }
  v3 = Input;
  v4 = Input->MaximumLength;
  DebugIo.Processor = 0;
  DebugIo.u = ($13DBB5D14318397D186C618E72C19658)__PAIR__(v4, (unsigned int)v2);
  MessageData.Length = (unsigned __int16)v2;
  DebugIo.ApiNumber = 12849;
  DebugIo.ProcessorLevel = 6;
  MessageHeader.Length = 16;
  MessageHeader.Buffer = (char *)&DebugIo;
  MessageData.Buffer = KdpMessageBuffer;
  KdPhysicalPort->SendPacket(3u, &MessageHeader, &MessageData);
  MessageHeader.MaximumLength = 16;
  MessageData.MaximumLength = 4096;
  do
  {
    v5 = KdPhysicalPort->ReceivePacket(3u, &MessageHeader, &MessageData, (unsigned int *)&Output);
    if ( v5 == 2 )
      return 1;
  }
  while ( v5 );
  if ( (unsigned int)Output > v3->MaximumLength )
    Output = (_STRING *)v3->MaximumLength;
  v3->Length = KdpMoveMemory(v3->Buffer, KdpMessageBuffer, (unsigned int)Output, 0);
  return 0;
}
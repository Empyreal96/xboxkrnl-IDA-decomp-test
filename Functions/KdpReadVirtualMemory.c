void __stdcall KdpReadVirtualMemory(_DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
{
  unsigned int v2; // ebx
  _STRING MessageHeader; // [esp+Ch] [ebp-8h]

  v2 = m->u.ReadMemory.TransferCount;
  if ( v2 > 0xF68 )
    v2 = 3944;
  AdditionalData->Length = KdpMoveMemory(AdditionalData->Buffer, (void *)m->u.GetContext.Unused, v2, 1);
  m->ReturnStatus = 0;
  if ( v2 != AdditionalData->Length )
    m->ReturnStatus = -1073741823;
  m->u.ReadMemory.ActualBytesRead = AdditionalData->Length;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)m;
  KdPhysicalPort->SendPacket(2u, &MessageHeader, AdditionalData);
}
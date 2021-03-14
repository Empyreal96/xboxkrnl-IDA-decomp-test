void __stdcall KdpWriteVirtualMemory(_DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
{
  unsigned int v2; // eax
  _STRING MessageHeader; // [esp+8h] [ebp-8h]

  v2 = KdpMoveMemory((void *)m->u.GetContext.Unused, AdditionalData->Buffer, AdditionalData->Length, 0);
  m->ReturnStatus = 0;
  if ( v2 != AdditionalData->Length )
    m->ReturnStatus = -1073741823;
  m->u.ReadMemory.ActualBytesRead = v2;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)m;
  KdPhysicalPort->SendPacket(2u, &MessageHeader, 0);
}
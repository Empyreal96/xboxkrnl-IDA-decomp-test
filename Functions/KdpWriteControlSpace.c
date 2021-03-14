void __stdcall KdpWriteControlSpace(_DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  _STRING *v4; // edi
  unsigned int v5; // eax
  _STRING MessageHeader; // [esp+8h] [ebp-8h]

  v2 = m->u.GetContext.Unused;
  v3 = v2 + m->u.ReadMemory.TransferCount;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)m;
  if ( v3 > 0x320 || m->Processor >= 1u )
  {
    v4 = AdditionalData;
    AdditionalData->Length = 0;
    m->ReturnStatus = -1073741823;
    m->u.ReadMemory.ActualBytesRead = 0;
  }
  else
  {
    v4 = AdditionalData;
    v5 = KdpMoveMemory((char *)&KdProcessorState + v2, AdditionalData->Buffer, AdditionalData->Length, 0);
    m->ReturnStatus = AdditionalData->Length != v5 ? 0xC0000001 : 0;
    m->u.ReadMemory.ActualBytesRead = v5;
  }
  KdPhysicalPort->SendPacket(2u, &MessageHeader, v4);
}
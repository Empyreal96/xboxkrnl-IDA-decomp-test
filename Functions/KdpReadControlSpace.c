void __userpurge KdpReadControlSpace(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
{
  bool v5; // zf
  unsigned int v6; // esi
  unsigned int v7; // ecx
  unsigned __int16 v8; // ax
  _STRING MessageHeader; // [esp+Ch] [ebp-8h]

  v5 = AdditionalData->Length == 0;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)m;
  if ( !v5 )
    RtlAssert(
      a1,
      a2,
      (int *)m,
      a3,
      "AdditionalData->Length == 0",
      "d:\\xbox-apr03\\private\\ntos\\kd64\\i386\\kdcpuapi.c",
      0x2D2u,
      0);
  v6 = m->u.ReadMemory.TransferCount;
  if ( v6 > 0xF68 )
    v6 = 3944;
  v7 = m->u.GetContext.Unused;
  if ( v7 >= 0x320 || m->Processor >= 1u )
  {
    AdditionalData->Length = 0;
    m->ReturnStatus = -1073741823;
    m->u.ReadMemory.ActualBytesRead = 0;
  }
  else
  {
    if ( 800 - v7 < v6 )
      v6 = 800 - v7;
    v8 = KdpMoveMemory(AdditionalData->Buffer, (char *)&KdProcessorState + v7, v6, 1);
    AdditionalData->Length = v8;
    m->ReturnStatus = v8 != v6 ? 0xC0000001 : 0;
    m->u.ReadMemory.ActualBytesRead = AdditionalData->Length;
  }
  KdPhysicalPort->SendPacket(2u, &MessageHeader, AdditionalData);
}
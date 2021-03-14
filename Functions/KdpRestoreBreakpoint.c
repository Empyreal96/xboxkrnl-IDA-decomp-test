void __userpurge KdpRestoreBreakpoint(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
{
  bool v5; // zf
  _STRING MessageHeader; // [esp+4h] [ebp-8h]

  v5 = AdditionalData->Length == 0;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)m;
  if ( !v5 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)m,
      "AdditionalData->Length == 0",
      "d:\\xbox-apr03\\private\\ntos\\kd64\\kdapi.c",
      0x428u,
      0);
  m->ReturnStatus = KdpDeleteBreakpoint(a3, m->u.GetContext.Unused) != 0 ? 0 : -1073741823;
  KdPhysicalPort->SendPacket(2u, &MessageHeader, 0);
}
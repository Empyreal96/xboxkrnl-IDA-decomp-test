void __fastcall KdpGetContext(int a1, int a2, _DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData, _X86_NT5_CONTEXT *Context)
{
  bool v5; // zf
  _STRING MessageHeader; // [esp+8h] [ebp-8h]

  v5 = AdditionalData->Length == 0;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)m;
  if ( !v5 )
    RtlAssert(
      a2,
      a1,
      (int *)m,
      (int)AdditionalData,
      "AdditionalData->Length == 0",
      "d:\\xbox-apr03\\private\\ntos\\kd64\\kdapi.c",
      0x39Fu,
      0);
  if ( m->Processor < 1u )
  {
    m->ReturnStatus = 0;
    AdditionalData->Length = 716;
    KdpQuickMoveMemory(AdditionalData->Buffer, Context, 0x2CCu);
  }
  else
  {
    m->ReturnStatus = -1073741823;
  }
  ((void (__fastcall *)(int, int, signed int, _STRING *, _STRING *))KdPhysicalPort->SendPacket)(
    a1,
    a2,
    2,
    &MessageHeader,
    AdditionalData);
}
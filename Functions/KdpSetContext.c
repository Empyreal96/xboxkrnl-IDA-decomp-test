void __fastcall KdpSetContext(int a1, int a2, _DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData, _X86_NT5_CONTEXT *Context)
{
  bool v5; // zf
  _STRING MessageHeader; // [esp+8h] [ebp-8h]

  v5 = AdditionalData->Length == 716;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)m;
  if ( !v5 )
    RtlAssert(
      a2,
      a1,
      (int *)AdditionalData,
      (int)m,
      "AdditionalData->Length == sizeof(*Context)",
      "d:\\xbox-apr03\\private\\ntos\\kd64\\kdapi.c",
      0x3CFu,
      0);
  if ( m->Processor < 1u )
  {
    m->ReturnStatus = 0;
    KdpQuickMoveMemory(Context, AdditionalData->Buffer, 0x2CCu);
  }
  else
  {
    m->ReturnStatus = -1073741823;
  }
  ((void (__fastcall *)(int, int, signed int, _STRING *, _DWORD))KdPhysicalPort->SendPacket)(
    a1,
    a2,
    2,
    &MessageHeader,
    0);
}
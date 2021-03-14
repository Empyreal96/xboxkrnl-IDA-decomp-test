void __fastcall KdpWriteMachineSpecificRegister(int a1, int a2, _DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
{
  unsigned int v4; // eax
  unsigned int v5; // ecx
  unsigned __int64 v6; // rax
  int v7; // ecx
  _STRING MessageHeader; // [esp+Ch] [ebp-20h]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h]

  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)m;
  if ( AdditionalData->Length )
    RtlAssert(
      a2,
      a1,
      0,
      (int)m,
      "AdditionalData->Length == 0",
      "d:\\xbox-apr03\\private\\ntos\\kd64\\i386\\kdcpuapi.c",
      0x414u,
      0);
  m->ReturnStatus = 0;
  v4 = m->u.ReadMemory.TransferCount;
  v5 = m->u.Continue2.ControlSet.TraceFlag;
  ms_exc.registration.TryLevel = 0;
  v6 = WRMSR(m->u.GetContext.Unused, __PAIR__(v4, v5));
  ((void (__fastcall *)(int, _DWORD, signed int, _STRING *, _DWORD))KdPhysicalPort->SendPacket)(
    v7,
    HIDWORD(v6),
    2,
    &MessageHeader,
    0);
}
void __fastcall KdpReadMachineSpecificRegister(int a1, int a2, _DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
{
  void **v4; // esi
  unsigned __int64 l; // ST1C_8
  int v6; // [esp+0h] [ebp-38h]
  int v7; // [esp+4h] [ebp-34h]
  int v8; // [esp+8h] [ebp-30h]
  _STRING MessageHeader; // [esp+14h] [ebp-24h]
  _DBGKD_READ_WRITE_MSR *a; // [esp+1Ch] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+20h] [ebp-18h]
  int savedregs; // [esp+38h] [ebp+0h]

  v4 = (void **)&m->u;
  a = (_DBGKD_READ_WRITE_MSR *)&m->u;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)m;
  if ( AdditionalData->Length )
    RtlAssert(
      a2,
      a1,
      (int *)m,
      (int)v4,
      "AdditionalData->Length == 0",
      "d:\\xbox-apr03\\private\\ntos\\kd64\\i386\\kdcpuapi.c",
      0x3E2u,
      0);
  m->ReturnStatus = 0;
  ms_exc.registration.TryLevel = 0;
  l = RDMSR(*v4);
  ms_exc.registration.TryLevel = -1;
  *(_QWORD *)(&m->u.SetContext + 1) = l;
  ((void (__stdcall *)(signed int, _STRING *, _DWORD, int, int, int, _DWORD, _DWORD, _DWORD, char *, _DBGKD_READ_WRITE_MSR *, DWORD, EXCEPTION_POINTERS *, struct _EH3_EXCEPTION_REGISTRATION *, PVOID, PSCOPETABLE_ENTRY, DWORD, int))KdPhysicalPort->SendPacket)(
    2,
    &MessageHeader,
    0,
    v6,
    v7,
    v8,
    l,
    HIDWORD(l),
    *(_DWORD *)&MessageHeader.Length,
    MessageHeader.Buffer,
    a,
    ms_exc.old_esp,
    ms_exc.exc_ptr,
    ms_exc.registration.Next,
    ms_exc.registration.ExceptionHandler,
    ms_exc.registration.ScopeTable,
    ms_exc.registration.TryLevel,
    savedregs);
}
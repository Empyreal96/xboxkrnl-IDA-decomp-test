void __userpurge KdpWriteIoSpace(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
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
      "d:\\xbox-apr03\\private\\ntos\\kd64\\i386\\kdcpuapi.c",
      0x3A0u,
      0);
  m->ReturnStatus = 0;
  switch ( m->u.ReadMemory.TransferCount )
  {
    case 1u:
      LOWORD(a1) = m->u.GetVersion64.MajorVersion;
      __outbyte(a1, *((_BYTE *)&m->u.SetSpecialCall + 12));
      goto LABEL_13;
    case 2u:
      if ( !(m->u.ReadMemory.TargetBaseAddress & 1) )
      {
        LOWORD(a1) = m->u.GetVersion64.MajorVersion;
        __outword(a1, m->u.GetVersion64.Unused[1]);
        goto LABEL_13;
      }
      goto LABEL_10;
    case 4u:
      if ( !(m->u.ReadMemory.TargetBaseAddress & 3) )
      {
        LOWORD(a1) = m->u.GetVersion64.MajorVersion;
        __outdword(a1, m->u.ReadMemory.ActualBytesRead);
        goto LABEL_13;
      }
LABEL_10:
      m->ReturnStatus = -2147483646;
      goto LABEL_13;
  }
  m->ReturnStatus = -1073741811;
LABEL_13:
  ((void (__fastcall *)(int, int, signed int, _STRING *, _DWORD))KdPhysicalPort->SendPacket)(
    a2,
    a1,
    2,
    &MessageHeader,
    0);
}
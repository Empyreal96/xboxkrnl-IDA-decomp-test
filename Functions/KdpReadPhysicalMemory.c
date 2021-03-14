void __userpurge KdpReadPhysicalMemory(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
{
  _STRING *v5; // ebx
  bool v6; // zf
  _DBGKD_MANIPULATE_STATE64 *v7; // esi
  unsigned int v8; // edi
  void *v9; // eax
  unsigned int v10; // esi
  _STRING MessageHeader; // [esp+Ch] [ebp-10h]
  _LARGE_INTEGER Source; // [esp+14h] [ebp-8h]
  char *Destination; // [esp+28h] [ebp+Ch]

  v5 = AdditionalData;
  v6 = AdditionalData->Length == 0;
  v7 = m;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)m;
  if ( !v6 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)m,
      "AdditionalData->Length == 0",
      "d:\\xbox-apr03\\private\\ntos\\kd64\\kdapi.c",
      0x773u,
      0);
  v8 = m->u.ReadMemory.TransferCount;
  if ( v8 > 0xF68 )
    v8 = 3944;
  Source = (_LARGE_INTEGER)m->u.ReadMemory.TargetBaseAddress;
  Destination = AdditionalData->Buffer;
  while ( v8 )
  {
    v9 = (void *)MmDbgTranslatePhysicalAddress64(Source);
    if ( !v9 )
      break;
    v10 = 4096 - (Source.LowPart & 0xFFF);
    if ( v10 > v8 )
      v10 = v8;
    KdpMoveMemory(Destination, v9, v10, 1);
    Destination += v10;
    Source.QuadPart += v10;
    v8 -= v10;
    v5->Length += v10;
    v7 = m;
  }
  v7->ReturnStatus = v8 != 0 ? 0xC0000001 : 0;
  v7->u.ReadMemory.ActualBytesRead = v5->Length;
  KdPhysicalPort->SendPacket(2u, &MessageHeader, v5);
}
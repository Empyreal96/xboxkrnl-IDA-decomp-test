void __stdcall KdpWritePhysicalMemory(_DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
{
  _DBGKD_MANIPULATE_STATE64 *v2; // esi
  unsigned int v3; // edi
  int v4; // eax
  void *v5; // eax
  unsigned int v6; // ebx
  _STRING MessageHeader; // [esp+8h] [ebp-10h]
  _LARGE_INTEGER Destination; // [esp+10h] [ebp-8h]
  char *Source; // [esp+20h] [ebp+8h]

  v2 = m;
  Source = AdditionalData->Buffer;
  v3 = v2->u.ReadMemory.TransferCount;
  Destination.LowPart = v2->u.GetContext.Unused;
  v4 = v2->u.BreakPointEx.ContinueStatus;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)v2;
  for ( Destination.HighPart = v4; v3; v3 -= v6 )
  {
    v5 = (void *)MmDbgTranslatePhysicalAddress64(Destination);
    if ( !v5 )
      break;
    v6 = 4096 - (Destination.LowPart & 0xFFF);
    if ( v6 > v3 )
      v6 = v3;
    KdpMoveMemory(v5, Source, v6, 0);
    Source += v6;
    Destination.QuadPart += v6;
    v2->u.ReadMemory.ActualBytesRead += v6;
  }
  v2->ReturnStatus = v3 != 0 ? 0xC0000001 : 0;
  KdPhysicalPort->SendPacket(2u, &MessageHeader, 0);
}
void __stdcall KdLogDbgPrint(_STRING *String)
{
  KIRQL v1; // al
  unsigned int v2; // edi
  unsigned int v3; // esi
  unsigned int v4; // eax
  char OldIrql; // [esp+Fh] [ebp-1h]

  v1 = KfRaiseIrql(31);
  v2 = String->Length;
  OldIrql = v1;
  if ( v2 > 0x3000 )
    v2 = 12288;
  if ( &KdPrintWritePointer[v2] > (char *)&KdProcessorState )
  {
    v3 = (char *)&KdProcessorState - KdPrintWritePointer;
    v4 = KdpMoveMemory(KdPrintWritePointer, String->Buffer, (char *)&KdProcessorState - KdPrintWritePointer, 1);
    if ( v4 == v3 )
      v4 += KdpMoveMemory(KdPrintCircularBuffer, &String->Buffer[v3], v2 - v3, 1);
    if ( v4 <= v3 )
    {
      KdPrintWritePointer += v4;
      if ( KdPrintWritePointer < (char *)&KdProcessorState )
        goto LABEL_13;
      KdPrintWritePointer = KdPrintCircularBuffer;
    }
    else
    {
      KdPrintWritePointer = &KdPrintCircularBuffer[v4 - v3];
    }
    ++KdPrintRolloverCount;
    goto LABEL_13;
  }
  KdPrintWritePointer += KdpMoveMemory(KdPrintWritePointer, String->Buffer, v2, 1);
  if ( KdPrintWritePointer >= (char *)&KdProcessorState )
  {
    ++KdPrintRolloverCount;
    KdPrintWritePointer = KdPrintCircularBuffer;
  }
LABEL_13:
  KfLowerIrql(OldIrql);
}
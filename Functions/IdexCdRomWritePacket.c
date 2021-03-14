char __userpurge IdexCdRomWritePacket@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _CDB *Cdb)
{
  signed int v5; // esi
  unsigned __int8 v6; // al

  if ( (_BYTE)dword_8004C5D0 != NewIrql )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == IdexChannelObject.InterruptIrql",
      "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      0x14Eu,
      0);
  __outbyte(0x1F7u, 0xA0u);
  v5 = 1000;
  while ( 1 )
  {
    v6 = __inbyte(0x1F7u);
    if ( (v6 & 0x80u) == 0 )
    {
      if ( v6 & 8 )
        break;
    }
    KeStallExecutionProcessor(0x64u);
    if ( !--v5 )
    {
      KfLowerIrql(2);
      Irp->IoStatus.Status = -1073741643;
      return 0;
    }
  }
  WRITE_PORT_BUFFER_ULONG((PULONG)0x1F0, (PULONG)Cdb, 3u);
  return 1;
}
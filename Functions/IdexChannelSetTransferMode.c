// local variable allocation has failed, the output may be wrong!
int *__userpurge IdexChannelSetTransferMode@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, char TargetDevice, char TransferMode)
{
  int v6; // edx
  int v7; // edx
  int v8; // ecx
  int *result; // eax

  if ( (_BYTE)dword_8004C5D0 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == PASSIVE_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x683u,
      0);
  KfRaiseIrql(NewIrql);
  LOWORD(v6) = 502;
  __outbyte(0x1F6u, 16 * (TargetDevice | 0xFA));
  if ( IdexChannelSpinWhileBusy(&TargetDevice + 3, v6, a3) )
  {
    __outbyte(0x1F1u, 3u);
    __outbyte(0x1F2u, TransferMode);
    LOWORD(v7) = 503;
    __outbyte(0x1F7u, 0xEFu);
    result = IdexChannelBlockOnInitCommand(v8, v7);
  }
  else
  {
    KfLowerIrql(0);
    result = (int *)-1073741643;
  }
  return result;
}
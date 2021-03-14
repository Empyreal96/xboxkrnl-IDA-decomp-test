// local variable allocation has failed, the output may be wrong!
int __userpurge IdexChannelIssueImmediateCommand@<eax>(__int16 a1@<dx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, char TargetDevice, char IdeCommand)
{
  int result; // eax

  if ( (_BYTE)dword_8004C5D0 != NewIrql )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == IdexChannelObject.InterruptIrql",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x6BDu,
      0);
  __outbyte(0x1F6u, 16 * (TargetDevice | 0xFA));
  if ( IdexChannelSpinWhileBusy(&TargetDevice + 3, 502, a3)
    && (__outbyte(0x1F7u, IdeCommand), IdexChannelSpinWhileBusy(&TargetDevice + 3, 503, a3)) )
  {
    result = (*(&TargetDevice + 3) & 1) != 0 ? 0xC0000010 : 0;
  }
  else
  {
    result = -1073741643;
  }
  return result;
}
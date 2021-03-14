// write access to const memory has been detected, the output may be wrong!
int *__fastcall IdexChannelBlockOnInitCommand(int a1, int a2)
{
  int v2; // edx
  int v3; // ecx
  int *result; // eax
  _LARGE_INTEGER Timeout; // [esp+8h] [ebp-8h]

  if ( (_BYTE)dword_8004C5D0 != NewIrql )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0,
      "KeGetCurrentIrql() == IdexChannelObject.InterruptIrql",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x5DBu,
      0);
  IdexChannelInitCommandEvent.Header.Type = 1;
  IdexChannelInitCommandEvent.Header.Size = 4;
  IdexChannelInitCommandEvent.Header.SignalState = 0;
  IdexChannelInitCommandEvent.Header.WaitListHead.Blink = &IdexChannelInitCommandEvent.Header.WaitListHead;
  IdexChannelInitCommandEvent.Header.WaitListHead.Flink = IdexChannelInitCommandEvent.Header.WaitListHead.Blink;
  if ( IdexChannelObject.InterruptRoutine )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0,
      "IdexChannelObject.InterruptRoutine == NULL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x5E8u,
      0);
  IdexChannelObject.InterruptRoutine = (void (__stdcall *)())IdexChannelInitCommandInterrupt;
  dword_80051344 = (void (__stdcall *)(_KDPC *, void *, void *, void *))IdexChannelFinishInitCommand;
  KfLowerIrql(0);
  Timeout.QuadPart = -10000000i64;
  result = KeWaitForSingleObject(v3, v2, &IdexChannelInitCommandEvent, 0, 0, 0, &Timeout);
  if ( (signed int)result >= 0 )
  {
    if ( result == (int *)258 )
      result = (int *)-1073741643;
    else
      result = (int *)((IdexChannelInitCommandIdeStatus & 1) != 0 ? 0xC0000010 : 0);
  }
  IdexChannelObject.InterruptRoutine = 0;
  return result;
}
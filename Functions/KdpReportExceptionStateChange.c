char __userpurge KdpReportExceptionStateChange@<al>(int a1@<esi>, _EXCEPTION_RECORD *ExceptionRecord, _X86_NT5_CONTEXT *ContextRecord, char SecondChance)
{
  int v4; // eax
  _DBGKD_WAIT_STATE_CHANGE64_X86_NT5 WaitStateChange; // [esp+0h] [ebp-3C8h]
  _STRING MessageData; // [esp+3B8h] [ebp-10h]
  _STRING MessageHeader; // [esp+3C0h] [ebp-8h]

  do
  {
    KdpSetStateChange(&WaitStateChange, ExceptionRecord, ContextRecord, SecondChance);
    MessageHeader.Buffer = (char *)&WaitStateChange;
    MessageHeader.Length = 952;
    DumpTraceData(&MessageData);
    LOBYTE(v4) = KdpSendWaitContinue(a1, 7u, &MessageHeader, &MessageData, ContextRecord);
  }
  while ( v4 == 2 );
  return v4;
}
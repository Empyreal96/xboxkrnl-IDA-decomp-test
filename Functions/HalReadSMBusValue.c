int __userpurge HalReadSMBusValue@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, char SlaveAddress, char CommandCode, char ReadWordValue, unsigned int *DataValue)
{
  int v8; // edx
  int v9; // ecx
  _KTHREAD *v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // eax
  _SMBUS_STATUS_BLOCK SMBusStatusBlock; // [esp+4h] [ebp-18h]
  char NumberOfBytes; // [esp+2Ch] [ebp+10h]

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\smbussci.c",
      0x167u,
      0);
  if ( ReadWordValue )
    NumberOfBytes = 2 * ((SlaveAddress & 0xF8) == -32) + 2;
  else
    NumberOfBytes = 1;
  --thread->KernelApcDisable;
  KeWaitForSingleObject(a2, a1, &HalpSMBusLock, 0, 0, 0, 0);
  SMBusStatusBlock.CompletionEvent.Header.WaitListHead.Blink = &SMBusStatusBlock.CompletionEvent.Header.WaitListHead;
  SMBusStatusBlock.CompletionEvent.Header.WaitListHead.Flink = &SMBusStatusBlock.CompletionEvent.Header.WaitListHead;
  SMBusStatusBlock.CompletionEvent.Header.Type = 0;
  SMBusStatusBlock.CompletionEvent.Header.Size = 4;
  SMBusStatusBlock.CompletionEvent.Header.SignalState = 0;
  HalpSMBusStatusBlock = &SMBusStatusBlock;
  HalpKickoffReadSMBus(SlaveAddress, CommandCode, NumberOfBytes);
  KeWaitForSingleObject(v9, v8, &SMBusStatusBlock.CompletionEvent, 0, 0, 0, 0);
  v10 = thread;
  v11 = thread->KernelApcDisable + 1;
  thread->KernelApcDisable = v11;
  if ( !v11 && (_KAPC_STATE *)v10->ApcState.ApcListHead[0].Flink != &v10->ApcState )
  {
    v10->ApcState.KernelApcPending = 1;
    HalRequestSoftwareInterrupt(1);
  }
  if ( NumberOfBytes == 4 )
  {
    *DataValue = SMBusStatusBlock.DataValue;
  }
  else
  {
    v12 = LOWORD(SMBusStatusBlock.DataValue);
    if ( NumberOfBytes != 2 )
      v12 = LOBYTE(SMBusStatusBlock.DataValue);
    *DataValue = v12;
  }
  return SMBusStatusBlock.Status;
}
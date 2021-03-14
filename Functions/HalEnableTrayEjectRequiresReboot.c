char __userpurge HalEnableTrayEjectRequiresReboot@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, char EnterNonSecureMode)
{
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  _KTHREAD *v9; // eax
  unsigned int v10; // ecx
  _SMBUS_STATUS_BLOCK SMBusStatusBlock; // [esp+4h] [ebp-18h]
  char OldIrql; // [esp+27h] [ebp+Bh]

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\smbussci.c",
      0x8A2u,
      0);
  --thread->KernelApcDisable;
  KeWaitForSingleObject(a2, a1, &HalpSMBusLock, 0, 0, 0, 0);
  HalpTrayEjectRequiresReboot = 1;
  if ( KeHasQuickBooted || !EnterNonSecureMode || XboxBootFlags & 8 )
  {
    OldIrql = KeRaiseIrqlToDpcLevel();
    HalpReleaseSMBusLock(v7, v8, a3, a4);
    KfLowerIrql(OldIrql);
  }
  else
  {
    XboxBootFlags |= 8u;
    SMBusStatusBlock.CompletionEvent.Header.WaitListHead.Blink = &SMBusStatusBlock.CompletionEvent.Header.WaitListHead;
    SMBusStatusBlock.CompletionEvent.Header.WaitListHead.Flink = &SMBusStatusBlock.CompletionEvent.Header.WaitListHead;
    SMBusStatusBlock.CompletionEvent.Header.Type = 0;
    SMBusStatusBlock.CompletionEvent.Header.Size = 4;
    SMBusStatusBlock.CompletionEvent.Header.SignalState = 0;
    HalpSMBusStatusBlock = &SMBusStatusBlock;
    HalpKickoffWriteSMBus(32, 25, 1, 1u);
    KeWaitForSingleObject(v6, v5, &SMBusStatusBlock.CompletionEvent, 0, 0, 0, 0);
  }
  v9 = thread;
  v10 = thread->KernelApcDisable + 1;
  thread->KernelApcDisable = v10;
  if ( !v10 && (_KAPC_STATE *)v9->ApcState.ApcListHead[0].Flink != &v9->ApcState )
  {
    v9->ApcState.KernelApcPending = 1;
    HalRequestSoftwareInterrupt(1);
  }
  return HalpTrayEjectDuringBootOccurred;
}
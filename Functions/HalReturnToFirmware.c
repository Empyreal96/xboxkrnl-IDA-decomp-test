void __userpurge __noreturn HalReturnToFirmware(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _FIRMWARE_REENTRY Routine)
{
  KIRQL v5; // al
  _LIST_ENTRY *v6; // esi
  _LIST_ENTRY *v7; // ebx
  _LIST_ENTRY *v8; // edx
  int v9; // edx
  int v10; // ecx
  KIRQL v11; // al
  _LIST_ENTRY *v12; // edx
  int v13; // edx
  int v14; // ecx

  if ( Routine != 2 )
  {
    if ( Routine == 4 )
      HalWriteSMBusValue(a1, a2, a3, a4, 32, 27, 0, 2u);
    if ( Routine != 3 )
      DbgUnLoadImageSymbols(0, (void *)0xFFFFFFFF, 0);
    HalpReboot(a1, a2, a3, a4);
  }
  if ( (_BYTE)dword_8004C5D0 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == PASSIVE_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\ixreboot.c",
      0x9Cu,
      0);
  v5 = KeRaiseIrqlToDpcLevel();
  v6 = HalpShutdownRegistrationList.Flink->Flink;
  v7 = HalpShutdownRegistrationList.Flink;
  v8 = HalpShutdownRegistrationList.Flink->Blink;
  v8->Flink = HalpShutdownRegistrationList.Flink->Flink;
  v6->Blink = v8;
  KfLowerIrql(v5);
  while ( v7 != &HalpShutdownRegistrationList )
  {
    ((void (__stdcall *)(_LIST_ENTRY *))v7[-1].Flink)(&v7[-1]);
    v11 = KeRaiseIrqlToDpcLevel();
    v6 = HalpShutdownRegistrationList.Flink->Flink;
    v7 = HalpShutdownRegistrationList.Flink;
    v12 = HalpShutdownRegistrationList.Flink->Blink;
    v12->Flink = HalpShutdownRegistrationList.Flink->Flink;
    v6->Blink = v12;
    KfLowerIrql(v11);
  }
  IdexChannelPrepareToQuickRebootSystem(v9, v10, (int *)&HalpShutdownRegistrationList, (int)v6);
  if ( KdDebuggerEnabled && !KdDebuggerNotPresent )
    KeWaitForSingleObject(v14, v13, &HalpTrayEjectCompleteEvent, 0, 0, 0, 0);
  DbgUnLoadImageSymbols(0, (void *)0xFFFFFFFF, 0);
  KdDeleteAllBreakpoints((int *)&HalpShutdownRegistrationList);
  KeQuickRebootSystem();
}
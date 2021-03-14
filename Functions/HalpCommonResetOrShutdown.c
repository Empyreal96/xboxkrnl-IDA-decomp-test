void __usercall __noreturn HalpCommonResetOrShutdown(int a1@<edx>, int a2@<ecx>, int *a3@<edi>)
{
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\halx\\i386\\smbussci.c",
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\smbussci.c",
      0x361u,
      0);
  if ( !dword_8004C604 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\halx\\i386\\smbussci.c",
      "KeIsExecutingDpc()",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\smbussci.c",
      0x362u,
      0);
  HalpSMBusCompletionRoutine = HalpWriteSMCAudioClampComplete;
  HalpKickoffWriteSMBus(32, 11, 1, 1u);
  KeRetireDpcListLoop((int)a3, (int)"d:\\xbox-apr03\\private\\ntos\\halx\\i386\\smbussci.c");
}
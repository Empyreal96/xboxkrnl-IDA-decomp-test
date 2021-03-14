KIRQL __usercall KiInitializeKernel@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  char *v4; // edx
  int *v5; // edi
  int v6; // edx
  int v7; // ecx
  int *v8; // eax
  int v9; // edx
  int v10; // ecx

  if ( (unsigned int)&dword_8004C5D0 & 0xF )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "(((ULONG_PTR)&Prcb->NpxSaveArea) % 16) == 0",
      "d:\\xbox-apr03\\private\\ntos\\ke\\i386\\kernlini.c",
      0xC7u,
      0);
  unk_8004C600 = &unk_8004C5FC;
  unk_8004C5FC = &unk_8004C5FC;
  dword_8004C604 = 0;
  KfLowerIrql(1);
  KiInitSystem();
  KeInitializeProcess(&KiIdleProcess, 0);
  KiIdleProcess.ThreadQuantum = 127;
  KeInitializeProcess(&KiSystemProcess, 8);
  KiSystemProcess.ThreadQuantum = 60;
  KeInitializeThread(&KiIdleThread, &KiDoubleFaultStackLimit, 0x3000u, 0, 0, 0, 0, &KiIdleProcess);
  KiIdleThread.Priority = 31;
  KiIdleThread.State = 2;
  KiIdleThread.WaitIrql = 2;
  v4 = (char *)KiIdleThread.StackBase - 528;
  v5 = (int *)((char *)KiIdleThread.StackBase - 528);
  memset((char *)KiIdleThread.StackBase - 528, 0, 0x210u);
  *(_WORD *)v4 = 639;
  *((_DWORD *)v4 + 6) = 8064;
  thread = &KiIdleThread;
  dword_8004C5D8 = 0;
  unk_8004C5DC = &KiIdleThread;
  dword_8004C5B0 = (int)KiIdleThread.StackBase - 528;
  ExpInitializeExecutive(v5 + 132, (int)&KiIdleThread);
  v8 = MmCreateKernelStack(v7, v6, 0x3000u, 0);
  if ( !v8 )
    KeBugCheckEx(0x4Du, 1u, 0, 0, 0);
  dword_8004C608 = (int)v8;
  KfRaiseIrql(2);
  KeSetPriorityThread(v10, v9, &KiIdleThread, 0);
  if ( !dword_8004C5D8 )
    KiIdleSummary |= 1u;
  return KfRaiseIrql(31);
}
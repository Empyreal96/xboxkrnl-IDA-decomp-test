char *__stdcall KiPreInitializeKernel()
{
  char *result; // eax

  KiPCR = -1;
  result = KiIdleThreadStackLimit;
  unk_8004C5C8 = &KiPCR;
  unk_8004C5CC = &thread;
  unk_8004C5B4 = KiIdleThreadStackLimit;
  dword_8004C5B0 = (int)&unk_8004FBB0;
  thread = &KiIdleThread;
  KiIdleThread.NpxState = 10;
  KiIdleThread.StackLimit = KiIdleThreadStackLimit;
  KiIdleThread.StackBase = &KiDoubleFaultStackLimit;
  return result;
}
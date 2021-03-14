char __usercall ExpInitializeExecutive@<al>(int *a1@<edi>, int a2@<esi>)
{
  int v2; // edx
  int v3; // ecx
  void *v4; // ecx
  char result; // al

  if ( KeHasQuickBooted )
    HalInitSystemPhase0Quick();
  else
    HalInitSystemPhase0();
  HalPulseHardwareMonitorPin();
  MmInitSystem(a1, a2);
  if ( !KeHasQuickBooted )
    ExpInitializeHardwareInfo(v2, v3, a1);
  if ( !ObInitSystem(a2) )
    KeBugCheck(0x5Eu);
  result = PsInitSystem(v4, a1, a2);
  if ( !result )
    KeBugCheck(0x60u);
  return result;
}
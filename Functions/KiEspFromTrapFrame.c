unsigned int *__stdcall KiEspFromTrapFrame(_KTRAP_FRAME *TrapFrame)
{
  unsigned int *result; // eax

  if ( TrapFrame->SegCs & 0xFFF8 )
    result = &TrapFrame->HardwareEsp;
  else
    result = (unsigned int *)TrapFrame->TempEsp;
  return result;
}
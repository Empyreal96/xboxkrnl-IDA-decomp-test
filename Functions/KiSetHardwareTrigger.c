void __stdcall KiSetHardwareTrigger()
{
  _InterlockedIncrement((volatile signed __int32 *)&KiHardwareTrigger);
}
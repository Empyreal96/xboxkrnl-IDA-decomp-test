// write access to const memory has been detected, the output may be wrong!
void __stdcall BootSoundDpc(_KDPC *Dpc, void *DeferredContext, void *SystemArgument1, void *SystemArgument2)
{
  ++system_clock_music;
  sos_main();
}
int __stdcall DirectSoundEnterCriticalSection()
{
  if ( KeGetCurrentIrql() )
    return 0;
  RtlEnterCriticalSection(&g_DirectSoundCriticalSection);
  return 1;
}
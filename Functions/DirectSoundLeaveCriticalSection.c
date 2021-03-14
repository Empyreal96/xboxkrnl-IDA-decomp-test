void __thiscall DirectSoundLeaveCriticalSection(void *this)
{
  RtlLeaveCriticalSection(this, (_KEVENT *)&g_DirectSoundCriticalSection);
}
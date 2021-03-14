int __thiscall NtCreateTimer(_ETIMER *this, void **TimerHandle, _OBJECT_ATTRIBUTES *ObjectAttributes, _TIMER_TYPE TimerType)
{
  int result; // eax
  _ETIMER *ExTimer; // [esp+0h] [ebp-4h]

  ExTimer = this;
  if ( TimerType && TimerType != 1 )
    return -1073741811;
  result = ObCreateObject(&ExTimerObjectType, ObjectAttributes, 0x80u, (void **)&ExTimer);
  if ( result >= 0 )
  {
    KeInitializeDpc(&ExTimer->TimerDpc, ExpTimerDpcRoutine, ExTimer);
    KeInitializeTimerEx(&ExTimer->KeTimer, TimerType);
    ExTimer->ApcAssociated = 0;
    result = ObInsertObject(ExTimer, ObjectAttributes, 0, TimerHandle);
  }
  return result;
}
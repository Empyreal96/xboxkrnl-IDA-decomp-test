_KAPC_STATE *__thiscall RtlLeaveCriticalSectionAndRegion(void *this, _KEVENT *Event)
{
  _KAPC_STATE *result; // eax
  bool v3; // zf
  bool v4; // sf
  unsigned __int8 v5; // of
  _KTHREAD *v6; // ecx

  result = 0;
  v3 = Event[1].Header.SignalState-- == 1;
  if ( v3 )
  {
    Event[1].Header.WaitListHead.Flink = 0;
    v5 = __OFSUB__(*(_DWORD *)&Event[1].Header.Type, 1);
    v4 = (*(_DWORD *)&Event[1].Header.Type)-- - 1 < 0;
    if ( !(v4 ^ v5) )
      KeSetEvent((int)this, (int)Event, Event, 1, 0);
    v6 = thread;
    result = (_KAPC_STATE *)(thread->KernelApcDisable + 1);
    thread->KernelApcDisable = (unsigned int)result;
    if ( !result )
    {
      result = &v6->ApcState;
      if ( (_KAPC_STATE *)v6->ApcState.ApcListHead[0].Flink != &v6->ApcState )
      {
        v6->ApcState.KernelApcPending = 1;
        result = (_KAPC_STATE *)HalRequestSoftwareInterrupt(1);
      }
    }
  }
  else
  {
    --*(_DWORD *)&Event[1].Header.Type;
  }
  return result;
}
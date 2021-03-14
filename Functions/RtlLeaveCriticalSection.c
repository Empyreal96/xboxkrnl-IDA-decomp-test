int __thiscall RtlLeaveCriticalSection(void *this, _KEVENT *Event)
{
  int result; // eax
  bool v3; // zf
  bool v4; // sf
  unsigned __int8 v5; // of

  result = 0;
  v3 = Event[1].Header.SignalState-- == 1;
  if ( v3 )
  {
    Event[1].Header.WaitListHead.Flink = 0;
    v5 = __OFSUB__(*(_DWORD *)&Event[1].Header.Type, 1);
    v4 = (*(_DWORD *)&Event[1].Header.Type)-- - 1 < 0;
    if ( !(v4 ^ v5) )
      result = KeSetEvent((int)this, (int)Event, Event, 1, 0);
  }
  else
  {
    --*(_DWORD *)&Event[1].Header.Type;
  }
  return result;
}
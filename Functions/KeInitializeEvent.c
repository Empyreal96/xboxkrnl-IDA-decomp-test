void __stdcall KeInitializeEvent(_KEVENT *Event, _EVENT_TYPE Type, char State)
{
  _KEVENT *v3; // eax

  v3 = Event;
  Event->Header.Type = Type;
  Event->Header.SignalState = (unsigned __int8)State;
  Event->Header.Size = 4;
  v3->Header.WaitListHead.Blink = &v3->Header.WaitListHead;
  v3->Header.WaitListHead.Flink = &v3->Header.WaitListHead;
}
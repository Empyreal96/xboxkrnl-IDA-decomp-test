void __stdcall KeInitializeQueue(_KQUEUE *Queue, unsigned int Count)
{
  _KQUEUE *v2; // eax

  v2 = Queue;
  Queue->Header.SignalState = 0;
  Queue->CurrentCount = 0;
  v2->Header.WaitListHead.Blink = &v2->Header.WaitListHead;
  v2->Header.WaitListHead.Flink = &v2->Header.WaitListHead;
  v2->EntryListHead.Blink = &v2->EntryListHead;
  v2->EntryListHead.Flink = &v2->EntryListHead;
  v2->ThreadListHead.Blink = &v2->ThreadListHead;
  v2->ThreadListHead.Flink = &v2->ThreadListHead;
  Queue->Header.Type = 4;
  Queue->Header.Size = 10;
  if ( Count )
    Queue->MaximumCount = Count;
  else
    Queue->MaximumCount = 1;
}
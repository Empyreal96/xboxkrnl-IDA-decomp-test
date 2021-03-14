_KQUEUE *__fastcall KeRundownQueue(int a1, int a2, _KQUEUE *Queue)
{
  KIRQL v3; // al
  _KQUEUE *v4; // ebx
  _LIST_ENTRY *v5; // edx
  _LIST_ENTRY *v6; // edi
  _LIST_ENTRY *v7; // esi
  _LIST_ENTRY *v8; // edx
  _LIST_ENTRY *v9; // edx

  if ( Queue->Header.Type != 4 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\queueobj.c",
      (int)Queue,
      "(Queue)->Header.Type == QueueObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\queueobj.c",
      0x22Bu,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\queueobj.c",
      (int)Queue,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\queueobj.c",
      0x22Cu,
      0);
  v3 = KeRaiseIrqlToDpcLevel();
  v4 = (_KQUEUE *)Queue->EntryListHead.Flink;
  if ( v4 == (_KQUEUE *)&Queue->EntryListHead )
  {
    v4 = 0;
  }
  else
  {
    v5 = Queue->EntryListHead.Blink;
    v5->Flink = (_LIST_ENTRY *)v4;
    v4->Header.SignalState = (int)v5;
  }
  v6 = &Queue->ThreadListHead;
  while ( 1 )
  {
    v9 = v6->Flink;
    if ( v6->Flink == v6 )
      break;
    v9[-1].Blink = 0;
    v7 = v9->Flink;
    v8 = v9->Blink;
    v8->Flink = v7;
    v7->Blink = v8;
  }
  KiUnlockDispatcherDatabase(v3);
  return v4;
}
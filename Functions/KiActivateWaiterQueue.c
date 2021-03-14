void __fastcall KiActivateWaiterQueue(_KQUEUE *Queue)
{
  _KQUEUE *v1; // edx
  _LIST_ENTRY *v2; // edi
  int v3; // eax
  _DWORD *v4; // esi

  if ( --Queue->CurrentCount < Queue->MaximumCount )
  {
    v1 = (_KQUEUE *)Queue->EntryListHead.Flink;
    v2 = Queue->Header.WaitListHead.Blink;
    if ( v1 != (_KQUEUE *)&Queue->EntryListHead && v2 != &Queue->Header.WaitListHead )
    {
      v3 = *(_DWORD *)&v1->Header.Type;
      v4 = (_DWORD *)v1->Header.SignalState;
      *v4 = *(_DWORD *)&v1->Header.Type;
      *(_DWORD *)(v3 + 4) = v4;
      *(_DWORD *)&v1->Header.Type = 0;
      --Queue->Header.SignalState;
      KiUnwaitThread((_KTHREAD *)v2[1].Flink, (int)v1, 0);
    }
  }
}
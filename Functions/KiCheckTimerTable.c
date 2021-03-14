void __stdcall KiCheckTimerTable(_ULARGE_INTEGER CurrentTime)
{
  _LIST_ENTRY *v1; // edi
  signed int v2; // ebx
  _LIST_ENTRY *v3; // esi
  int v4; // eax
  _LIST_ENTRY *v5; // ecx
  char OldIrql; // [esp+Fh] [ebp-1h]

  OldIrql = KfRaiseIrql(31);
  v1 = KiTimerTableListHead;
  v2 = 32;
  do
  {
    v3 = v1->Flink;
    while ( v3 != v1 )
    {
      v4 = (int)&v3[-3];
      v5 = v3[-1].Blink;
      v3 = v3->Flink;
      if ( __PAIR__((unsigned int)v5, *(_DWORD *)(v4 + 16)) <= CurrentTime.QuadPart )
        DbgBreakPoint();
    }
    ++v1;
    --v2;
  }
  while ( v2 );
  KfLowerIrql(OldIrql);
}
void __fastcall IopDeleteIoCompletion(int a1, int a2, void *Object)
{
  _KQUEUE *v3; // eax
  int v4; // edx
  int v5; // ecx
  _KQUEUE *v6; // edi
  _KQUEUE *v7; // esi
  _KQUEUE *v8; // eax
  bool v9; // zf

  v3 = KeRundownQueue(a1, a2, (_KQUEUE *)Object);
  v6 = v3;
  if ( v3 )
  {
    v7 = v3;
    do
    {
      v8 = v7;
      v9 = v7->Header.WaitListHead.Flink == 0;
      v7 = *(_KQUEUE **)&v7->Header.Type;
      if ( v9 )
        IoFreeIrp(v5, v4, (_IRP *)&v8[-3].ThreadListHead.Blink);
      else
        ExFreePool(v8);
    }
    while ( v6 != v7 );
  }
}
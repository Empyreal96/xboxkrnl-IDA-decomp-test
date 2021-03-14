int __userpurge NtSetEvent@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *EventHandle, int *PreviousState)
{
  int v6; // edx
  int v7; // ecx
  int v8; // edi
  int v9; // esi
  int v10; // edx

  v8 = ObReferenceObjectByHandle(a1, a2, a3, a4, EventHandle, &ExEventObjectType, &EventHandle);
  if ( v8 >= 0 )
  {
    v9 = KeSetEvent(v7, v6, (_KEVENT *)EventHandle, 1, 0);
    ObfDereferenceObject(EventHandle, v10);
    if ( PreviousState )
      *PreviousState = v9;
  }
  return v8;
}
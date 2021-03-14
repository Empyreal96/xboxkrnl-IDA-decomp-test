int __userpurge NtClearEvent@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *EventHandle)
{
  int v5; // edx
  int v6; // esi

  v6 = ObReferenceObjectByHandle(a1, a2, a3, a4, EventHandle, &ExEventObjectType, &EventHandle);
  if ( v6 >= 0 )
  {
    *((_DWORD *)EventHandle + 1) = 0;
    ObfDereferenceObject(EventHandle, v5);
  }
  return v6;
}
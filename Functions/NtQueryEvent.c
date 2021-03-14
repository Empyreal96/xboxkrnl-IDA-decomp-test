int __userpurge NtQueryEvent@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *EventHandle, _EVENT_BASIC_INFORMATION *EventInformation)
{
  int v6; // edx
  int v7; // ebx
  int v8; // esi
  _EVENT_TYPE v9; // edi
  _EVENT_BASIC_INFORMATION *v10; // eax

  v7 = ObReferenceObjectByHandle(a1, a2, a3, a4, EventHandle, &ExEventObjectType, &EventHandle);
  if ( v7 >= 0 )
  {
    v8 = *((_DWORD *)EventHandle + 1);
    v9 = *(unsigned __int8 *)EventHandle;
    ObfDereferenceObject(EventHandle, v6);
    v10 = EventInformation;
    EventInformation->EventType = v9;
    v10->EventState = v8;
  }
  return v7;
}
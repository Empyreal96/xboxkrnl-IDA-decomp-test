int __stdcall NtCreateEvent(void **EventHandle, _OBJECT_ATTRIBUTES *ObjectAttributes, _EVENT_TYPE EventType, char InitialState)
{
  char v4; // bl
  int result; // eax

  v4 = EventType;
  if ( EventType && EventType != 1 )
    return -1073741811;
  result = ObCreateObject(&ExEventObjectType, ObjectAttributes, 0x10u, (void **)&EventType);
  if ( result >= 0 )
  {
    *(_BYTE *)EventType = v4;
    *(_BYTE *)(EventType + 2) = 4;
    *(_DWORD *)(EventType + 4) = (unsigned __int8)InitialState;
    *(_DWORD *)(EventType + 12) = EventType + 8;
    *(_DWORD *)(EventType + 8) = *(_DWORD *)(EventType + 12);
    result = ObInsertObject((void *)EventType, ObjectAttributes, 0, EventHandle);
  }
  return result;
}
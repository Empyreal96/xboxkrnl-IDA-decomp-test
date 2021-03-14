int *__stdcall NtOpenSymbolicLinkObject(void **LinkHandle, _OBJECT_ATTRIBUTES *ObjectAttributes)
{
  return ObOpenObjectByName(ObjectAttributes, &ObSymbolicLinkObjectType, 0, LinkHandle);
}
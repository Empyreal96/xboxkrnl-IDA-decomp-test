int *__stdcall NtOpenDirectoryObject(void **DirectoryHandle, _OBJECT_ATTRIBUTES *ObjectAttributes)
{
  return ObOpenObjectByName(ObjectAttributes, &ObDirectoryObjectType, 0, DirectoryHandle);
}
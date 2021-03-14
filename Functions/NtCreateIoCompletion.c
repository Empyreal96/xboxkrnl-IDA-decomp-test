int __stdcall NtCreateIoCompletion(void **IoCompletionHandle, unsigned int DesiredAccess, _OBJECT_ATTRIBUTES *ObjectAttributes, unsigned int Count)
{
  int result; // eax
  void *Handle; // [esp+0h] [ebp-8h]
  void *IoCompletion; // [esp+4h] [ebp-4h]

  result = ObCreateObject(&IoCompletionObjectType, ObjectAttributes, 0x28u, &IoCompletion);
  if ( result >= 0 )
  {
    KeInitializeQueue((_KQUEUE *)IoCompletion, Count);
    result = ObInsertObject(IoCompletion, ObjectAttributes, 0, &Handle);
    if ( result >= 0 )
      *IoCompletionHandle = Handle;
  }
  return result;
}
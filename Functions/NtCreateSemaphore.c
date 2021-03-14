int __stdcall NtCreateSemaphore(void **SemaphoreHandle, _OBJECT_ATTRIBUTES *ObjectAttributes, int InitialCount, int MaximumCount)
{
  int v4; // esi
  int result; // eax

  if ( MaximumCount <= 0 )
    return -1073741811;
  v4 = InitialCount;
  if ( InitialCount < 0 || InitialCount > MaximumCount )
    return -1073741811;
  result = ObCreateObject(&ExSemaphoreObjectType, ObjectAttributes, 0x14u, (void **)&InitialCount);
  if ( result >= 0 )
  {
    KeInitializeSemaphore((_KSEMAPHORE *)InitialCount, v4, MaximumCount);
    result = ObInsertObject((void *)InitialCount, ObjectAttributes, 0, SemaphoreHandle);
  }
  return result;
}
int __userpurge NtDuplicateObject@<eax>(int a1@<edx>, void *a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *SourceHandle, void **TargetHandle, unsigned int Options)
{
  int result; // eax
  int v8; // esi
  int v9; // edx
  void *Object; // [esp+0h] [ebp-4h]

  Object = a2;
  result = ObReferenceObjectByHandle(a1, (int)a2, a3, a4, SourceHandle, 0, &Object);
  if ( result >= 0 )
  {
    if ( Options & 1 )
      NtClose(a3, SourceHandle);
    v8 = ObOpenObjectByPointer(Object, *((_OBJECT_TYPE **)Object - 2), TargetHandle);
    ObfDereferenceObject(Object, v9);
    result = v8;
  }
  else
  {
    *TargetHandle = 0;
  }
  return result;
}
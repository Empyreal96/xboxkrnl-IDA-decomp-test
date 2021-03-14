int __userpurge ObReferenceObjectByHandle@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *Handle, _OBJECT_TYPE *ObjectType, void **ReturnedObject)
{
  int result; // eax
  _KTHREAD *v8; // edx
  void *v16; // eax
  int v17; // edx

  if ( Handle == (void *)-2 )
  {
    if ( ObjectType != &PsThreadObjectType && ObjectType )
      goto LABEL_4;
    v8 = thread;
    _EAX = 1;
    _ECX = &thread[-1].SuspendSemaphore.Limit;
    __asm { xadd    [ecx], eax }
    *ReturnedObject = v8;
    return 0;
  }
  v16 = (void *)ObpGetObjectHandleReference(a1, a2, a3, a4, Handle);
  if ( !v16 )
  {
    result = -1073741816;
    goto LABEL_13;
  }
  if ( ObjectType == *((_OBJECT_TYPE **)v16 - 2) || !ObjectType )
  {
    *ReturnedObject = v16;
    return 0;
  }
  ObfDereferenceObject(v16, v17);
LABEL_4:
  result = -1073741788;
LABEL_13:
  *ReturnedObject = 0;
  return result;
}
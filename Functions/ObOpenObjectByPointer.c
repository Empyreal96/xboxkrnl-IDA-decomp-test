int __stdcall ObOpenObjectByPointer(void *Object, _OBJECT_TYPE *ObjectType, void **ReturnedHandle)
{
  int result; // eax
  KIRQL v4; // bl
  int v5; // edx
  int v6; // ecx
  void *v7; // esi
  int v8; // edx

  result = ObReferenceObjectByPointer(Object, ObjectType);
  if ( result < 0 )
  {
    v7 = 0;
  }
  else
  {
    v4 = KeRaiseIrqlToDpcLevel();
    v7 = ObpCreateObjectHandle(v6, v5, Object);
    KfLowerIrql(v4);
    if ( v7 )
    {
      result = 0;
    }
    else
    {
      ObfDereferenceObject(Object, v8);
      result = -1073741670;
    }
  }
  *ReturnedHandle = v7;
  return result;
}
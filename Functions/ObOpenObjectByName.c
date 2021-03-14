int *__stdcall ObOpenObjectByName(_OBJECT_ATTRIBUTES *ObjectAttributes, _OBJECT_TYPE *ObjectType, void *ParseContext, void **ReturnedHandle)
{
  int *v4; // edi
  KIRQL v5; // bl
  int v6; // edx
  int v7; // ecx
  void *v8; // esi
  int v9; // edx

  v4 = ObpReferenceObjectByName(
         ObjectAttributes->RootDirectory,
         ObjectAttributes->ObjectName,
         ObjectAttributes->Attributes,
         ObjectType,
         ParseContext,
         &ParseContext);
  if ( (signed int)v4 < 0 )
  {
    v8 = 0;
  }
  else
  {
    v5 = KeRaiseIrqlToDpcLevel();
    v8 = ObpCreateObjectHandle(v7, v6, ParseContext);
    KfLowerIrql(v5);
    if ( !v8 )
    {
      ObfDereferenceObject(ParseContext, v9);
      v4 = (int *)-1073741670;
    }
  }
  *ReturnedHandle = v8;
  return v4;
}
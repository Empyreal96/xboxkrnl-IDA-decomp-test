int *__stdcall NtCreateSymbolicLinkObject(void **LinkHandle, _OBJECT_ATTRIBUTES *ObjectAttributes, _STRING *LinkTarget)
{
  _STRING *v3; // esi
  int *result; // eax
  unsigned int v5; // ebx
  int v6; // edx
  int *v7; // edi
  char **v8; // eax
  void *LinkTargetObject; // [esp+4h] [ebp-4h]

  v3 = LinkTarget;
  result = ObpResolveLinkTarget(LinkTarget, &LinkTargetObject);
  if ( (signed int)result >= 0 )
  {
    v5 = v3->Length;
    v7 = (int *)ObCreateObject(&ObSymbolicLinkObjectType, ObjectAttributes, v5 + 12, (void **)&LinkTarget);
    if ( (signed int)v7 < 0 )
    {
      ObfDereferenceObject(LinkTargetObject, v6);
    }
    else
    {
      v8 = &LinkTarget[1].Buffer;
      qmemcpy(&LinkTarget[1].Buffer, v3->Buffer, v5);
      *(_DWORD *)&LinkTarget->Length = LinkTargetObject;
      *(_DWORD *)&LinkTarget[1].Length = v8;
      LOWORD(LinkTarget->Buffer) = v5;
      HIWORD(LinkTarget->Buffer) = v5;
      v7 = (int *)ObInsertObject(LinkTarget, ObjectAttributes, 0, LinkHandle);
    }
    result = v7;
  }
  return result;
}
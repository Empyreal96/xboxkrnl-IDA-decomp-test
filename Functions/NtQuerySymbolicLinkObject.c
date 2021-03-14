_STRING *__userpurge NtQuerySymbolicLinkObject@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *LinkHandle, _STRING *LinkTarget, unsigned int *ReturnedLength)
{
  _STRING *result; // eax
  _STRING *v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // ecx
  void *v11; // ecx
  unsigned int BytesRequired; // [esp+0h] [ebp-4h]

  result = (_STRING *)ObReferenceObjectByHandle(a1, a2, a3, a4, LinkHandle, &ObSymbolicLinkObjectType, &LinkHandle);
  if ( (signed int)result >= 0 )
  {
    v8 = LinkTarget;
    v9 = LinkTarget->MaximumLength;
    v10 = *((unsigned __int16 *)LinkHandle + 2);
    BytesRequired = *((unsigned __int16 *)LinkHandle + 2);
    if ( v10 > v9 )
    {
      LinkTarget = (_STRING *)-1073741789;
    }
    else
    {
      LinkTarget = 0;
      v9 = v10;
    }
    qmemcpy(v8->Buffer, *((const void **)LinkHandle + 2), v9);
    v11 = LinkHandle;
    v8->Length = v9;
    ObfDereferenceObject(v11, v9);
    if ( ReturnedLength )
      *ReturnedLength = BytesRequired;
    result = LinkTarget;
  }
  return result;
}
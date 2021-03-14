int *__userpurge IopParseFile@<eax>(int *a1@<edi>, int a2@<esi>, void *ParseObject, _OBJECT_TYPE *ObjectType, unsigned int Attributes, _STRING *CompleteName, _STRING *RemainingName, void *Context, void **Object)
{
  int v9; // edx
  int v10; // ST18_4

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v9, v10, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\parse.c", 0x2F4u, 0);
  }
  if ( !Context || *(_WORD *)Context != 8 || *((_WORD *)Context + 1) != 64 )
    return (int *)-1073741788;
  *((_DWORD *)Context + 5) = ParseObject;
  return IoParseDevice(
           a1,
           a2,
           *((void **)ParseObject + 1),
           ObjectType,
           Attributes,
           CompleteName,
           RemainingName,
           Context,
           Object);
}
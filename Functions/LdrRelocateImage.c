unsigned int __userpurge LdrRelocateImage@<eax>(unsigned int a1@<ecx>, int *a2@<edi>, int a3@<esi>, void *NewBase, char *LoaderName, unsigned int Success, unsigned int Conflict, unsigned int Invalid)
{
  int v8; // edx
  int v9; // ST18_4
  _IMAGE_NT_HEADERS *v10; // eax
  int v11; // esi
  void *v12; // eax
  int v13; // edx
  unsigned int TotalCountBytes; // [esp+0h] [ebp-4h]

  TotalCountBytes = a1;
  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a2, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v8, v9, a2, a3, "FALSE", "d:\\xbox-apr03\\private\\ntos\\rtl\\ldrreloc.c", 0x49u, 0);
  }
  v10 = RtlImageNtHeader(NewBase);
  if ( !v10 )
    return Invalid;
  v11 = v10->OptionalHeader.ImageBase;
  v12 = RtlImageDirectoryEntryToData(NewBase, 1, 5u, &TotalCountBytes);
  if ( v12 && TotalCountBytes )
  {
    while ( 1 )
    {
      v13 = *((_DWORD *)v12 + 1);
      TotalCountBytes -= v13;
      v12 = LdrProcessRelocationBlock(
              (int *)NewBase,
              v11,
              (unsigned int)NewBase + *(_DWORD *)v12,
              (unsigned int)(v13 - 8) >> 1,
              (unsigned __int16 *)v12 + 4,
              (int)NewBase - v11);
      if ( !v12 )
        break;
      if ( !TotalCountBytes )
        return Success;
    }
    DbgPrint((int *)NewBase, "%s: Unknown base relocation type\n", LoaderName);
    return Invalid;
  }
  DbgPrint((int *)NewBase, "%s: Image can't be relocated, no fixup information.\n", LoaderName);
  return Conflict;
}
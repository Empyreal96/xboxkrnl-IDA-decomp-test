void __userpurge IdexDiskInitIdentifierString(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, char *IdentifyDataString, char *DiskIdentifierBuffer, unsigned int DiskIdentifierLength, _STRING *DiskIdentifierString)
{
  char *v8; // esi
  char *v9; // ebx
  char *v10; // edi
  int v11; // eax
  char *i; // eax
  char *DiskIdentifierBuffera; // [esp+18h] [ebp+Ch]

  if ( DiskIdentifierLength & 1 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "(DiskIdentifierLength & 1) == 0",
      "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
      0x711u,
      0);
  v8 = DiskIdentifierBuffer;
  v9 = &DiskIdentifierBuffer[DiskIdentifierLength];
  v10 = DiskIdentifierBuffer;
  if ( DiskIdentifierBuffer < &DiskIdentifierBuffer[DiskIdentifierLength] )
  {
    v11 = IdentifyDataString - DiskIdentifierBuffer;
    for ( DiskIdentifierBuffera = (char *)(IdentifyDataString - DiskIdentifierBuffer); ; v11 = (int)DiskIdentifierBuffera )
    {
      *(_WORD *)v10 = RtlUshortByteSwap(*(_WORD *)&v10[v11]);
      v10 += 2;
      if ( v10 >= v9 )
        break;
    }
  }
  for ( i = v9; i > v8 && *(i - 1) == 32; --i )
    ;
  DiskIdentifierString->Buffer = v8;
  DiskIdentifierString->Length = (_WORD)i - (_WORD)v8;
  DiskIdentifierString->MaximumLength = DiskIdentifierLength;
}
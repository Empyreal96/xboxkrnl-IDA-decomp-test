void __userpurge UdfxCopyPartialDirectoryBuffer(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _UDF_DIRECTORY_MAPPING *DirectoryMapping, void *Destination, void *Source, unsigned int Length)
{
  char *v7; // ecx

  if ( Source < DirectoryMapping->CacheBuffer )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
      "(PUCHAR)Source >= (PUCHAR)DirectoryMapping->CacheBuffer",
      "d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
      0xAAu,
      0);
  if ( Source >= (char *)DirectoryMapping->CacheBuffer + 2048 )
    RtlAssert(
      a1,
      a2,
      (int *)0x800,
      (int)"d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
      "(PUCHAR)Source < (PUCHAR)DirectoryMapping->CacheBuffer + UDF_CD_SECTOR_SIZE",
      "d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
      0xACu,
      0);
  v7 = (char *)DirectoryMapping->CacheBuffer + 2048;
  if ( (char *)Source + Length > v7 )
    RtlAssert(
      a1,
      (int)v7,
      (int *)0x800,
      (int)"d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
      "(PUCHAR)Source + Length <= (PUCHAR)DirectoryMapping->CacheBuffer + UDF_CD_SECTOR_SIZE",
      "d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
      0xAEu,
      0);
  if ( Length > 0x800 )
    RtlAssert(
      a1,
      (int)v7,
      (int *)0x800,
      (int)"d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
      "Length <= UDF_CD_SECTOR_SIZE",
      "d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
      0xAFu,
      0);
  qmemcpy(Destination, Source, Length);
}
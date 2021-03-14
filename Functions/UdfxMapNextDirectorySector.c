int __stdcall UdfxMapNextDirectorySector(_UDF_DIRECTORY_MAPPING *DirectoryMapping)
{
  int *v1; // edi
  int result; // eax
  int v3; // edx
  int v4; // ecx
  _UDF_FCB *v5; // eax
  int *v6; // edi
  signed int v7; // ebx
  unsigned int v8; // eax
  unsigned int v9; // eax

  v1 = (int *)&DirectoryMapping->CacheBuffer;
  if ( DirectoryMapping->CacheBuffer )
  {
    FscUnmapBuffer(v1, (int)DirectoryMapping, DirectoryMapping->CacheBuffer);
    *v1 = 0;
  }
  if ( !DirectoryMapping->FileBytesRemaining )
    return -1073741772;
  result = UdfxMapLogicalSector(
             DirectoryMapping->VolumeExtension,
             DirectoryMapping->Irp,
             DirectoryMapping->LogicalSectorNumber,
             (void **)v1);
  if ( result >= 0 )
  {
    v5 = DirectoryMapping->DirectoryFcb;
    ++DirectoryMapping->LogicalSectorNumber;
    v6 = (int *)*v1;
    v7 = 2048;
    if ( v5->Flags & 8 )
    {
      v6 = (int *)((char *)v6 + v5->EmbeddedDataOffset);
      if ( DirectoryMapping->FileBytesRemaining >= 0x800 )
        RtlAssert(
          v3,
          v4,
          v6,
          (int)DirectoryMapping,
          "DirectoryMapping->FileBytesRemaining < UDF_CD_SECTOR_SIZE",
          "d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
          0x67u,
          0);
    }
    v8 = DirectoryMapping->FileBytesRemaining;
    if ( v8 <= 0x800 )
    {
      DirectoryMapping->FileBytesRemaining = 0;
      v7 = v8;
    }
    else
    {
      DirectoryMapping->FileBytesRemaining = v8 - 2048;
    }
    v9 = DirectoryMapping->CacheBytesRemaining;
    DirectoryMapping->CacheBytesRemaining = v7 + v9;
    DirectoryMapping->CurrentBuffer = (char *)v6 - v9;
    result = 0;
  }
  return result;
}
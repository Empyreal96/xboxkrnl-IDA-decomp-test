char *__stdcall RtlImageDirectoryEntryToData(void *Base, char MappedAsImage, unsigned __int16 DirectoryEntry, unsigned int *Size)
{
  void *v4; // ebx
  _IMAGE_NT_HEADERS *v5; // eax
  char *result; // eax

  v4 = Base;
  if ( (unsigned __int8)Base & 1 )
  {
    v4 = (void *)((unsigned int)Base & 0xFFFFFFFE);
    MappedAsImage = 0;
  }
  v5 = RtlImageNtHeader(v4);
  if ( v5 && v5->OptionalHeader.Magic == 267 )
    result = RtlpImageDirectoryEntryToData32(v4, MappedAsImage, DirectoryEntry, Size, v5);
  else
    result = 0;
  return result;
}
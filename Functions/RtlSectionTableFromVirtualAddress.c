_IMAGE_SECTION_HEADER *__stdcall RtlSectionTableFromVirtualAddress(_IMAGE_NT_HEADERS *NtHeaders, void *Base, unsigned int Address)
{
  _IMAGE_SECTION_HEADER *result; // eax
  int v4; // esi
  unsigned int v5; // edx

  result = (_IMAGE_SECTION_HEADER *)((char *)&NtHeaders->OptionalHeader + NtHeaders->FileHeader.SizeOfOptionalHeader);
  v4 = 0;
  if ( !NtHeaders->FileHeader.NumberOfSections )
    return 0;
  while ( 1 )
  {
    v5 = result->VirtualAddress;
    if ( Address >= v5 && Address < v5 + result->SizeOfRawData )
      break;
    ++result;
    if ( ++v4 >= (unsigned int)NtHeaders->FileHeader.NumberOfSections )
      return 0;
  }
  return result;
}
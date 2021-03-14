char *__stdcall RtlpImageDirectoryEntryToData32(void *Base, char MappedAsImage, unsigned __int16 DirectoryEntry, unsigned int *Size, _IMAGE_NT_HEADERS *NtHeaders)
{
  unsigned int v5; // eax
  char *result; // eax

  if ( DirectoryEntry >= NtHeaders->OptionalHeader.NumberOfRvaAndSizes )
    return 0;
  v5 = NtHeaders->OptionalHeader.DataDirectory[DirectoryEntry].VirtualAddress;
  if ( !v5 )
    return 0;
  if ( (unsigned int)Base < 0x7FFEFFFF && (unsigned int)Base + v5 >= 0x7FFEFFFF )
    return 0;
  *Size = NtHeaders->OptionalHeader.DataDirectory[DirectoryEntry].Size;
  if ( MappedAsImage || v5 < NtHeaders->OptionalHeader.SizeOfHeaders )
    result = (char *)Base + v5;
  else
    result = RtlAddressInSectionTable(NtHeaders, Base, v5);
  return result;
}
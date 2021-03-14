char *__stdcall RtlAddressInSectionTable(_IMAGE_NT_HEADERS *NtHeaders, void *Base, unsigned int Address)
{
  _IMAGE_SECTION_HEADER *v3; // eax
  char *result; // eax

  v3 = RtlSectionTableFromVirtualAddress(NtHeaders, Base, Address);
  if ( v3 )
    result = (char *)Base + v3->PointerToRawData - v3->VirtualAddress + Address;
  else
    result = 0;
  return result;
}
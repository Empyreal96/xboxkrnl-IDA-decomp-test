int __stdcall RtlUnicodeToMultiByteSize(unsigned int *BytesInMultiByteString, unsigned __int16 *UnicodeString, unsigned int BytesInUnicodeString)
{
  *BytesInMultiByteString = BytesInUnicodeString >> 1;
  return 0;
}
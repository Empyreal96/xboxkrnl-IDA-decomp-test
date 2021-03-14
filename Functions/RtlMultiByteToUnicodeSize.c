int __stdcall RtlMultiByteToUnicodeSize(unsigned int *BytesInUnicodeString, char *MultiByteString, unsigned int BytesInMultiByteString)
{
  *BytesInUnicodeString = 2 * BytesInMultiByteString;
  return 0;
}
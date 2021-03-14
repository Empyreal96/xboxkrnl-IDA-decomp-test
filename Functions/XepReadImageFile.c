int __userpurge XepReadImageFile@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, void *ImageFileHandle, void *Buffer, unsigned int Length, unsigned int ByteOffset)
{
  int result; // eax
  _IO_STATUS_BLOCK IoStatusBlock; // [esp+4h] [ebp-10h]
  _LARGE_INTEGER ByteOffsetLarge; // [esp+Ch] [ebp-8h]

  ByteOffsetLarge.QuadPart = ByteOffset;
  result = NtReadFile(a1, a2, a3, ImageFileHandle, 0, 0, 0, &IoStatusBlock, Buffer, Length, &ByteOffsetLarge);
  if ( result >= 0 && IoStatusBlock.Information != Length )
    result = -1073741566;
  return result;
}
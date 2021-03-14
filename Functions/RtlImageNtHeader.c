_IMAGE_NT_HEADERS *__stdcall RtlImageNtHeader(void *Base)
{
  _IMAGE_NT_HEADERS *result; // eax

  result = 0;
  if ( Base && Base != (void *)-1 && *(_WORD *)Base == 23117 )
  {
    if ( (result = (_IMAGE_NT_HEADERS *)((char *)Base + *((_DWORD *)Base + 15)), (unsigned int)Base < 0x7FFEFFFF)
      && ((unsigned int)result >= 0x7FFEFFFF || (unsigned int)&result[1] >= 0x7FFEFFFF)
      || result->Signature != 17744 )
    {
      result = 0;
    }
  }
  return result;
}
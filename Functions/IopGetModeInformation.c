unsigned int __stdcall IopGetModeInformation(_FILE_OBJECT *FileObject)
{
  char v1; // cl
  unsigned int result; // eax

  v1 = FileObject->Flags;
  result = 0;
  if ( v1 & 8 )
    result = 4;
  if ( v1 & 4 )
    result |= 8u;
  if ( v1 & 1 )
  {
    if ( v1 & 2 )
      result |= 0x10u;
    else
      result |= 0x20u;
  }
  return result;
}
int __stdcall FatxCheckDesiredAccess(unsigned int DesiredAccess, unsigned int CreateOptions, char FileAttributes, char CreatingFile)
{
  int result; // eax

  if ( FileAttributes & 0xC8 || DesiredAccess & 0xFEE0FE00 )
    return -1073741790;
  if ( !(FileAttributes & 1) )
    goto LABEL_12;
  if ( !CreatingFile && DesiredAccess & 0xFEE0FE46 )
    return -1073741790;
  if ( CreateOptions & 0x1000 )
    result = -1073741535;
  else
LABEL_12:
    result = 0;
  return result;
}
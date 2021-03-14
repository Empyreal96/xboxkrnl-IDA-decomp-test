int __stdcall SymNumFor(unsigned int pc)
{
  int result; // eax

  result = 0;
  if ( !NumTraceDataSyms )
    return -1;
  while ( *(_DWORD *)(8 * result - 2147117568) > pc || *(_DWORD *)(8 * result - 2147117564) <= pc )
  {
    if ( ++result >= (unsigned int)(unsigned __int8)NumTraceDataSyms )
      return -1;
  }
  return result;
}
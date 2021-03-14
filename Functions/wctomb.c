int __cdecl wctomb(char *s, unsigned __int16 wchar)
{
  int result; // eax

  if ( !s )
    return 0;
  if ( wchar <= 0xFFu )
  {
    *s = wchar;
    result = 1;
  }
  else
  {
    errno = 42;
    result = -1;
  }
  return result;
}
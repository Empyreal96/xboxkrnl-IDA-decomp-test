unsigned __int64 __stdcall _allmul(__int64 a1, __int64 a2)
{
  unsigned __int64 result; // rax

  if ( HIDWORD(a1) | HIDWORD(a2) )
    result = a1 * a2;
  else
    result = (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
  return result;
}
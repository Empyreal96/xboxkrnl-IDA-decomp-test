double __stdcall fast_acos(float x)
{
  if ( x >= 0.0 )
  {
    if ( x != 0.0 )
    {
      if ( LODWORD(x) < 0x3F800000 )
        return 1.5707964 - fast_asin(x);
      return 0.0;
    }
    return 1.5707964;
  }
  if ( !(LODWORD(x) & 0x7FFFFFFF) )
    return 1.5707964;
  if ( (LODWORD(x) & 0x7FFFFFFFu) < 0xBF800000 )
    return 1.5707964 - fast_asin(x);
  return 3.1415927;
}
double __stdcall AngleFromSinCos(const float *s, const float *c)
{
  double result; // st7

  if ( *s <= -1.0 )
    return -1.5707964;
  if ( *s >= 1.0 )
    return 1.5707964;
  if ( *c <= -1.0 )
    return 3.1415927;
  if ( *c >= 1.0 )
    return 0.0;
  if ( *s >= 0.1 || *s <= -0.1 )
  {
    result = fast_acos(*c);
    if ( *s < 0.0 )
      result = -result;
  }
  else
  {
    result = fast_asin(*s);
    if ( *c < 0.0 )
    {
      result = 3.1415927 - result;
      if ( result > 3.1415927 )
        result = result - 6.2831855;
    }
  }
  return result;
}
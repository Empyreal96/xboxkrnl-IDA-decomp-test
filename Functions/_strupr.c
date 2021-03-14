char *__cdecl _strupr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  result = string;
  for ( i = string; *i; ++i )
  {
    v3 = *i;
    if ( *i >= 97 && v3 <= 122 )
      *i = v3 - 32;
  }
  return result;
}
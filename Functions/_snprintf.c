int __usercall _snprintf@<eax>(int *a1@<edi>, char *string, unsigned int count, const char *format, ...)
{
  int v4; // edi
  _iobuf str; // [esp+8h] [ebp-20h]
  va_list argptr; // [esp+3Ch] [ebp+14h]

  va_start(argptr, format);
  str._cnt = count;
  str._flag = 66;
  str._base = string;
  str._ptr = string;
  v4 = _output(a1, &str, format, argptr);
  if ( string )
  {
    if ( --str._cnt < 0 )
      _flsbuf(0, &str);
    else
      *str._ptr = 0;
  }
  return v4;
}
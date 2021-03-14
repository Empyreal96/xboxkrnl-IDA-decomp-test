int __usercall sprintf@<eax>(int *a1@<edi>, char *string, const char *format, ...)
{
  int v3; // edi
  _iobuf str; // [esp+8h] [ebp-20h]
  va_list argptr; // [esp+38h] [ebp+10h]

  va_start(argptr, format);
  str._cnt = 0x7FFFFFFF;
  str._flag = 66;
  str._base = string;
  str._ptr = string;
  v3 = _output(a1, &str, format, argptr);
  if ( string )
  {
    if ( --str._cnt < 0 )
      _flsbuf(0, &str);
    else
      *str._ptr = 0;
  }
  return v3;
}
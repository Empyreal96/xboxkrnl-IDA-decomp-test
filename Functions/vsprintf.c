int __usercall vsprintf@<eax>(int *a1@<edi>, char *string, const char *format, char *ap)
{
  int v4; // edi
  _iobuf str; // [esp+8h] [ebp-20h]

  str._cnt = 0x7FFFFFFF;
  str._flag = 66;
  str._base = string;
  str._ptr = string;
  v4 = _output(a1, &str, format, ap);
  if ( string )
  {
    if ( --str._cnt < 0 )
      _flsbuf(0, &str);
    else
      *str._ptr = 0;
  }
  return v4;
}
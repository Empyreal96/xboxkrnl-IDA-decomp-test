int __cdecl _flsbuf(int ch, _iobuf *str)
{
  str->_flag |= 0x20u;
  return -1;
}
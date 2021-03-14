int __usercall write_char@<eax>(_iobuf *str@<ecx>, int result@<eax>, _DWORD *a3@<esi>)
{
  bool v3; // sf

  if ( str->_flag & 0x40 && !str->_base
    || ((v3 = str->_cnt - 1 < 0, --str->_cnt, v3) ? (result = _flsbuf((char)result, str)) : (*str->_ptr = result,
                                                                                             ++str->_ptr,
                                                                                             result = (unsigned __int8)result),
        result != -1) )
  {
    ++*a3;
  }
  else
  {
    *a3 = -1;
  }
  return result;
}
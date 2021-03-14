unsigned __int64 __usercall _aullshr@<edx:eax>(unsigned __int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  unsigned __int64 result; // rax

  if ( a2 >= 0x40u )
    result = 0i64;
  else
    result = a1 >> a2;
  return result;
}
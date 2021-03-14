int __userpurge RtlFillMemory@<eax>(int a1@<eax>, char *a2, unsigned int a3, char a4)
{
  int result; // eax

  LOBYTE(a1) = a4;
  BYTE1(a1) = a4;
  result = a1 << 16;
  LOBYTE(result) = a4;
  BYTE1(result) = a4;
  memset32(a2, result, a3 >> 2);
  if ( a3 & 3 )
    memset(&a2[4 * (a3 >> 2)], a4, a3 & 3);
  return result;
}
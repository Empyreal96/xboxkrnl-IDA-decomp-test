void __userpurge SetValDWORD(int a1@<ebx>, unsigned int *num, unsigned int val, unsigned int len)
{
  unsigned int v4; // edx
  int v5; // eax

  *num = val;
  v4 = 4 * len - 4;
  LOBYTE(a1) = -((val & 0x80000000) != 0);
  BYTE1(a1) = -((val & 0x80000000) != 0);
  v5 = a1 << 16;
  LOWORD(v5) = a1;
  memset32(num + 1, v5, v4 >> 2);
  memset(&num[(v4 >> 2) + 1], a1, v4 & 3);
}
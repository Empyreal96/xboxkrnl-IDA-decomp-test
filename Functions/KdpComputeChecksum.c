unsigned int __stdcall KdpComputeChecksum(char *Buffer, unsigned int Length)
{
  unsigned int v2; // edx
  unsigned int result; // eax
  char *v4; // ecx

  v2 = Length;
  result = 0;
  if ( Length )
  {
    v4 = Buffer;
    do
    {
      result += (unsigned __int8)*v4++;
      --v2;
    }
    while ( v2 );
  }
  return result;
}
void __stdcall DWORDToBigEndian(char *block, unsigned int *x, unsigned int digits)
{
  unsigned int v3; // esi
  char *v4; // ecx
  char *v5; // eax

  v3 = digits;
  if ( digits )
  {
    v4 = block + 1;
    v5 = (char *)x + 2;
    do
    {
      *(v4 - 1) = v5[1];
      *v4 = *v5;
      v4[1] = *(v5 - 1);
      v4[2] = *(v5 - 2);
      v5 += 4;
      v4 += 4;
      --v3;
    }
    while ( v3 );
  }
}
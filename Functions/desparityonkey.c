void __stdcall desparityonkey(char *pbKey, unsigned int cbKey)
{
  unsigned int v2; // edx
  unsigned __int8 v3; // cl
  bool v4; // zf
  signed int v5; // ebx

  v2 = 0;
  if ( cbKey )
  {
    do
    {
      v3 = pbKey[v2];
      v5 = ((unsigned __int8)DESParityTable[v3 & 0xF] + (unsigned __int8)DESParityTable[(unsigned int)v3 >> 4]) & 0x80000001;
      v4 = v5 == 0;
      if ( v5 < 0 )
        v4 = (((_BYTE)v5 - 1) | 0xFFFFFFFE) == -1;
      if ( v4 )
        pbKey[v2] = v3 ^ 1;
      ++v2;
    }
    while ( v2 < cbKey );
  }
}
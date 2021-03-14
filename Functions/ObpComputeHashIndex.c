unsigned int __fastcall ObpComputeHashIndex(_STRING *ElementName)
{
  char *v1; // edx
  unsigned int v2; // ecx
  unsigned int v3; // esi
  unsigned __int8 v4; // al

  v1 = ElementName->Buffer;
  v2 = (unsigned int)&v1[ElementName->Length];
  v3 = 0;
  while ( (unsigned int)v1 < v2 )
  {
    v4 = *v1++;
    if ( v4 < 0x80u )
      v3 = (v3 >> 1) + (v4 | 0x20) + 3 * v3;
  }
  return v3 % 0xB;
}
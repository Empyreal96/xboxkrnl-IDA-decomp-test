int __stdcall BSafeEncPublic(BSAFE_PUB_KEY *const key, const char *part_in, char *part_out)
{
  int *v3; // ebp
  int v4; // edi
  int result; // eax
  unsigned int v6; // esi
  int v7; // edx
  int v8; // ecx
  unsigned int v9; // esi
  int *v10; // eax
  unsigned int *v11; // edx
  int len; // [esp+10h] [ebp-8Ch]
  unsigned int dwTemp[34]; // [esp+14h] [ebp-88h]

  v3 = 0;
  v4 = 0;
  if ( key->magic != 826364754 )
    return 0;
  v6 = (key->bitlen >> 6) + 1;
  if ( (key->bitlen >> 1) & 0x1F )
    v6 = (key->bitlen >> 6) + 2;
  result = 1;
  if ( key->pubexp == 1 )
  {
    qmemcpy(part_out, part_in, 8 * v6);
    return result;
  }
  len = 2 * v6;
  if ( Compare((unsigned int *)part_in, &key[1].magic, 2 * v6) < 0 )
  {
    v9 = 8 * v6;
    if ( v9 <= 0x88 )
    {
      v11 = dwTemp;
LABEL_12:
      memset(v11, 0, v9);
      *v11 = key->pubexp;
      v4 = BenalohModExp((int)key, (unsigned int *)part_out, (unsigned int *)part_in, v11, &key[1].magic, len);
      if ( v3 )
        RSA32Free(v3);
      return v4;
    }
    v10 = RSA32Alloc(v7, v8, v9, v9);
    v3 = v10;
    if ( v10 )
    {
      v11 = (unsigned int *)v10;
      goto LABEL_12;
    }
  }
  return v4;
}
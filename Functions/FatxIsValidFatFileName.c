char __stdcall FatxIsValidFatFileName(_STRING *FileName)
{
  unsigned __int16 v1; // cx
  char *v2; // eax
  unsigned int v3; // esi
  signed int v5; // edi
  unsigned int v6; // edx

  v1 = FileName->Length;
  if ( !FileName->Length )
    return 0;
  if ( v1 > 0x2Au )
    return 0;
  v2 = FileName->Buffer;
  v3 = (unsigned int)&v2[v1];
  if ( *v2 == 46 && (v1 == 1 || v1 == 2 && v2[1] == 46) )
    return 0;
  while ( (unsigned int)v2 < v3 )
  {
    v5 = 1 << (*v2 & 0x1F);
    v6 = (unsigned int)(unsigned __int8)*v2++ >> 5;
    if ( v5 & *(_DWORD *)(4 * v6 - 2147385584) )
      return 0;
  }
  return 1;
}
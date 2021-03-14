char *__stdcall KiSwapGDT()
{
  char *result; // eax
  unsigned int v1; // ecx
  char v2; // dl

  result = KiGDT;
  if ( KiGDT < (char *)KiDataSectionDigest )
  {
    result = (char *)&unk_8005FBAE;
    v1 = ((unsigned int)((char *)KiDataSectionDigest - KiGDT - 1) >> 3) + 1;
    do
    {
      v2 = *(result - 1);
      *(result - 1) = *result;
      *result = result[1];
      result[1] = v2;
      result += 8;
      --v1;
    }
    while ( v1 );
  }
  return result;
}
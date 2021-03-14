char *__stdcall KiSwapIDT()
{
  char *result; // eax
  unsigned int v1; // ecx
  __int16 v2; // dx

  result = KiIDT;
  if ( KiIDT < (char *)KiIDTEnd )
  {
    result = (char *)&unk_8004BC0E;
    v1 = ((unsigned int)((char *)KiIDTEnd - KiIDT - 1) >> 3) + 1;
    do
    {
      v2 = *((_WORD *)result - 2);
      *((_WORD *)result - 2) = *(_WORD *)result;
      *(_WORD *)result = v2;
      result += 8;
      --v1;
    }
    while ( v1 );
  }
  return result;
}
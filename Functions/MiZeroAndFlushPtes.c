char *__fastcall MiZeroAndFlushPtes(_DWORD *a1, int a2)
{
  char *result; // eax

  if ( !a2 )
    __debugbreak();
  result = (char *)((_DWORD)a1 << 10);
  do
  {
    *a1 = 0;
    __invlpg(result);
    ++a1;
    result += 4096;
    --a2;
  }
  while ( a2 );
  return result;
}
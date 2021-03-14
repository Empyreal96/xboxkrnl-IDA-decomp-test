int __cdecl _abnormal_termination()
{
  int result; // eax
  int v1; // ecx

  result = 0;
  if ( *(signed int (__cdecl **)(int, int, int, _DWORD *))(v1 + 4) == ___00003_19
    && *(_DWORD *)(v1 + 8) == *(_DWORD *)(*(_DWORD *)(v1 + 12) + 12) )
  {
    result = 1;
  }
  return result;
}
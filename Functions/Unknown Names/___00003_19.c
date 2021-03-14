signed int __cdecl ___00003_19(int a1, int a2, int a3, _DWORD *a4)
{
  signed int result; // eax

  result = 1;
  if ( *(_DWORD *)(a1 + 4) & 6 )
  {
    *a4 = a2;
    result = 3;
  }
  return result;
}
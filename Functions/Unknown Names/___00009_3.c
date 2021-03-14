signed int __stdcall ___00009_3(int a1, int a2, int a3, _DWORD *a4)
{
  signed int result; // eax

  result = 1;
  if ( *(_DWORD *)(a1 + 4) & 6 )
  {
    *a4 = *(_DWORD *)(a2 + 8);
    result = 3;
  }
  return result;
}
int __cdecl wcslen(const unsigned __int16 *wcs)
{
  const unsigned __int16 *v1; // eax
  unsigned __int16 v2; // cx

  v1 = wcs;
  do
  {
    v2 = *v1;
    ++v1;
  }
  while ( v2 );
  return v1 - wcs - 1;
}
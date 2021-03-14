unsigned __int16 *__userpurge LogoRenderer::decompressIndexData@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, char *pdata, int ncount)
{
  unsigned __int16 *result; // eax
  char *v6; // esi
  int v7; // ecx
  char v8; // dl
  __int16 v9; // dx
  unsigned __int16 v10; // dx

  result = (unsigned __int16 *)MemAlloc(a1, a2, a3, 2 * ncount);
  v6 = pdata;
  v7 = 1;
  for ( *result = *pdata; v7 < ncount; ++v7 )
  {
    v8 = v6[v7];
    if ( v8 == 126 )
    {
      LOBYTE(v9) = v6[v7 + 2];
      HIBYTE(v9) = v6[v7 + 1];
      v10 = result[v7 - 1] + v9;
      v6 += 2;
    }
    else
    {
      v10 = result[v7 - 1] + v8;
    }
    result[v7] = v10;
  }
  return result;
}
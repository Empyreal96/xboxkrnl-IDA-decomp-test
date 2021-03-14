__int16 *__userpurge SceneRenderer::decompressIndices@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, char *p_indices, int nindices)
{
  __int16 *result; // eax
  char *v6; // esi
  __int16 v7; // dx
  int i; // ecx
  char v9; // dl
  __int16 v10; // dx
  __int16 v11; // dx

  result = (__int16 *)MemAlloc(a1, a2, a3, 2 * nindices);
  v6 = p_indices;
  if ( *p_indices == 127 )
  {
    HIBYTE(v7) = p_indices[1];
    v6 = p_indices + 2;
    LOBYTE(v7) = p_indices[2];
    *result = v7;
  }
  else
  {
    *result = *p_indices;
  }
  for ( i = 1; i < nindices; ++i )
  {
    v9 = v6[i];
    if ( v9 == 127 )
    {
      HIBYTE(v10) = v6[i + 1];
      LOBYTE(v10) = v6[i + 2];
      v11 = result[i - 1] + v10;
      v6 += 2;
    }
    else
    {
      v11 = result[i - 1] + v9;
    }
    result[i] = v11;
  }
  return result;
}
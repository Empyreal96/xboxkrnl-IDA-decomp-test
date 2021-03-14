void __thiscall PrimitiveSet::initSurfOfRevVersion(PrimitiveSet *this, SurfOfRevVers *psurf, int idx, int ndet_bias)
{
  PrimitiveSet *v4; // edi
  signed int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  unsigned int dwDupVerts; // [esp+Ch] [ebp-4h]

  v4 = this;
  v5 = psurf->nPts;
  v6 = 0;
  dwDupVerts = 0;
  if ( v5 > 0 )
  {
    v7 = 0;
    do
    {
      if ( !(psurf->pts[v7].flags & 1) )
        ++dwDupVerts;
      v7 = (unsigned __int16)++v6;
    }
    while ( (unsigned __int16)v6 < v5 );
  }
  v8 = psurf->nSegs >> ndet_bias;
  v9 = idx;
  v4->aVersRecs[v9].dwVertexCount = (v8 + 1) * (dwDupVerts + psurf->nPts);
  v4->aVersRecs[v9].dwPrimCount = 2 * v8 * (psurf->nPts + dwDupVerts + 1) - 2;
  v4->aVersRecs[idx].dwIndexCount = v4->aVersRecs[idx].dwPrimCount + 2;
}
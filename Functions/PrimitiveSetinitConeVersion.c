void __thiscall PrimitiveSet::initConeVersion(PrimitiveSet *this, ConeVers *pcone, int idx, int ndet_bias)
{
  PrimitiveSet *v4; // ebx
  int v5; // edi
  int v6; // esi

  v4 = this;
  v5 = pcone->nSides >> ndet_bias;
  v6 = idx;
  this->aVersRecs[v6].dwVertexCount = (v5 + 1) * (pcone->nHeightSeg + 1) + 2 * v5 + 2;
  this->aVersRecs[v6].dwPrimCount = 0;
  this->aVersRecs[v6].dwIndexCount = 2 * v5 + GetNumberOfIndicesForTristripMesh(v5, pcone->nHeightSeg, 0, 0);
  v4->aVersRecs[v6].dwParameter = v5;
}
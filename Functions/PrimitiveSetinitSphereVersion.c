void __thiscall PrimitiveSet::initSphereVersion(PrimitiveSet *this, SphereVers *psphere, int idx, int ndet_bias)
{
  PrimitiveSet *v4; // edx
  PrimitiveVersionRecord *v5; // ebx
  unsigned int v6; // esi
  int v7; // eax
  int v8; // ecx

  v4 = this;
  v5 = this->aVersRecs;
  v6 = (char)(psphere->nSegs >> ndet_bias);
  v7 = idx;
  v8 = (v6 + 1) * ((v6 >> 1) - 1);
  v5[v7].dwVertexCount = v6 * (v6 >> 1);
  v4->aVersRecs[v7].dwPrimCount = 2 * v8 - 2;
  v4->aVersRecs[idx].dwIndexCount = v4->aVersRecs[idx].dwPrimCount + 2;
}
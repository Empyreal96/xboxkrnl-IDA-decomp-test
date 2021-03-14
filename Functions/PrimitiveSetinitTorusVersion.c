void __thiscall PrimitiveSet::initTorusVersion(PrimitiveSet *this, TorusVers *ptorus, int idx, int ndet_bias)
{
  int v4; // esi
  int v5; // eax
  int v6; // edx

  v4 = ptorus->nSides >> ndet_bias;
  v5 = idx;
  v6 = v4 * ((ptorus->nSegs >> ndet_bias) + 1);
  this->aVersRecs[v5].dwVertexCount = v4 * (ptorus->nSegs >> ndet_bias);
  this->aVersRecs[v5].dwPrimCount = 2 * v6 - 2;
  this->aVersRecs[idx].dwIndexCount = this->aVersRecs[idx].dwPrimCount + 2;
}
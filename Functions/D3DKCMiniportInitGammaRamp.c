void __thiscall D3DK::CMiniport::InitGammaRamp(D3DK::CMiniport *this, unsigned int RampNo)
{
  _D3DGAMMARAMP *v2; // eax
  char *v3; // edx
  _D3DGAMMARAMP *v4; // edi
  unsigned int v5; // ecx
  int v6; // edi
  int v7; // esi
  char *v8; // eax

  v2 = &this->m_GammaRamp[RampNo];
  v3 = this->m_GammaRamp[RampNo].green;
  v4 = &this->m_GammaRamp[RampNo];
  v5 = 0;
  v6 = (char *)v4 - v3;
  v7 = (char *)v2 - v3 + 512;
  do
  {
    v8 = &v3[v5];
    v8[v6] = v5;
    *v8 = v5;
    v8[v7] = v5++;
  }
  while ( v5 < 0x100 );
}
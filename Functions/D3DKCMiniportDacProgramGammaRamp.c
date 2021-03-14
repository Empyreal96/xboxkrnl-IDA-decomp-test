void __thiscall D3DK::CMiniport::DacProgramGammaRamp(D3DK::CMiniport *this, _D3DGAMMARAMP *GammaRamp)
{
  _BYTE *v2; // eax
  char *v3; // ecx
  signed int v4; // esi
  char v5; // dl

  v2 = this->m_RegisterBase;
  *((_BYTE *)this->m_RegisterBase + 6820808) = 0;
  v3 = GammaRamp->green;
  v4 = 256;
  do
  {
    v2[6820809] = *(v3 - 256);
    v2[6820809] = *v3;
    v5 = (v3++)[256];
    --v4;
    v2[6820809] = v5;
  }
  while ( v4 );
}
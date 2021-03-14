int __thiscall D3DK::CMiniport::InitEngines(D3DK::CMiniport *this)
{
  D3DK::CMiniport *v1; // esi
  _DWORD *v2; // edi
  signed int v3; // ecx
  unsigned int i; // ebx
  int den; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = this->m_RegisterBase;
  v2[1548] = 0;
  v2[1539] = 63488;
  D3DK::CMiniport::HalMcControlInit(this);
  v3 = v1->m_DacInfo.NVClk;
  v1->m_GenInfo.ChipIntrEn0 = 1;
  for ( den = 31250000; !(v3 % 2) && !(den % 2); den /= 2 )
    v3 /= 2;
  while ( !(v3 % 5) && !(den % 5) )
  {
    den /= 5;
    v3 /= 5;
  }
  for ( i = den; (unsigned int)v3 > 0x1FFFE || i > 0x1FFFE; i = (signed int)i / 2 )
    v3 /= 2;
  v2[9344] = (v3 + 1) / 2;
  v2[9348] = (signed int)(i + 1) / 2;
  v2[9480] = -1;
  D3DK::CMiniport::HalFbControlInit(v1);
  D3DK::CMiniport::HalDacControlInit(v1);
  D3DK::CMiniport::InitGammaRamp(v1, 0);
  D3DK::CMiniport::HalVideoControlInit(v1);
  v1->m_HalInfo.GrChID = 2;
  D3DK::CMiniport::HalGrControlInit(v1);
  D3DK::CMiniport::HalFifoControlInit(v1);
  return 1;
}
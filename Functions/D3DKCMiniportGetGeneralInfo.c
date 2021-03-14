int __thiscall D3DK::CMiniport::GetGeneralInfo(D3DK::CMiniport *this)
{
  _DWORD *v1; // edx

  v1 = this->m_RegisterBase;
  this->m_GenInfo.ChipId = (*((_DWORD *)this->m_RegisterBase + 1536) >> 16) & 0xFFFC;
  this->m_GenInfo.MaskRevision = v1[1538] & 0xFF;
  this->m_GenInfo.VideoRamSize = v1[262275];
  this->m_GenInfo.CrystalFreq = 16666666;
  return 1;
}
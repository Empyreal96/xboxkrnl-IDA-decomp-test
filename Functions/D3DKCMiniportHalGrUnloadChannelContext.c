void __thiscall D3DK::CMiniport::HalGrUnloadChannelContext(D3DK::CMiniport *this, unsigned int ChID)
{
  _DWORD *v2; // esi

  v2 = this->m_RegisterBase;
  if ( ChID != 2 )
  {
    v2[1049057] = this->m_HalInfo.GrCtxTable[ChID] & 0xFFFF;
    v2[1049058] = 2;
    D3DK::CMiniport::HalGrIdle(this, 2);
    v2[1048657] = 0x10000000;
  }
}
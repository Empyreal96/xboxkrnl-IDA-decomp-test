int __thiscall D3DK::CMiniport::IsFlipPending(D3DK::CMiniport *this)
{
  return this->m_VBlankFlips[this->m_VBlankFlipNext].Pending;
}
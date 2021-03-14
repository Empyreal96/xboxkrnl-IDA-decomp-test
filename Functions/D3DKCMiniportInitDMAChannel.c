int __thiscall D3DK::CMiniport::InitDMAChannel(D3DK::CMiniport *this, unsigned int Class, D3DK::CMiniport::OBJECTINFO *ErrorContext, D3DK::CMiniport::OBJECTINFO *DataContext, unsigned int Offset, void **ppChannel)
{
  D3DK::CMiniport *v6; // esi

  v6 = this;
  this->m_HalInfo.FifoChID = 0;
  this->m_HalInfo.FifoMode = 0;
  this->m_HalInfo.FifoAllocCount = 0;
  this->m_HalInfo.FifoObjectCount = 0;
  this->m_HalInfo.FifoInstance = D3DK::CMiniport::ReserveInstMem(this, 0x37Fu);
  D3DK::CMiniport::HalFifoAllocDMA(v6, 0x80u, 0x80u, 8u, DataContext);
  *ppChannel = (char *)v6->m_RegisterBase + 0x10000 * (v6->m_HalInfo.FifoChID + 128);
  return 1;
}
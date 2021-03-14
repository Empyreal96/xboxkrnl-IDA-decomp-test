void __thiscall D3DK::CMiniport::HalFifoControlInit(D3DK::CMiniport *this)
{
  _DWORD *v1; // eax

  v1 = this->m_RegisterBase;
  this->m_HalInfo.FifoRetryCount = 255;
  this->m_HalInfo.FifoUserBase = 0x800000;
  this->m_HalInfo.FifoIntrEn0 = 17895697;
  v1[3204] = 0;
  v1[3228] = 0;
  v1[3216] = 0;
  v1[3217] = 0;
  v1[3094] = 0;
  v1[3222] = 0;
  v1[2369] = this->m_HalInfo.FifoMode;
  v1[2370] = 0;
  v1[2371] = 0;
  v1[3210] = 0;
  v1[2308] = 0;
  v1[2312] = 0;
}
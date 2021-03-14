void __thiscall D3DK::CMiniport::HalFifoControlLoad(D3DK::CMiniport *this)
{
  _DWORD *v1; // esi

  v1 = this->m_RegisterBase;
  v1[3209] = 983160;
  v1[2065] = 16908287;
  v1[2064] = this->m_HalInfo.FifoRetryCount & 0x3FF;
  v1[2368] = 0;
  v1[3072] = 0;
  v1[3092] = 0;
  v1[3200] = 0;
  v1[3220] = 0;
  v1[3208] = 0;
  D3DK::CMiniport::HalFifoContextSwitch(this, 1u);
  v1[3204] = 0;
  v1[3228] = 0;
  v1[3220] = 1;
  v1[3200] = 1;
  v1[2368] = 1;
  v1[2368] = 0;
}
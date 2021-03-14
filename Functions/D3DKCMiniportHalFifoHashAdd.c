void __thiscall D3DK::CMiniport::HalFifoHashAdd(D3DK::CMiniport *this, unsigned int entry, unsigned int handle, unsigned int chid, unsigned int instance, unsigned int engine)
{
  D3DK::CMiniport *v6; // esi
  int *v7; // edi
  unsigned int *v8; // eax

  v6 = this;
  v7 = (int *)this->m_RegisterBase;
  if ( 8 * entry >= 0x1000 )
    D3DK::DXGRIP(v7, "Assertion failure: %s", "entry * sizeof(HW_HASHENTRY) < 0x1000");
  v8 = (unsigned int *)((char *)&v7[2 * entry] + v6->m_HalInfo.HashTableAddr);
  *v8 = handle;
  v8[1] = (unsigned __int16)instance | ((engine | ((chid | 0xFFFFFF80) << 8)) << 16);
}
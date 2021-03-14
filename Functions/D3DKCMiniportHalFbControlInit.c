void __thiscall D3DK::CMiniport::HalFbControlInit(D3DK::CMiniport *this)
{
  D3DK::CMiniport *v1; // esi
  int *v2; // edi
  unsigned int v3; // eax
  unsigned int v4; // ecx
  int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int InstPadSize; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = (int *)this->m_RegisterBase;
  this->m_HalInfo.FbSave0 = *((_DWORD *)this->m_RegisterBase + 262272);
  this->m_HalInfo.FbSave1 = v2[262273];
  this->m_GenInfo.VideoRamType = ((v2[1158] & 0x100) != 256) + 2;
  if ( (v2[262272] & 3) != 3 )
    D3DK::DXGRIP(v2, "Assertion failure: %s", "REG_RD_DRF(regbase, _PFB, _CFG0, _PART) == 3");
  v3 = MmClaimGpuInstanceMemory(0xFFFFFFFF, &InstPadSize);
  v1->m_InstMem = (void *)v3;
  if ( !v3 )
    D3DK::DXGRIP(v2, "Assertion failure: %s", "m_InstMem != NULL");
  v4 = InstPadSize;
  v1->m_InstMem = (char *)v1->m_InstMem - 20480;
  v1->m_HalInfo.HashTableAddr = v4 + 7340032;
  v2[2180] = (v4 >> 8) & 0x1F0 | 0x3000000;
  v5 = v4 + 7344128;
  v1->m_HalInfo.FifoContextAddr1 = v4 + 7344128;
  v6 = v1->m_HalInfo.FifoContextAddr1;
  v5 += 128;
  v1->m_HalInfo.FifoContextAddr2 = v5;
  v2[2181] = (v6 >> 8) & 0x1FC | ((v5 & 0x1FC00 | 0x200) << 7);
  v1->m_FreeInstAddr = (unsigned int)(v5 - 7340000) >> 4;
  v2[262277] &= 0xFFFFFFFE;
  v7 = 7340032;
  do
  {
    v8 = v7 + InstPadSize;
    v7 += 4;
    *(int *)((char *)v2 + v8) = 0;
  }
  while ( v7 < 0x705000 );
  v1->m_HalInfo.GrCtxTableBase = D3DK::CMiniport::ReserveInstMem(v1, 8u);
}
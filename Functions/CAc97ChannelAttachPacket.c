void __thiscall CAc97Channel::AttachPacket(CAc97Channel *this, unsigned int dwBufferAddress, unsigned int dwBufferSize)
{
  CAc97Channel *thisa; // [esp+0h] [ebp-10h]
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-Ch]
  char bPrdIndex; // [esp+Fh] [ebp-1h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( thisa->m_dwFlags & 2 )
  {
    thisa->m_dwFlags &= 0xFFFFFFFD;
    --thisa->m_bPrdCount;
  }
  bPrdIndex = (thisa->m_bPrdCount + thisa->m_bCurrentPrd) & 0x1F;
  thisa->m_pPrdl[(unsigned __int8)bPrdIndex].dwPhysicalAddress = dwBufferAddress;
  *((_DWORD *)&thisa->m_pPrdl[(unsigned __int8)bPrdIndex] + 1) = (unsigned __int16)(dwBufferSize
                                                                                  / ((signed int)CAc97Device::m_wfxFormat.wBitsPerSample >> 3)) | *((_DWORD *)&thisa->m_pPrdl[(unsigned __int8)bPrdIndex] + 1) & 0xFFFF0000;
  *((_DWORD *)&thisa->m_pPrdl[(unsigned __int8)bPrdIndex] + 1) &= 0xC000FFFF;
  *((_DWORD *)&thisa->m_pPrdl[(unsigned __int8)bPrdIndex] + 1) |= 0x40000000u;
  *((_DWORD *)&thisa->m_pPrdl[(unsigned __int8)bPrdIndex] + 1) = *((_DWORD *)&thisa->m_pPrdl[(unsigned __int8)bPrdIndex]
                                                                 + 1) & 0x7FFFFFFF | 0x80000000;
  CAc97Channel::SetPrdIndeces(thisa, thisa->m_bCurrentPrd, thisa->m_bPrdCount + 1, 0, 1);
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}
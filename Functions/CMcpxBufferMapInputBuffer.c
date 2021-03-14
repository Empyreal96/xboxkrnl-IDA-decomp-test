int __usercall CMcpxBuffer::MapInputBuffer@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-18h]
  void *pvBufferData; // [esp+4h] [ebp-14h]
  int hr; // [esp+8h] [ebp-10h]
  unsigned int dwBufferSize; // [esp+Ch] [ebp-Ch]
  unsigned int dwAddress; // [esp+10h] [ebp-8h]
  unsigned int i; // [esp+14h] [ebp-4h]

  thisa = this;
  hr = 0;
  if ( !(this->m_dwStatus & 0x40) )
  {
    this->m_dwStatus |= 0x40u;
    MmLockUnlockBufferPages(
      (int)this,
      (int)this->m_pSettings->m_pvBufferData,
      a2,
      a3,
      this->m_pSettings->m_pvBufferData,
      this->m_pSettings->m_dwBufferSize,
      0);
    thisa->m_pSgeHeapEntry = (_SGEHEAPRUNMARKER *)((int (__thiscall *)(CMcpxBufferSgeHeap *, void *, unsigned int))thisa->m_pMcpxApu->m_SgeHeap.vfptr[1].__vecDelDtor)(
                                                    &thisa->m_pMcpxApu->m_SgeHeap,
                                                    thisa->m_pSettings->m_pvBufferData,
                                                    thisa->m_pSettings->m_dwBufferSize);
    if ( !thisa->m_pSgeHeapEntry )
      hr = -2147024882;
    if ( hr >= 0 )
    {
      pvBufferData = thisa->m_pSettings->m_pvBufferData;
      dwBufferSize = thisa->m_pSettings->m_dwBufferSize;
      for ( i = 0; i < thisa->m_pSgeHeapEntry->wLength; ++i )
      {
        dwAddress = CMcpxCore::MapTransfer(a2, &pvBufferData, &dwBufferSize, 0);
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820804] = i + thisa->m_pSgeHeapEntry->wElement;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820808] = dwAddress & 0xFFFFF000;
      }
    }
    if ( hr >= 0 )
      CMcpxBuffer::MapBuffer(
        thisa,
        thisa->m_pSgeHeapEntry->wElement,
        thisa->m_pSettings->m_pvBufferData,
        thisa->m_pSettings->m_dwBufferSize);
    if ( hr < 0 )
      CMcpxBuffer::UnmapBuffer(thisa, a2, a3);
  }
  return hr;
}
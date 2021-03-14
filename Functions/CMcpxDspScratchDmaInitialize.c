void __userpurge CMcpxDspScratchDma::Initialize(CMcpxDspScratchDma *this@<ecx>, int *a2@<edi>, unsigned int dwReservedPages)
{
  unsigned int v3; // eax
  unsigned int v4; // [esp+0h] [ebp-20h]
  CMcpxDspScratchDma *thisa; // [esp+4h] [ebp-1Ch]
  unsigned int i; // [esp+8h] [ebp-18h]
  unsigned int bytesRemaining; // [esp+Ch] [ebp-14h]
  MCP1_PRD *pPrd; // [esp+10h] [ebp-10h]
  unsigned int index; // [esp+14h] [ebp-Ch]
  unsigned int bytesMapped; // [esp+18h] [ebp-8h]
  void *currentVa; // [esp+1Ch] [ebp-4h]

  thisa = this;
  if ( this->m_fGpScratch == 1 )
  {
    index = 12;
    v4 = 12;
  }
  else
  {
    v4 = 14;
  }
  index = v4;
  this->m_pDmaBufferContext = &this->m_pApu->m_ctxMemory[v4];
  this->m_pSGETableContext = &this->m_pApu->m_ctxMemory[index + 1];
  this->m_dwMaxPages = (unsigned __int16)(this->m_pSGETableContext->Size >> 3);
  this->m_dwReservedPages = dwReservedPages;
  pPrd = (MCP1_PRD *)this->m_pSGETableContext->VirtualAddress;
  bytesRemaining = this->m_pDmaBufferContext->Size;
  bytesMapped = 0;
  currentVa = this->m_pDmaBufferContext->VirtualAddress;
  for ( i = 0; i < thisa->m_dwMaxPages - dwReservedPages; ++i )
  {
    v3 = CMcpxCore::MapTransfer(a2, &currentVa, &bytesRemaining, &bytesMapped);
    pPrd[i].uAddr = v3;
    pPrd[i].Control.uValue = 0;
    pPrd[i].Control.uValue &= 0xFEFFFFFF;
  }
  if ( thisa->m_fGpScratch )
  {
    MEMORY[0xFE802040] = thisa->m_pSGETableContext->PhysicalAddress;
    MEMORY[0xFE8020D4] = thisa->m_dwMaxPages - thisa->m_dwReservedPages;
  }
  else
  {
    MEMORY[0xFE802048] = thisa->m_pSGETableContext->PhysicalAddress;
    MEMORY[0xFE8020DC] = thisa->m_dwMaxPages;
  }
}
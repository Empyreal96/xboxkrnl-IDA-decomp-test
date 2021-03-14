void __thiscall CMcpxDspScratchDma::Copy(CMcpxDspScratchDma *this, unsigned int uLinOffset, void *pSource, unsigned int uSize)
{
  memcpy((char *)this->m_pDmaBufferContext->VirtualAddress + uLinOffset, (char *)pSource, uSize);
}
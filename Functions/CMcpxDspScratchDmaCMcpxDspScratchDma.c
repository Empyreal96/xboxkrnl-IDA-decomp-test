void __thiscall CMcpxDspScratchDma::CMcpxDspScratchDma(CMcpxDspScratchDma *this, CMcpxCore *pApu, int fGpScratch)
{
  this->m_dwMaxPages = 0;
  this->m_pApu = pApu;
  this->m_fGpScratch = fGpScratch;
  memset(&this->m_ctxFxScratch, 0, 0xCu);
}
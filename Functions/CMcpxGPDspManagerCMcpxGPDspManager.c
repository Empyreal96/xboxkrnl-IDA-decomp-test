void __thiscall CMcpxGPDspManager::CMcpxGPDspManager(CMcpxGPDspManager *this, CMcpxCore *pApu)
{
  this->m_pApu = pApu;
  this->m_pScratchDma = 0;
  this->m_pDspImage = 0;
  this->m_uPMemMaxSize = 4096;
  this->m_uPMemOffset = 0;
  this->m_dwCurrentLowestScratchOffset = 0x8000;
  this->m_dwStateSizeToCommit = 0;
}
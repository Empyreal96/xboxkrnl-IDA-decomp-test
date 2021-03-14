void __usercall CMcpxGPDspManager::~CMcpxGPDspManager(CMcpxGPDspManager *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  CMcpxGPDspManager *v3; // ST04_4

  v3 = this;
  __delete(a2, a3, &this->m_pScratchDma);
  __delete(&v3->m_pDspImage);
}
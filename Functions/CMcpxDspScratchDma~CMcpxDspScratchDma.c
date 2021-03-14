void __usercall CMcpxDspScratchDma::~CMcpxDspScratchDma(CMcpxDspScratchDma *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  CMcpxDspScratchDma *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  if ( this->m_ctxFxScratch.VirtualAddress )
  {
    if ( this->m_ctxFxScratch.Size )
    {
      MmLockUnlockBufferPages(
        (int)this->m_ctxFxScratch.VirtualAddress,
        (int)this,
        a2,
        a3,
        this->m_ctxFxScratch.VirtualAddress,
        this->m_ctxFxScratch.Size,
        1);
      PoolFree(&thisa->m_ctxFxScratch.VirtualAddress);
    }
  }
}
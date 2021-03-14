void __usercall CMcpxBuffer::UnmapBuffer(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  ((void (__thiscall *)(CMcpxBuffer *, _DWORD, signed int))this->vfptr[1].AddRef)(this, 0, 1);
  if ( thisa->m_dwStatus & 0x40 )
  {
    thisa->m_dwStatus &= 0xFFFFFFBF;
    if ( !(thisa->m_pSettings->m_dwFlags & 0x80000) )
    {
      MmLockUnlockBufferPages(
        (int)thisa,
        (int)thisa->m_pSettings->m_pvBufferData,
        a2,
        a3,
        thisa->m_pSettings->m_pvBufferData,
        thisa->m_pSettings->m_dwBufferSize,
        1);
      if ( thisa->m_pSgeHeapEntry )
      {
        thisa->m_pMcpxApu->m_SgeHeap.vfptr->Free(
          (CHeap<_SGEHEAPRUNMARKER> *)&thisa->m_pMcpxApu->m_SgeHeap.vfptr,
          thisa->m_pSgeHeapEntry);
        thisa->m_pSgeHeapEntry = 0;
      }
    }
  }
}
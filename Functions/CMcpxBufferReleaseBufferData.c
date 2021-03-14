int __usercall CMcpxBuffer::ReleaseBufferData@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  if ( this->m_pSettings->m_dwFlags & 0x40000 )
    CMcpxBuffer::ReleaseBufferResources(this, a2, a3);
  else
    CMcpxBuffer::UnmapBuffer(this, a2, a3);
  thisa->m_dwCachedPlayCursor = 0;
  return 0;
}
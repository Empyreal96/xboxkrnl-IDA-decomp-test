int __usercall CMcpxBuffer::Stop@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  if ( (this->m_dwStatus & 3) == 3 )
  {
    if ( !(this->m_pSettings->m_dwFlags & 0x82000) )
      CMcpxBuffer::GetCurrentPosition(this, &this->m_dwCachedPlayCursor, 0);
    if ( thisa->m_pSettings->m_dwFlags & 0x40000 )
      CMcpxBuffer::ReleaseBufferResources(thisa, a2, a3);
    else
      ((void (__thiscall *)(CMcpxBuffer *, _DWORD, _DWORD))thisa->vfptr[1].AddRef)(thisa, 0, 0);
    CMcpxBuffer::OnPositionDelta(thisa, a2);
  }
  return 0;
}
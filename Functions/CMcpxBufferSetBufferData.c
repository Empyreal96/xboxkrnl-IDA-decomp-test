int __usercall CMcpxBuffer::SetBufferData@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  int hr; // [esp+4h] [ebp-4h]

  hr = 0;
  if ( !(this->m_pSettings->m_dwFlags & 0x40000) )
    hr = CMcpxBuffer::AllocateBufferResources(this, a2, a3);
  return hr;
}
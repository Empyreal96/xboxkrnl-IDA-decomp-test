int __usercall CMcpxBuffer::SetLoopRegion@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  int hr; // [esp+4h] [ebp-4h]

  hr = 0;
  if ( (this->m_dwStatus & 3) == 3 )
    hr = CMcpxBuffer::Play(this, a2, a3, (this->m_dwStatus & 0x10) != 0);
  return hr;
}
int __usercall CMcpxBuffer::AllocateBufferResources@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-8h]
  int hr; // [esp+4h] [ebp-4h]

  thisa = this;
  hr = CMcpxVoiceClient::AllocateVoiceResources((CMcpxVoiceClient *)&this->vfptr);
  if ( hr >= 0 && !(thisa->m_pSettings->m_dwFlags & 0x2000) )
  {
    if ( thisa->m_pSettings->m_dwFlags & 0x80000 )
      CMcpxBuffer::MapEffectsBuffer(thisa, a3);
    else
      hr = CMcpxBuffer::MapInputBuffer(thisa, a2, a3);
  }
  return hr;
}
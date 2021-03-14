void __usercall CMcpxBuffer::~CMcpxBuffer(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-8h]
  unsigned int i; // [esp+4h] [ebp-4h]

  thisa = this;
  this->vfptr = (CRefCountVtbl *)&CMcpxBuffer::`vftable';
  CMcpxBuffer::ReleaseBufferResources(this, a2, a3);
  for ( i = 0; i < 5; ++i )
    CMcpxBuffer::RemoveDeferredCommand(thisa, a2, i);
  __Release(&thisa->m_pSettings);
  CMcpxVoiceClient::~CMcpxVoiceClient((CMcpxVoiceClient *)&thisa->vfptr);
}
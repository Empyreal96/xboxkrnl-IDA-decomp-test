void __usercall CMcpxBuffer::ReleaseBufferResources(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-8h]
  unsigned int i; // [esp+4h] [ebp-4h]

  thisa = this;
  ((void (__thiscall *)(CMcpxBuffer *, _DWORD, signed int))this->vfptr[1].AddRef)(this, 0, 1);
  for ( i = 0; i < 2; ++i )
    CMcpxBuffer::RemoveDeferredCommand(thisa, a2, i);
  CMcpxBuffer::UnmapBuffer(thisa, a2, a3);
  CMcpxVoiceClient::ReleaseVoiceResources((CMcpxVoiceClient *)&thisa->vfptr);
}
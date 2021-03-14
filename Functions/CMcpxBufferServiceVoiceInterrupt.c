int __usercall CMcpxBuffer::ServiceVoiceInterrupt@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-8h]
  int fHandled; // [esp+4h] [ebp-4h]

  thisa = this;
  fHandled = CMcpxVoiceClient::GetNotifierStatus((CMcpxVoiceClient *)&this->vfptr, 0, 1);
  if ( fHandled )
  {
    ((void (__thiscall *)(CMcpxBuffer *, signed int, _DWORD))thisa->vfptr[1].AddRef)(thisa, 1, 0);
    if ( thisa->m_pSettings->m_dwFlags & 0x40000 )
      CMcpxBuffer::ScheduleDeferredCommand(thisa, a2, 1u, 0i64, 0);
  }
  return fHandled;
}
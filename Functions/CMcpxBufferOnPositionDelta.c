void __usercall CMcpxBuffer::OnPositionDelta(CMcpxBuffer *this@<ecx>, int *a2@<edi>)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-8h]
  unsigned int dwPlayCursor; // [esp+4h] [ebp-4h]

  thisa = this;
  if ( this->m_EventSink.OnPositionDelta && CMcpxBuffer::GetCurrentPosition(this, &dwPlayCursor, 0) >= 0 )
    thisa->m_EventSink.OnPositionDelta(dwPlayCursor, thisa->m_pvEventContext);
  if ( !(thisa->m_dwStatus & 0x10000002) )
  {
    if ( thisa->m_EventSink.OnStop )
      thisa->m_EventSink.OnStop(thisa->m_pvEventContext);
    CMcpxBuffer::RemoveDeferredCommand(thisa, a2, 0);
  }
}
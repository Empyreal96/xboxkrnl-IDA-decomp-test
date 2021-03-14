void __userpurge CMcpxBuffer::ServiceDeferredCommand(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>, unsigned int dwCommand, unsigned int dwContext)
{
  switch ( dwCommand )
  {
    case 0u:
      CMcpxBuffer::OnPositionDelta(this, a2);
      break;
    case 1u:
      CMcpxBuffer::ReleaseBufferResources(this, a2, a3);
      break;
    case 2u:
      CMcpxBuffer::Play(this, a2, a3, dwContext);
      break;
    case 3u:
      CMcpxBuffer::Stop(this, a2, a3);
      break;
    case 4u:
      CMcpxBuffer::NoteOff(this, a2, a3, dwContext);
      break;
    default:
      return;
  }
}
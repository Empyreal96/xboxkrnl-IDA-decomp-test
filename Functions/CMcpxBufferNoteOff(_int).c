int __userpurge CMcpxBuffer::NoteOff@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>, int fBreakLoop)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-8h]
  int hr; // [esp+4h] [ebp-4h]

  thisa = this;
  hr = 0;
  if ( fBreakLoop && (this->m_dwStatus & 0x13) == 19 )
    hr = CMcpxBuffer::Play(this, a2, a3, 0);
  if ( hr >= 0 )
    CMcpxVoiceClient::ReleaseVoice((CMcpxVoiceClient *)&thisa->vfptr);
  return hr;
}
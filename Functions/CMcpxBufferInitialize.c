int __userpurge CMcpxBuffer::Initialize@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>, CDirectSoundBufferSettings *pSettings, VADBUFFEREVENTSINK *EventSink, void *pvEventContext)
{
  void (__stdcall *v6)(void *); // ecx
  CMcpxBuffer *thisa; // [esp+0h] [ebp-8h]
  int hr; // [esp+4h] [ebp-4h]

  thisa = this;
  this->m_pSettings = (CDirectSoundBufferSettings *)__AddRef((CMcpxAPU *)pSettings);
  v6 = EventSink->OnStop;
  thisa->m_EventSink.OnPositionDelta = EventSink->OnPositionDelta;
  thisa->m_EventSink.OnStop = v6;
  thisa->m_pvEventContext = pvEventContext;
  hr = CMcpxVoiceClient::Initialize(
         (CMcpxVoiceClient *)&thisa->vfptr,
         (CDirectSoundVoiceSettings *)&thisa->m_pSettings->vfptr,
         0);
  if ( hr >= 0
    && !(thisa->m_pSettings->m_dwFlags & 0x40000)
    && (thisa->m_pSettings->m_dwFlags & 0x82000
     || thisa->m_pSettings->m_pvBufferData && thisa->m_pSettings->m_dwBufferSize) )
  {
    hr = CMcpxBuffer::AllocateBufferResources(thisa, a2, a3);
  }
  return hr;
}
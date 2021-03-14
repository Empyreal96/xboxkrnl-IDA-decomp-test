void __thiscall CMcpxBuffer::CMcpxBuffer(CMcpxBuffer *this, CMcpxAPU *pMcpxApu)
{
  CMcpxBuffer *thisa; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  thisa = this;
  CMcpxVoiceClient::CMcpxVoiceClient((CMcpxVoiceClient *)&this->vfptr, pMcpxApu);
  thisa->vfptr = (CRefCountVtbl *)&CMcpxBuffer::`vftable';
  for ( i = 0; i < 5; ++i )
  {
    thisa->m_aDeferredCommands[i].leListEntry.Blink = &thisa->m_aDeferredCommands[i].leListEntry;
    thisa->m_aDeferredCommands[i].leListEntry.Flink = thisa->m_aDeferredCommands[i].leListEntry.Blink;
    thisa->m_aDeferredCommands[i].pVoice = (CMcpxVoiceClient *)&thisa->vfptr;
    thisa->m_aDeferredCommands[i].dwCommand = i;
  }
  thisa->m_aDeferredCommands[1].dwFlags = 1;
  thisa->m_aDeferredCommands[0].dwFlags = 5;
}
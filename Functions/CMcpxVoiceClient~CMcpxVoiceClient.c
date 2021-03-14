void __thiscall CMcpxVoiceClient::~CMcpxVoiceClient(CMcpxVoiceClient *this)
{
  CMcpxVoiceClient *v1; // ST04_4

  v1 = this;
  this->vfptr = (CRefCountVtbl *)&CMcpxVoiceClient::`vftable';
  CMcpxVoiceClient::DisconnectVoice(this);
  RemoveEntryList(&v1->m_le3dVoice);
  __Release((CDirectSoundBufferSettings **)&v1->m_pMcpxApu);
  __Release((CDirectSoundBufferSettings **)&v1->m_pSettings);
  CRefCount::~CRefCount((CRefCount *)&v1->vfptr);
}
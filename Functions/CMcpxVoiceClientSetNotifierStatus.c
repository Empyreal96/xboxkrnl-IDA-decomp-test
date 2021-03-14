void __thiscall CMcpxVoiceClient::SetNotifierStatus(CMcpxVoiceClient *this, unsigned int dwIndex, int fSignaled)
{
  CMcpxVoiceClient *v3; // ST08_4
  unsigned int v4; // eax

  v3 = this;
  v4 = CMcpxCore::GetVoiceNotifierIndex((unsigned int)this->m_ahVoices[0], dwIndex);
  CMcpxCore::SetNotifierStatus((CMcpxCore *)&v3->m_pMcpxApu->vfptr, v4, fSignaled);
}
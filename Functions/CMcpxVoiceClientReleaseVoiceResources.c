void __thiscall CMcpxVoiceClient::ReleaseVoiceResources(CMcpxVoiceClient *this)
{
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-Ch]
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-8h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( thisa->m_dwStatus & 1 )
  {
    CMcpxAPU::FreeVoices(thisa->m_pMcpxApu, thisa);
    thisa->m_dwStatus &= 0x80u;
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}
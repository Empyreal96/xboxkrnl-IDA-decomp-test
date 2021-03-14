unsigned int __thiscall CMcpxVoiceClient::GetSSLPosition(CMcpxVoiceClient *this)
{
  unsigned int v1; // ST08_4
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-14h]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-Ch]
  unsigned int dwPlayCursor; // [esp+10h] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( thisa->m_dwStatus & 1 )
  {
    while ( MEMORY[0xFE820010] < 4u )
      ;
    MEMORY[0xFE8202F8] = thisa->m_ahVoices[0];
    while ( MEMORY[0xFE820010] < 4u )
      ;
    MEMORY[0xFE8202FC] = 1;
    dwPlayCursor = *((_DWORD *)thisa->m_pMcpxApu->m_ctxMemory[3].VirtualAddress + 32 * (_DWORD)thisa->m_ahVoices[0] + 22);
    while ( MEMORY[0xFE820010] < 4u )
      ;
    MEMORY[0xFE8202FC] = 0;
    dwPlayCursor &= 0xFFFFFFu;
    dwPlayCursor = CMcpxVoiceClient::SamplesToBytes(thisa, dwPlayCursor);
  }
  else
  {
    dwPlayCursor = 0;
  }
  v1 = dwPlayCursor;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return v1;
}
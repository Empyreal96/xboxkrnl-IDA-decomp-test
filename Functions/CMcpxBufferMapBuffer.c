void __thiscall CMcpxBuffer::MapBuffer(CMcpxBuffer *this, unsigned int dwSgeIndex, void *pvBufferData, unsigned int dwBufferSize)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-18h]
  int dwIncrement; // [esp+4h] [ebp-14h]
  unsigned int i; // [esp+8h] [ebp-10h]
  CIrql irql; // [esp+Ch] [ebp-Ch]
  unsigned int dwBufferBase; // [esp+14h] [ebp-4h]

  thisa = this;
  dwBufferBase = (dwSgeIndex << 12) | (unsigned __int16)pvBufferData & 0xFFF;
  dwIncrement = 2 * this->m_pSettings->m_pwfxFormat->wBitsPerSample / 8;
  CIrql::Raise(&irql);
  for ( i = 0; i < CMcpxVoiceClient::GetHwVoiceCount((CMcpxVoiceClient *)&thisa->vfptr); ++i )
  {
    while ( MEMORY[0xFE820010] < 4u )
      ;
    MEMORY[0xFE8202F8] = thisa->m_ahVoices[i];
    while ( MEMORY[0xFE820010] < 4u )
      ;
    MEMORY[0xFE8203A0] = dwBufferBase;
    dwBufferBase += dwIncrement;
  }
  CIrql::Lower(&irql);
}
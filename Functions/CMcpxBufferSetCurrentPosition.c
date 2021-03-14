int __userpurge CMcpxBuffer::SetCurrentPosition@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>, unsigned int dwPlayCursor)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-14h]
  int hr; // [esp+4h] [ebp-10h]
  unsigned int i; // [esp+8h] [ebp-Ch]
  CIrql irql; // [esp+Ch] [ebp-8h]
  unsigned int dwPlayCursora; // [esp+1Ch] [ebp+8h]

  thisa = this;
  hr = 0;
  if ( (this->m_dwStatus & 3) == 3 )
  {
    if ( (this->m_dwStatus & 0x13) == 19
      && dwPlayCursor >= this->m_pSettings->m_dwLoopLength + this->m_pSettings->m_dwLoopStart )
    {
      hr = CMcpxBuffer::Play(this, a2, a3, 0);
    }
    if ( hr >= 0 )
      CMcpxVoiceClient::PauseVoice((CMcpxVoiceClient *)&thisa->vfptr, 4u);
    if ( hr >= 0 )
    {
      dwPlayCursora = CMcpxVoiceClient::BytesToSamples((CMcpxVoiceClient *)&thisa->vfptr, dwPlayCursor);
      CIrql::Raise(&irql);
      for ( i = 0; i < CMcpxVoiceClient::GetHwVoiceCount((CMcpxVoiceClient *)&thisa->vfptr); ++i )
      {
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE8202F8] = thisa->m_ahVoices[i];
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE8203D8] = dwPlayCursora;
      }
      CIrql::Lower(&irql);
    }
    if ( hr >= 0 )
      CMcpxVoiceClient::PauseVoice((CMcpxVoiceClient *)&thisa->vfptr, 0);
  }
  else
  {
    this->m_dwCachedPlayCursor = dwPlayCursor;
  }
  return hr;
}
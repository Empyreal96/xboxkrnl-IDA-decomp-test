int __thiscall CMcpxBuffer::GetCurrentPosition(CMcpxBuffer *this, unsigned int *pdwPlayCursor, unsigned int *pdwWriteCursor)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-18h]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-10h]
  unsigned int dwFrameSize; // [esp+10h] [ebp-8h]
  unsigned int dwPlayCursor; // [esp+14h] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( (thisa->m_dwStatus & 3) == 3 )
  {
    dwPlayCursor = CMcpxVoiceClient::GetSSLPosition((CMcpxVoiceClient *)&thisa->vfptr);
    if ( pdwPlayCursor )
      *pdwPlayCursor = dwPlayCursor;
    if ( pdwWriteCursor )
    {
      dwFrameSize = CMcpxVoiceClient::SamplesToBytes((CMcpxVoiceClient *)&thisa->vfptr, 0x20u);
      if ( dwFrameSize < thisa->m_pSettings->m_pwfxFormat->nBlockAlign )
        dwFrameSize = thisa->m_pSettings->m_pwfxFormat->nBlockAlign;
      *pdwWriteCursor = dwFrameSize + dwPlayCursor;
      if ( thisa->m_dwStatus & 0x10
        && dwPlayCursor >= thisa->m_pSettings->m_dwLoopStart
        && dwPlayCursor < thisa->m_pSettings->m_dwLoopLength + thisa->m_pSettings->m_dwLoopStart )
      {
        *pdwWriteCursor %= thisa->m_pSettings->m_dwLoopLength;
        *pdwWriteCursor += thisa->m_pSettings->m_dwLoopStart;
      }
      else
      {
        *pdwWriteCursor %= thisa->m_pSettings->m_dwBufferSize;
      }
    }
  }
  else
  {
    if ( pdwPlayCursor )
      *pdwPlayCursor = thisa->m_dwCachedPlayCursor;
    if ( pdwWriteCursor )
      *pdwWriteCursor = thisa->m_dwCachedPlayCursor;
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return 0;
}
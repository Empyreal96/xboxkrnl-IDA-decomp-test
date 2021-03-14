void __userpurge CDirectSoundBuffer::OnPositionDelta(int *a1@<edi>, int a2@<esi>, CDirectSoundBuffer *this, unsigned int dwPlayCursor)
{
  CAutoLock __AutoLock; // [esp+0h] [ebp-14h]
  unsigned int dwRegionStart; // [esp+8h] [ebp-Ch]
  unsigned int dwStatus; // [esp+Ch] [ebp-8h]
  unsigned int dwRegionLength; // [esp+10h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  if ( dwPlayCursor != this->m_dwLastNotifyPosition )
  {
    if ( dwPlayCursor <= this->m_dwLastNotifyPosition )
    {
      if ( CDirectSoundBuffer::GetStatus(this, &dwStatus) >= 0 )
      {
        if ( dwStatus & 4
          && dwPlayCursor >= this->m_pSettings->m_dwLoopStart
          && dwPlayCursor < this->m_pSettings->m_dwLoopLength + this->m_pSettings->m_dwLoopStart )
        {
          dwRegionStart = this->m_pSettings->m_dwLoopStart;
          dwRegionLength = this->m_pSettings->m_dwLoopLength;
        }
        else
        {
          dwRegionStart = 0;
          dwRegionLength = this->m_pSettings->m_dwBufferSize;
        }
        CDirectSoundBuffer::NotifyPosition(
          a1,
          a2,
          this,
          this->m_dwLastNotifyPosition,
          dwRegionLength + dwRegionStart - this->m_dwLastNotifyPosition);
        CDirectSoundBuffer::NotifyPosition(a1, a2, this, dwRegionStart, dwPlayCursor);
      }
    }
    else
    {
      CDirectSoundBuffer::NotifyPosition(
        a1,
        a2,
        this,
        this->m_dwLastNotifyPosition,
        dwPlayCursor - this->m_dwLastNotifyPosition);
    }
    this->m_dwLastNotifyPosition = dwPlayCursor;
  }
  CAutoLock::~CAutoLock(&__AutoLock);
}
void __thiscall CDirectSoundBufferSettings::SetLoopRegion(CDirectSoundBufferSettings *this, unsigned int dwLoopStart, unsigned int dwLoopLength)
{
  if ( !dwLoopLength )
  {
    dwLoopStart = 0;
    dwLoopLength = this->m_dwBufferSize;
  }
  this->m_dwLoopStart = dwLoopStart;
  this->m_dwLoopLength = dwLoopLength;
}
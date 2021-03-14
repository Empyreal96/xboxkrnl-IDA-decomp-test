void __userpurge CDirectSoundBuffer::NotifyPosition(int *a1@<edi>, int a2@<esi>, CDirectSoundBuffer *this, unsigned int dwStartPosition, unsigned int dwDelta)
{
  unsigned int i; // [esp+0h] [ebp-4h]

  if ( this->m_paNotifies )
  {
    for ( i = 0; i < this->m_dwNotifyCount; ++i )
    {
      if ( this->m_paNotifies[i].dwOffset >= dwStartPosition )
      {
        if ( this->m_paNotifies[i].dwOffset >= dwDelta + dwStartPosition )
          return;
        NtSetEvent(i, (int)this->m_paNotifies, a1, a2, this->m_paNotifies[i].hEventNotify, 0);
      }
    }
  }
}
void __userpurge CDirectSoundBuffer::NotifyStop(int *a1@<edi>, int a2@<esi>, CDirectSoundBuffer *this)
{
  unsigned int i; // [esp+0h] [ebp-4h]

  if ( this->m_paNotifies )
  {
    for ( i = this->m_dwNotifyCount; i && this->m_paNotifies[i - 1].dwOffset == -1; --i )
      NtSetEvent(
        (int)this->m_paNotifies,
        *((_DWORD *)&this->m_paNotifies[i] - 1),
        a1,
        a2,
        *((void **)&this->m_paNotifies[i] - 1),
        0);
  }
}
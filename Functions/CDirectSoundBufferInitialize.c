int __userpurge CDirectSoundBuffer::Initialize@<eax>(int *a1@<edi>, int a2@<esi>, CDirectSoundBuffer *this, _DSBUFFERDESC *pdsbd)
{
  int v4; // edx
  int v5; // ecx
  CDirectSoundBufferSettings *v6; // eax
  int v7; // ST14_4
  CDirectSoundBufferSettings *v9; // [esp+0h] [ebp-1Ch]
  CDirectSoundBufferSettings *v10; // [esp+8h] [ebp-14h]
  CAutoLock __AutoLock; // [esp+Ch] [ebp-10h]
  int hr; // [esp+10h] [ebp-Ch]
  VADBUFFEREVENTSINK EventSink; // [esp+14h] [ebp-8h]

  CAutoLock::CAutoLock(&__AutoLock);
  v10 = (CDirectSoundBufferSettings *)CMcpxAPU::operator new(v4, v5, a2, 0x5Cu);
  if ( v10 )
  {
    CDirectSoundBufferSettings::CDirectSoundBufferSettings(v10);
    v9 = v6;
  }
  else
  {
    v9 = 0;
  }
  this->m_pSettings = v9;
  hr = v9 != 0 ? 0 : 0x8007000E;
  if ( hr >= 0 )
    hr = CDirectSoundBufferSettings::Initialize(this->m_pSettings, a1, a2, this->m_pDirectSound->m_pSettings, pdsbd);
  if ( hr >= 0 )
  {
    if ( pdsbd->dwFlags & 0x100 )
    {
      EventSink.OnPositionDelta = (void (__stdcall *)(unsigned int, void *))CDirectSoundBuffer::OnPositionDeltaStatic;
      EventSink.OnStop = (void (__stdcall *)(void *))CDirectSoundBuffer::OnStopStatic;
    }
    else
    {
      EventSink.OnPositionDelta = 0;
      EventSink.OnStop = 0;
    }
    hr = CMcpxAPU::CreateBuffer(
           this->m_pDirectSound->m_pDevice,
           a1,
           a2,
           (int)this->m_pSettings,
           this->m_pSettings,
           &EventSink,
           this,
           &this->m_pBuffer);
  }
  if ( hr >= 0 )
    CDirectSoundVoice::Initialize(
      (CDirectSoundVoice *)&this->vfptr,
      (CMcpxVoiceClient *)&this->m_pBuffer->vfptr,
      (CDirectSoundVoiceSettings *)&this->m_pSettings->vfptr);
  v7 = hr;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v7;
}
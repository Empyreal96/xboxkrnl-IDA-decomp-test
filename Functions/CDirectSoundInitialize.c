int __userpurge CDirectSound::Initialize@<eax>(int *a1@<edi>, int a2@<esi>, CDirectSound *this)
{
  int v3; // edx
  int v4; // ecx
  CDirectSoundSettings *v5; // eax
  CMcpxAPU *v6; // eax
  int v7; // ST18_4
  CMcpxAPU *v9; // [esp+0h] [ebp-38h]
  CDirectSoundSettings *v10; // [esp+4h] [ebp-34h]
  CMcpxAPU *v11; // [esp+Ch] [ebp-2Ch]
  CDirectSoundSettings *v12; // [esp+10h] [ebp-28h]
  CAutoLock __AutoLock; // [esp+14h] [ebp-24h]
  int hr; // [esp+18h] [ebp-20h]
  _DSBUFFERDESC dsbd; // [esp+1Ch] [ebp-1Ch]
  unsigned int i; // [esp+34h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  v12 = (CDirectSoundSettings *)CMcpxAPU::operator new(v3, v4, a2, 0x14u);
  if ( v12 )
  {
    CDirectSoundSettings::CDirectSoundSettings(v12);
    v10 = v5;
  }
  else
  {
    v10 = 0;
  }
  this->m_pSettings = v10;
  hr = v10 != 0 ? 0 : 0x8007000E;
  if ( hr >= 0 )
  {
    v11 = (CMcpxAPU *)CMcpxAPU::operator new(v10 != 0 ? 0 : 0x8007000E, (int)v10, a2, 0xE78u);
    if ( v11 )
    {
      CMcpxAPU::CMcpxAPU(v11);
      v9 = v6;
    }
    else
    {
      v9 = 0;
    }
    this->m_pDevice = v9;
    hr = v9 != 0 ? 0 : 0x8007000E;
  }
  if ( hr >= 0 )
    hr = CMcpxAPU::Initialize(this->m_pDevice, a1, a2, this->m_pSettings);
  if ( hr >= 0 )
  {
    memset(&dsbd, 0, 0x18u);
    dsbd.dwSize = 24;
    dsbd.lpwfxFormat = &wfxSilence;
    for ( i = 0; hr >= 0 && i < 1; ++i )
    {
      dsbd.dwMixBinMask = 63;
      hr = CDirectSound::CreateSoundBuffer(a1, a2, this, &dsbd, &this->m_apKeepAliveBuffers[i], 0);
      if ( hr >= 0 )
        hr = IDirectSoundBuffer::SetBufferData(a1, a2, this->m_apKeepAliveBuffers[i], (void *)asSilence, 0x40u);
      if ( hr >= 0 )
        hr = IDirectSoundBuffer::Play(a1, a2, this->m_apKeepAliveBuffers[i], 0, 0, 1u);
    }
  }
  v7 = hr;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v7;
}
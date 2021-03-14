int __userpurge CDirectSound::CreateSoundBuffer@<eax>(int *a1@<edi>, int a2@<esi>, CDirectSound *this, _DSBUFFERDESC *pdsbd, IDirectSoundBuffer **ppBuffer, IUnknown *pControllingUnknown)
{
  int v6; // edx
  int v7; // ecx
  CDirectSoundBuffer *v8; // eax
  int v9; // ST10_4
  IDirectSoundBuffer *v11; // [esp+0h] [ebp-1Ch]
  CDirectSoundBuffer *v12; // [esp+4h] [ebp-18h]
  CDirectSoundBuffer *v13; // [esp+Ch] [ebp-10h]
  CAutoLock __AutoLock; // [esp+10h] [ebp-Ch]
  int hr; // [esp+14h] [ebp-8h]
  CDirectSoundBuffer *pBuffer; // [esp+18h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  v13 = (CDirectSoundBuffer *)CMcpxAPU::operator new(v6, v7, a2, 0x30u);
  if ( v13 )
  {
    CDirectSoundBuffer::CDirectSoundBuffer(v13, this);
    v12 = v8;
  }
  else
  {
    v12 = 0;
  }
  pBuffer = v12;
  hr = v12 != 0 ? 0 : 0x8007000E;
  if ( hr >= 0 )
    hr = CDirectSoundBuffer::Initialize(a1, a2, pBuffer, pdsbd);
  if ( hr < 0 )
  {
    __Release((CDirectSoundBufferSettings **)&pBuffer);
  }
  else
  {
    if ( pBuffer )
      v11 = (IDirectSoundBuffer *)&pBuffer->m_pSettings;
    else
      v11 = 0;
    *ppBuffer = v11;
  }
  v9 = hr;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v9;
}
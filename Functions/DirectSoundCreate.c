int __userpurge DirectSoundCreate@<eax>(int *a1@<edi>, int a2@<esi>, _GUID *pguidDeviceId, IDirectSound **ppDirectSound, IUnknown *pControllingUnknown)
{
  int v5; // edx
  int v6; // ecx
  CDirectSound *v7; // eax
  int v8; // ST14_4
  IDirectSound *v10; // [esp+0h] [ebp-24h]
  CDirectSound *v11; // [esp+4h] [ebp-20h]
  IDirectSound *v12; // [esp+8h] [ebp-1Ch]
  CMcpxAPU *v13; // [esp+Ch] [ebp-18h]
  CDirectSound *v14; // [esp+14h] [ebp-10h]
  CAutoLock __AutoLock; // [esp+18h] [ebp-Ch]
  int hr; // [esp+1Ch] [ebp-8h]
  CDirectSound *pDirectSound; // [esp+20h] [ebp-4h]

  pDirectSound = 0;
  hr = 0;
  CAutoLock::CAutoLock(&__AutoLock);
  if ( CDirectSound::m_pDirectSound )
  {
    v13 = __AddRef((CMcpxAPU *)CDirectSound::m_pDirectSound);
    if ( v13 )
      v12 = (IDirectSound *)&v13->vfptr;
    else
      v12 = 0;
    *ppDirectSound = v12;
  }
  else
  {
    v14 = (CDirectSound *)CMcpxAPU::operator new(v5, v6, a2, 0x1Cu);
    if ( v14 )
    {
      CDirectSound::CDirectSound(v14);
      v11 = v7;
    }
    else
    {
      v11 = 0;
    }
    pDirectSound = v11;
    hr = v11 != 0 ? 0 : 0x8007000E;
    if ( hr >= 0 )
      hr = CDirectSound::Initialize(a1, a2, pDirectSound);
    if ( hr < 0 )
    {
      __Release((CDirectSoundBufferSettings **)&pDirectSound);
    }
    else
    {
      if ( pDirectSound )
        v10 = (IDirectSound *)&pDirectSound->m_pSettings;
      else
        v10 = 0;
      *ppDirectSound = v10;
    }
  }
  v8 = hr;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v8;
}
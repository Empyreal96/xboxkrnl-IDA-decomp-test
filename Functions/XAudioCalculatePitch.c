int __userpurge XAudioCalculatePitch@<eax>(int *a1@<edi>, unsigned int dwFrequency)
{
  float flFrequency; // ST00_4
  char v4; // [esp+Fh] [ebp-5h]
  int lPitch; // [esp+10h] [ebp-4h]

  if ( dwFrequency == 48000 )
    return 0;
  if ( !dwFrequency )
    return -32767;
  CAutoFpState::CAutoFpState((CAutoFpState *)&v4, a1);
  flFrequency = (double)dwFrequency;
  lPitch = XAudioCalculatePitchFloat(a1, flFrequency);
  CAutoFpState::~CAutoFpState();
  return lPitch;
}
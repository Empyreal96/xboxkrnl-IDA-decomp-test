int __userpurge XAudioCalculatePitchFloat@<eax>(int *a1@<edi>, float flFrequency)
{
  int v2; // ST00_4
  char v4; // [esp+7h] [ebp-Dh]
  float flRatio; // [esp+8h] [ebp-Ch]
  float fl4096; // [esp+Ch] [ebp-8h]
  int lPitch; // [esp+10h] [ebp-4h]

  CAutoFpState::CAutoFpState((CAutoFpState *)&v4, a1);
  if ( flFrequency == 48000.0 )
  {
    lPitch = 0;
  }
  else if ( flFrequency > 0.0 )
  {
    fl4096 = 4096.0;
    flRatio = flFrequency * 0.000020833333;
    lPitch = (signed int)__FYL2X__(flRatio, 4096.0);
  }
  else
  {
    lPitch = -32767;
  }
  v2 = lPitch;
  CAutoFpState::~CAutoFpState();
  return v2;
}
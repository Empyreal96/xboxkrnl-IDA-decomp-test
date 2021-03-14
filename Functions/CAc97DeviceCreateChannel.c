int __userpurge CAc97Device::CreateChannel@<eax>(CAc97Device *this@<ecx>, int a2@<esi>, AC97CHANNELTYPE nChannelType, CAc97Channel **ppChannel)
{
  int v4; // edx
  int v5; // ecx
  CAc97Channel *v6; // eax
  int v7; // ST10_4
  CAc97Channel *v9; // [esp+0h] [ebp-1Ch]
  CAc97Device *thisa; // [esp+4h] [ebp-18h]
  CAc97Channel *v11; // [esp+Ch] [ebp-10h]
  CAutoIrql __AutoIrql; // [esp+10h] [ebp-Ch]
  int hr; // [esp+18h] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  v11 = (CAc97Channel *)CMcpxAPU::operator new(v4, v5, a2, 0x30u);
  if ( v11 )
  {
    CAc97Channel::CAc97Channel(v11, thisa, nChannelType);
    v9 = v6;
  }
  else
  {
    v9 = 0;
  }
  thisa->m_apChannels[nChannelType] = v9;
  hr = v9 != 0 ? 0 : 0x8007000E;
  if ( hr >= 0 && ppChannel )
    *ppChannel = thisa->m_apChannels[nChannelType];
  v7 = hr;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return v7;
}
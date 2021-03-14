void __thiscall CMcpxVoiceClient::PauseVoice(CMcpxVoiceClient *this, unsigned int dwStatus)
{
  unsigned int v2; // eax
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-14h]
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-10h]
  unsigned int dwRegisterValue; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]
  unsigned int dwStatusa; // [esp+1Ch] [ebp+8h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  dwStatusa = dwStatus & 0xC;
  if ( dwStatusa )
    dwStatusa |= 4u;
  if ( (thisa->m_dwStatus & 0xC) != dwStatusa )
  {
    if ( (thisa->m_dwStatus & 3) == 3 )
    {
      if ( dwStatusa )
        dwRegisterValue = 0x40000;
      else
        dwRegisterValue = 0;
      for ( i = 0; ; ++i )
      {
        v2 = CMcpxVoiceClient::GetHwVoiceCount(thisa);
        if ( i >= v2 )
          break;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820140] = (_DWORD)thisa->m_ahVoices[i] & 0xFFFF | dwRegisterValue & 0xFFFF0000;
      }
    }
    thisa->m_dwStatus &= 0xFFFFFFF3;
    thisa->m_dwStatus |= dwStatusa;
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}
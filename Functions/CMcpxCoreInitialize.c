int __userpurge CMcpxCore::Initialize@<eax>(CMcpxCore *this@<ecx>, int *a2@<edi>, int a3@<esi>, CDirectSoundSettings *pSettings, int fInitial)
{
  CMcpxCore *thisa; // [esp+0h] [ebp-10h]
  int hr; // [esp+4h] [ebp-Ch]
  HOST_TO_DSP_COMMANDBLOCK *volatile pCmdBlock; // [esp+Ch] [ebp-4h]

  thisa = this;
  hr = 0;
  pCmdBlock = (HOST_TO_DSP_COMMANDBLOCK *volatile )((char *)this->m_ctxMemory[12].VirtualAddress + 2048);
  CMcpxCore::Reset(this, a2, fInitial);
  if ( fInitial )
    thisa->m_pSettings = (CDirectSoundSettings *)__AddRef((CMcpxAPU *)pSettings);
  if ( fInitial )
    hr = CMcpxCore::AllocateApuMemory(thisa, a2, a3);
  else
    MEMORY[0xFE801000] = -1;
  if ( hr >= 0 )
    CMcpxCore::SetupFrontEndProcessor();
  if ( hr >= 0 && fInitial )
    CMcpxCore::SetupVoiceProcessor(thisa);
  if ( hr >= 0 && fInitial )
    hr = CMcpxCore::SetupAc97(thisa, a2, a3);
  if ( hr >= 0 )
  {
    if ( !fInitial )
    {
      pCmdBlock->dwCommandFlags = 0;
      pCmdBlock->dwOffset = 0;
    }
    CMcpxCore::SetupGlobalProcessor(thisa, a2, a3, fInitial);
  }
  if ( hr >= 0 )
    CMcpxCore::SetSetupEngineState(MCPX_SE_STATE_AC_SYNC);
  if ( hr >= 0 )
  {
    CAc97Channel::Run(thisa->m_Ac97.m_apChannels[1], 0xFFFFFFFF);
    CAc97Channel::Run(thisa->m_Ac97.m_apChannels[0], 0xFFFFFFFF);
  }
  return hr;
}
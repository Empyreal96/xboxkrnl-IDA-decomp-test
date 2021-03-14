void __userpurge CMcpxCore::Reset(CMcpxCore *this@<ecx>, int *a2@<edi>, int fFull)
{
  CMcpxCore *thisa; // [esp+0h] [ebp-10h]

  thisa = this;
  if ( fFull )
  {
    CAc97Device::Terminate(&this->m_Ac97, a2);
  }
  else
  {
    CAc97Channel::Reset(this->m_Ac97.m_apChannels[0]);
    CAc97Channel::Reset(thisa->m_Ac97.m_apChannels[1]);
  }
  CMcpxCore::IdleVoiceProcessor(thisa, 1);
  CMcpxCore::SetInterruptState(0);
  CMcpxCore::SetPrivLockState(1);
  CMcpxCore::SetFrontEndState(0);
  CMcpxCore::SetSetupEngineState(0);
  if ( fFull )
  {
    MEMORY[0xFE802054] = 0xFFFF;
    MEMORY[0xFE802060] = 0xFFFF;
    MEMORY[0xFE80206C] = 0xFFFF;
    MEMORY[0xFE802058] = 0xFFFF;
    MEMORY[0xFE802064] = 0xFFFF;
    MEMORY[0xFE802070] = 0xFFFF;
  }
  else
  {
    MEMORY[0xFE802058] = MEMORY[0xFE802054];
    MEMORY[0xFE802064] = MEMORY[0xFE802060];
    MEMORY[0xFE802070] = MEMORY[0xFE80206C];
  }
  MEMORY[0xFE80205C] = 0xFFFF;
  MEMORY[0xFE802068] = 0xFFFF;
  MEMORY[0xFE802074] = 0xFFFF;
  MEMORY[0xFE83FFFC] = 0;
  MEMORY[0xFE85FFFC] = 1;
}
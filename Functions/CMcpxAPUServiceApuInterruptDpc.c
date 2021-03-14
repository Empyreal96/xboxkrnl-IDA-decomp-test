void __thiscall CMcpxAPU::ServiceApuInterruptDpc(CMcpxAPU *this)
{
  CMcpxAPU *thisa; // [esp+0h] [ebp-4h]

  for ( thisa = this; ; thisa->m_arInterruptStatus[1].uValue = 0 )
  {
    KeSynchronizeExecution(&CMcpxAPU::m_Interrupt, CMcpxAPU::SynchronizeWithIsr, thisa);
    if ( !(thisa->m_arInterruptStatus[1].uValue & 1) )
      break;
    if ( (thisa->m_arInterruptStatus[1].uValue >> 3) & 1 )
      CMcpxAPU::HandleDeltaPanic();
    if ( (thisa->m_arInterruptStatus[1].uValue >> 6) & 1 )
      CMcpxAPU::ServiceVoiceInterrupt(thisa);
  }
}
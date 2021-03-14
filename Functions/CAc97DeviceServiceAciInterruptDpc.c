void __thiscall CAc97Device::ServiceAciInterruptDpc(CAc97Device *this)
{
  CAc97Device *thisa; // [esp+0h] [ebp-Ch]
  int fContinue; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  thisa = this;
  do
  {
    KeSynchronizeExecution(&CAc97Device::m_Interrupt, CAc97Device::AciSynchronizationRoutine, thisa);
    i = 0;
    fContinue = 0;
    while ( i < 2 )
    {
      if ( thisa->m_abPendingBufferCompletions[i][1] )
      {
        fContinue = 1;
        if ( thisa->m_apChannels[i] )
        {
          do
          {
            CAc97Channel::ServiceInterrupt(thisa->m_apChannels[i]);
            --thisa->m_abPendingBufferCompletions[i][1];
          }
          while ( thisa->m_abPendingBufferCompletions[i][1] );
        }
        else
        {
          thisa->m_abPendingBufferCompletions[i][1] = 0;
        }
      }
      ++i;
    }
  }
  while ( fContinue );
}
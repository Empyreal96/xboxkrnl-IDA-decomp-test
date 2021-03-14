int __thiscall CMcpxCore::IdleVoiceProcessor(CMcpxCore *this, int fIdle)
{
  unsigned int v2; // eax
  unsigned int dwTimeout; // [esp+4h] [ebp-10h]
  _MCPX_HW_NOTIFICATION *pNotifier; // [esp+10h] [ebp-4h]

  dwTimeout = 667;
  if ( fIdle )
  {
    fIdle = 0;
    if ( !(MEMORY[0xFE801100] >> 5) && (MEMORY[0xFE802000] >> 3) & 3 )
    {
      fIdle = 1;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE82010C] = 0;
      if ( this->m_ctxMemory[4].VirtualAddress )
      {
        pNotifier = CMcpxCore::GetNotifier(this, 0);
        pNotifier->Status = -128;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820104] = 2;
        do
        {
          if ( pNotifier->Status == 1 )
            break;
          KeStallExecutionProcessor(1u);
          v2 = dwTimeout--;
        }
        while ( v2 );
      }
      else
      {
        KeStallExecutionProcessor(0x29Bu);
      }
    }
  }
  else
  {
    while ( MEMORY[0xFE820010] < 4u )
      ;
    MEMORY[0xFE82010C] = 1;
  }
  return fIdle;
}
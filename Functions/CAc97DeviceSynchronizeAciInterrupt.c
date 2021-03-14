void __thiscall CAc97Device::SynchronizeAciInterrupt(CAc97Device *this)
{
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    this->m_abPendingBufferCompletions[i][1] += this->m_abPendingBufferCompletions[i][0];
    this->m_abPendingBufferCompletions[i][0] = 0;
  }
}
unsigned int __usercall CAc97Device::ServiceAciInterrupt@<eax>(CAc97Device *this@<ecx>, int *a2@<edi>)
{
  CAc97Device *thisa; // [esp+0h] [ebp-14h]
  unsigned int dwStatus; // [esp+4h] [ebp-10h]
  unsigned __int16 wChannelStatus; // [esp+8h] [ebp-Ch]
  unsigned int dwInterruptMask; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  thisa = this;
  dwStatus = CAc97Device::GetInterruptStatus();
  if ( !dwStatus )
    return 0;
  dwInterruptMask = 2147483648;
  for ( i = 0; i < 2; ++i )
  {
    if ( *(_DWORD *)(4 * i - 2146508016) & dwStatus && thisa->m_apChannels[i] )
    {
      wChannelStatus = CAc97Channel::PeekAciRegister16(thisa->m_apChannels[i], 6u);
      if ( wChannelStatus & 8 )
      {
        dwInterruptMask |= 1 << i;
        if ( thisa->m_dwFlags & 1 )
          CAc97Channel::ServiceInterrupt(thisa->m_apChannels[i]);
        else
          ++thisa->m_abPendingBufferCompletions[i][0];
      }
      CAc97Channel::PokeAciRegister16(thisa->m_apChannels[i], 6u, wChannelStatus);
    }
  }
  if ( !(thisa->m_dwFlags & 1) && dwInterruptMask & 3 )
    KeInsertQueueDpc(0, (int)&thisa->m_dpc, a2, &thisa->m_dpc, 0, 0);
  CAc97Device::PokeAciRegister32(0x30u, dwStatus & 0xFFFFFFFE);
  return dwInterruptMask;
}
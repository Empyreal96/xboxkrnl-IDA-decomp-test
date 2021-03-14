int __userpurge CMcpxBuffer::Play@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>, int fLoop)
{
  unsigned int v4; // eax
  CMcpxBuffer *thisa; // [esp+0h] [ebp-48h]
  unsigned int dwEndBufferOffset; // [esp+4h] [ebp-44h]
  unsigned int dwEndBufferOffseta; // [esp+4h] [ebp-44h]
  int hr; // [esp+8h] [ebp-40h]
  unsigned int dwLoopBackOffset; // [esp+Ch] [ebp-3Ch]
  MCPX_VOICE_VOLUME Volume; // [esp+10h] [ebp-38h]
  unsigned int i; // [esp+34h] [ebp-14h]
  unsigned int dwState; // [esp+38h] [ebp-10h]
  unsigned int dwCurrentBufferOffset; // [esp+3Ch] [ebp-Ch]
  CIrql irql; // [esp+40h] [ebp-8h]

  thisa = this;
  dwCurrentBufferOffset = 0;
  hr = CMcpxBuffer::AllocateBufferResources(this, a2, a3);
  if ( hr >= 0 && !(thisa->m_pSettings->m_dwFlags & 0x2000) )
  {
    CIrql::Raise(&irql);
    if ( fLoop )
    {
      thisa->m_RegCache.CfgFMT = thisa->m_RegCache.CfgFMT & 0xFDFFFFFF | 0x2000000;
      dwLoopBackOffset = CMcpxVoiceClient::BytesToSamples(
                           (CMcpxVoiceClient *)&thisa->vfptr,
                           thisa->m_pSettings->m_dwLoopStart);
      dwEndBufferOffset = CMcpxVoiceClient::BytesToSamples(
                            (CMcpxVoiceClient *)&thisa->vfptr,
                            thisa->m_pSettings->m_dwLoopLength + thisa->m_pSettings->m_dwLoopStart);
      thisa->m_dwStatus |= 0x10u;
    }
    else
    {
      thisa->m_RegCache.CfgFMT &= 0xFDFFFFFF;
      dwLoopBackOffset = 0;
      dwEndBufferOffset = CMcpxVoiceClient::BytesToSamples(
                            (CMcpxVoiceClient *)&thisa->vfptr,
                            thisa->m_pSettings->m_dwBufferSize);
      thisa->m_dwStatus &= 0xFFFFFFEF;
    }
    dwEndBufferOffseta = dwEndBufferOffset - 1;
    for ( i = 0; i < CMcpxVoiceClient::GetHwVoiceCount((CMcpxVoiceClient *)&thisa->vfptr); ++i )
    {
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202F8] = thisa->m_ahVoices[i];
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202FC] = 1;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820304] = CMcpxVoiceClient::GetVoiceCfgFMT((CMcpxVoiceClient *)&thisa->vfptr, i);
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8203DC] = dwEndBufferOffseta;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8203A4] = dwLoopBackOffset;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202FC] = 0;
    }
    if ( !(thisa->m_dwStatus & 2) )
      dwCurrentBufferOffset = CMcpxVoiceClient::BytesToSamples(
                                (CMcpxVoiceClient *)&thisa->vfptr,
                                thisa->m_dwCachedPlayCursor);
    thisa->m_dwCachedPlayCursor = 0;
    if ( dwCurrentBufferOffset )
    {
      thisa->m_RegCache.CfgFMT = thisa->m_RegCache.CfgFMT & 0xFDFFFFFF | 0x2000000;
      for ( i = 0; i < CMcpxVoiceClient::GetHwVoiceCount((CMcpxVoiceClient *)&thisa->vfptr); ++i )
      {
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE8202F8] = thisa->m_ahVoices[i];
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE8202FC] = 1;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820304] = CMcpxVoiceClient::GetVoiceCfgFMT((CMcpxVoiceClient *)&thisa->vfptr, i);
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820360] = -1;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820364] = -1;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820368] = -1;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE8202FC] = 0;
      }
    }
    CIrql::Lower(&irql);
  }
  if ( hr >= 0 )
    ((void (__thiscall *)(CMcpxBuffer *))thisa->vfptr[1].__vecDelDtor)(thisa);
  if ( hr >= 0 )
    CMcpxBuffer::RemoveDeferredCommand(thisa, a2, 1u);
  if ( hr >= 0 && dwCurrentBufferOffset )
  {
    do
      dwState = *((_DWORD *)thisa->m_pMcpxApu->m_ctxMemory[3].VirtualAddress + 32 * (_DWORD)thisa->m_ahVoices[0] + 21);
    while ( (dwState >> 20) & 1 );
    CIrql::Raise(&irql);
    CMcpxVoiceClient::ConvertVolumeValues((CMcpxVoiceClient *)&thisa->vfptr, &Volume);
    if ( !fLoop )
      thisa->m_RegCache.CfgFMT &= 0xFDFFFFFF;
    for ( i = 0; ; ++i )
    {
      v4 = CMcpxVoiceClient::GetHwVoiceCount((CMcpxVoiceClient *)&thisa->vfptr);
      if ( i >= v4 )
        break;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202F8] = thisa->m_ahVoices[i];
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202FC] = 1;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820304] = CMcpxVoiceClient::GetVoiceCfgFMT((CMcpxVoiceClient *)&thisa->vfptr, i);
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820360] = Volume.TarVOLA[i];
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820364] = Volume.TarVOLB[i];
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820368] = Volume.TarVOLC[i];
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8203D8] = dwCurrentBufferOffset;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202FC] = 0;
    }
    CIrql::Lower(&irql);
  }
  if ( hr >= 0 && !(thisa->m_pSettings->m_dwFlags & 0x82000) && thisa->m_EventSink.OnPositionDelta )
    CMcpxBuffer::ScheduleDeferredCommand(thisa, a2, 0, 0i64, 0);
  return hr;
}
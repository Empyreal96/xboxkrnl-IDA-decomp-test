void __thiscall CMcpxAPU::ServiceDeferredCommandsHigh(CMcpxAPU *this)
{
  CMcpxAPU *thisa; // [esp+4h] [ebp-18h]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-14h]
  MCPX_DEFERRED_COMMAND *pCmd; // [esp+10h] [ebp-Ch]
  __int64 rtCurrentTime; // [esp+14h] [ebp-8h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  while ( thisa->m_lstDeferredCommandsHigh.Flink != &thisa->m_lstDeferredCommandsHigh )
  {
    pCmd = (MCPX_DEFERRED_COMMAND *)thisa->m_lstDeferredCommandsHigh.Flink;
    KeQuerySystemTime((_LARGE_INTEGER *)&rtCurrentTime);
    if ( pCmd->rtTimestamp > rtCurrentTime )
    {
      KeSetTimer(
        (int)&thisa->m_tmrDeferredCommandsHigh,
        HIDWORD(pCmd->rtTimestamp),
        &thisa->m_tmrDeferredCommandsHigh,
        (_LARGE_INTEGER)pCmd->rtTimestamp,
        &thisa->m_dpcDeferredCommandsHigh);
      break;
    }
    pCmd->dwFlags &= 0xFFFFFFFD;
    RemoveEntryList(&pCmd->leListEntry);
    ((void (__thiscall *)(CMcpxVoiceClient *, unsigned int, unsigned int))pCmd->pVoice->vfptr[2].__vecDelDtor)(
      pCmd->pVoice,
      pCmd->dwCommand,
      pCmd->dwContext);
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}
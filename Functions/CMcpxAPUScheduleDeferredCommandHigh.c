int __userpurge CMcpxAPU::ScheduleDeferredCommandHigh@<eax>(CMcpxAPU *this@<ecx>, int *a2@<edi>, MCPX_DEFERRED_COMMAND *pCmd)
{
  int v3; // ecx
  CMcpxAPU *thisa; // [esp+18h] [ebp-18h]
  int fScheduled; // [esp+1Ch] [ebp-14h]
  __int64 rtCurrentTime; // [esp+20h] [ebp-10h]
  _LIST_ENTRY *pleNextEntry; // [esp+2Ch] [ebp-4h]

  thisa = this;
  if ( !pCmd->rtTimestamp )
    return 0;
  KeQuerySystemTime((_LARGE_INTEGER *)&rtCurrentTime);
  if ( SHIDWORD(pCmd->rtTimestamp) <= 0 && (pCmd->rtTimestamp < 0 || !LODWORD(pCmd->rtTimestamp)) )
  {
    v3 = (unsigned __int64)(rtCurrentTime - pCmd->rtTimestamp) >> 32;
    LODWORD(pCmd->rtTimestamp) = rtCurrentTime - LODWORD(pCmd->rtTimestamp);
    HIDWORD(pCmd->rtTimestamp) = v3;
  }
  fScheduled = pCmd->rtTimestamp > rtCurrentTime;
  if ( pCmd->rtTimestamp > rtCurrentTime )
  {
    if ( pCmd->dwFlags & 2 )
      CMcpxAPU::RemoveDeferredCommand(thisa, a2, pCmd);
    for ( pleNextEntry = thisa->m_lstDeferredCommandsHigh.Flink;
          pleNextEntry != &thisa->m_lstDeferredCommandsHigh && *(_QWORD *)&pleNextEntry[2] <= pCmd->rtTimestamp;
          pleNextEntry = pleNextEntry->Flink )
    {
      ;
    }
    InsertTailList(pleNextEntry, &pCmd->leListEntry);
    if ( pCmd == (MCPX_DEFERRED_COMMAND *)thisa->m_lstDeferredCommandsHigh.Flink )
      KeSetTimer(
        HIDWORD(pCmd->rtTimestamp),
        pCmd->rtTimestamp,
        &thisa->m_tmrDeferredCommandsHigh,
        (_LARGE_INTEGER)pCmd->rtTimestamp,
        &thisa->m_dpcDeferredCommandsHigh);
  }
  return fScheduled;
}
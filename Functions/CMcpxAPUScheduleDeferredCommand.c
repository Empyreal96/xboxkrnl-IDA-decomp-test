int __userpurge CMcpxAPU::ScheduleDeferredCommand@<eax>(CMcpxAPU *this@<ecx>, int *a2@<edi>, MCPX_DEFERRED_COMMAND *pCmd)
{
  int v3; // ST08_4
  CMcpxAPU *thisa; // [esp+0h] [ebp-14h]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-Ch]
  int fScheduled; // [esp+10h] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( pCmd->dwFlags & 1 )
    fScheduled = CMcpxAPU::ScheduleDeferredCommandLow(thisa, pCmd);
  else
    fScheduled = CMcpxAPU::ScheduleDeferredCommandHigh(thisa, a2, pCmd);
  if ( fScheduled )
    pCmd->dwFlags |= 2u;
  v3 = fScheduled;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return v3;
}
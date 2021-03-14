void __userpurge CMcpxAPU::RemoveDeferredCommand(CMcpxAPU *this@<ecx>, int *a2@<edi>, MCPX_DEFERRED_COMMAND *pCmd)
{
  CMcpxAPU *thisa; // [esp+0h] [ebp-Ch]
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-8h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( pCmd->dwFlags & 2 )
  {
    if ( pCmd->dwFlags & 1 )
      CMcpxAPU::RemoveDeferredCommandLow(thisa, pCmd);
    else
      CMcpxAPU::RemoveDeferredCommandHigh(thisa, a2, pCmd);
  }
  pCmd->dwFlags &= 0xFFFFFFFD;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}
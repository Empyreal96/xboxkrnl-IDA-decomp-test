void __userpurge CMcpxAPU::RemoveDeferredCommandHigh(CMcpxAPU *this@<ecx>, int *a2@<edi>, MCPX_DEFERRED_COMMAND *pCmd)
{
  int v3; // edx
  int v4; // ecx
  CMcpxAPU *thisa; // [esp+0h] [ebp-8h]
  int fListHead; // [esp+4h] [ebp-4h]

  thisa = this;
  fListHead = this->m_lstDeferredCommandsHigh.Flink == (_LIST_ENTRY *)pCmd;
  RemoveEntryList(&pCmd->leListEntry);
  if ( thisa->m_lstDeferredCommandsHigh.Flink == &thisa->m_lstDeferredCommandsHigh )
  {
    KeCancelTimer((int)thisa, (int)&thisa->m_tmrDeferredCommandsHigh, &thisa->m_tmrDeferredCommandsHigh);
    KeRemoveQueueDpc(v3, v4, a2, &thisa->m_dpcDeferredCommandsHigh);
  }
  else if ( fListHead )
  {
    KeSetTimer(
      (int)thisa->m_lstDeferredCommandsHigh.Flink[2].Blink,
      (int)thisa->m_lstDeferredCommandsHigh.Flink[2].Flink,
      &thisa->m_tmrDeferredCommandsHigh,
      (_LARGE_INTEGER)thisa->m_lstDeferredCommandsHigh.Flink[2],
      &thisa->m_dpcDeferredCommandsHigh);
  }
}
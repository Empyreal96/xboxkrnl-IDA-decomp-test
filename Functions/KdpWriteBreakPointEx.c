int __stdcall KdpWriteBreakPointEx(_DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
{
  int v2; // edx
  unsigned int v3; // eax
  int result; // eax
  unsigned int v5; // ebx
  int *v6; // edi
  unsigned int v7; // ebx
  _DBGKD_WRITE_BREAKPOINT64 *v8; // edi
  unsigned int v9; // eax
  _DBGKD_WRITE_BREAKPOINT64 BpBuf[32]; // [esp+4h] [ebp-208h]
  _STRING MessageHeader; // [esp+204h] [ebp-8h]

  v2 = AdditionalData->Length;
  v3 = 16 * m->u.GetContext.Unused;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)m;
  if ( v2 == v3 )
  {
    KdpQuickMoveMemory(BpBuf, AdditionalData->Buffer, v3);
    v5 = 0;
    m->ReturnStatus = 0;
    if ( m->u.GetContext.Unused )
    {
      v6 = (int *)&BpBuf[0].BreakPointHandle;
      do
      {
        if ( *v6 )
        {
          if ( !KdpDeleteBreakpoint(v6, *v6) )
            m->ReturnStatus = -1073741823;
          *v6 = 0;
        }
        ++v5;
        v6 += 4;
      }
      while ( v5 < m->u.GetContext.Unused );
    }
    v7 = 0;
    v8 = BpBuf;
    if ( m->u.GetContext.Unused )
    {
      do
      {
        if ( v8->BreakPointAddress )
        {
          v9 = KdpAddBreakpoint((void *)v8->BreakPointAddress);
          v8->BreakPointHandle = v9;
          if ( !v9 )
            m->ReturnStatus = -1073741823;
        }
        ++v7;
        ++v8;
      }
      while ( v7 < m->u.GetContext.Unused );
    }
    KdpQuickMoveMemory(AdditionalData->Buffer, BpBuf, 16 * m->u.GetContext.Unused);
    KdPhysicalPort->SendPacket(2u, &MessageHeader, AdditionalData);
    result = m->u.BreakPointEx.ContinueStatus;
  }
  else
  {
    m->ReturnStatus = -1073741823;
    KdPhysicalPort->SendPacket(2u, &MessageHeader, AdditionalData);
    result = m->ReturnStatus;
  }
  return result;
}
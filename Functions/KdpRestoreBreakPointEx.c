void __stdcall KdpRestoreBreakPointEx(_DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
{
  _DBGKD_MANIPULATE_STATE64 *v2; // esi
  int v3; // ecx
  unsigned int v4; // eax
  _DBGKD_RESTORE_BREAKPOINT *v5; // ebx
  _DBGKD_RESTORE_BREAKPOINT BpBuf[32]; // [esp+8h] [ebp-88h]
  _STRING MessageHeader; // [esp+88h] [ebp-8h]
  unsigned int i; // [esp+98h] [ebp+8h]

  v2 = m;
  v3 = AdditionalData->Length;
  v4 = 4 * m->u.GetContext.Unused;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)m;
  if ( v3 == v4 )
  {
    KdpQuickMoveMemory(BpBuf, AdditionalData->Buffer, v4);
    m->ReturnStatus = 0;
    v5 = BpBuf;
    i = 0;
    if ( v2->u.GetContext.Unused )
    {
      do
      {
        if ( !KdpDeleteBreakpoint((int *)AdditionalData, v5->BreakPointHandle) )
          v2->ReturnStatus = -1073741823;
        ++i;
        ++v5;
      }
      while ( i < v2->u.GetContext.Unused );
    }
    KdPhysicalPort->SendPacket(2u, &MessageHeader, AdditionalData);
  }
  else
  {
    m->ReturnStatus = -1073741823;
    KdPhysicalPort->SendPacket(2u, &MessageHeader, AdditionalData);
  }
}
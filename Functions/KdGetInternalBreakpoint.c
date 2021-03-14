void __stdcall KdGetInternalBreakpoint(_DBGKD_MANIPULATE_STATE64 *m)
{
  unsigned int v1; // ecx
  DBGKD_INTERNAL_BREAKPOINT *v2; // esi
  unsigned __int64 *v3; // ecx
  _STRING messageHeader; // [esp+Ch] [ebp-8h]

  v1 = 0;
  messageHeader.Length = 56;
  messageHeader.Buffer = (char *)m;
  if ( !KdpNumInternalBreakpoints )
    goto LABEL_9;
  v2 = KdpInternalBPs;
  while ( v2->Flags & 6
       || LODWORD(v2->Addr) != m->u.GetContext.Unused
       || HIDWORD(v2->Addr) != m->u.Continue2.ControlSet.TraceFlag )
  {
    ++v1;
    ++v2;
    if ( v1 >= KdpNumInternalBreakpoints )
      goto LABEL_9;
  }
  v3 = &KdpInternalBPs[v1].Addr;
  if ( v3 )
  {
    m->u.SearchMemory.SearchLength = v3[1];
    m->u.ReadWriteIoExtended.IoAddress = *(unsigned __int64 *)((char *)v3 + 20);
    m->u.GetVersion64.PsLoadedModuleList = *(unsigned __int64 *)((char *)v3 + 28);
    m->ReturnStatus = 0;
  }
  else
  {
LABEL_9:
    m->u.SearchMemory.SearchLength = 2i64;
    m->u.ReadWriteIoExtended.IoAddress = 0i64;
    m->u.GetVersion64.PsLoadedModuleList = 0i64;
    m->ReturnStatus = -1073741823;
  }
  m->ApiNumber = 12611;
  KdPhysicalPort->SendPacket(2u, &messageHeader, 0);
}
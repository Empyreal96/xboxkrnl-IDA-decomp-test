void __stdcall KdpGetVersion(_DBGKD_MANIPULATE_STATE64 *m)
{
  _STRING messageHeader; // [esp+8h] [ebp-8h]

  memset(&m->u, 0, sizeof(m->u));
  m->u.GetInternalBreakpoint.MinInstructions = -1;
  m->ReturnStatus = 0;
  m->u.GetVersion64.MajorVersion = 268;
  m->u.GetVersion64.PsLoadedModuleList = (signed int)&KdLoadedModuleList;
  *((_DWORD *)&m->u.GetSetBusData + 8) = &KdpDebuggerDataListHead;
  m->u.GetVersion64.MinorVersion = 5455;
  m->u.GetVersion64.ProtocolVersion = 5;
  m->u.GetVersion64.Flags = 2;
  m->u.GetVersion64.MachineType = 332;
  m->u.Continue2.ControlSet.CurrentSymbolEnd = (unsigned int)osfile;
  *((_DWORD *)&m->u.GetSetBusData + 9) = (signed int)&KdpDebuggerDataListHead >> 31;
  m->ApiNumber = 12614;
  messageHeader.Length = 56;
  messageHeader.Buffer = (char *)m;
  KdPhysicalPort->SendPacket(2u, &messageHeader, 0);
}
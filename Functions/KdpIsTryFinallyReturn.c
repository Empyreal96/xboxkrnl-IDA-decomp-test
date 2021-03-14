bool __stdcall KdpIsTryFinallyReturn(unsigned int Pc, _CONTEXT *ContextRecord)
{
  bool result; // al
  unsigned int calldisp; // [esp+4h] [ebp-8h]
  unsigned int retaddr; // [esp+8h] [ebp-4h]

  KdpMoveMemory(&retaddr, (void *)ContextRecord->Esp, 4u, 1);
  result = 0;
  if ( KdpCurrentSymbolStart < retaddr && retaddr < KdpCurrentSymbolEnd )
  {
    KdpMoveMemory((char *)&ContextRecord + 3, (void *)(retaddr - 5), 1u, 1);
    KdpMoveMemory(&calldisp, (void *)(retaddr - 4), 4u, 1);
    if ( HIBYTE(ContextRecord) != -24 || retaddr + calldisp != Pc )
    {
      KdpMoveMemory((char *)&ContextRecord + 3, (void *)(Pc - 1), 1u, 1);
      if ( HIBYTE(ContextRecord) != -55 )
        result = 1;
    }
  }
  return result;
}
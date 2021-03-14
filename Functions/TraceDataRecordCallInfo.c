char __stdcall TraceDataRecordCallInfo(unsigned int InstructionsTraced, int CallLevelChange, unsigned int pc)
{
  int v3; // eax
  char v4; // dl
  unsigned int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ecx

  v3 = SymNumFor(pc);
  v4 = KdpNextCallLevelChange;
  v5 = TraceDataBufferPosition;
  if ( KdpNextCallLevelChange )
  {
    KdpNextCallLevelChange = 0;
    *(_BYTE *)(4 * TraceDataBufferPosition - 2147115519) = v4;
  }
  if ( InstructionsTraced < 0xFFFF )
  {
    *(_WORD *)(4 * v5 - 2147115518) = InstructionsTraced;
  }
  else
  {
    *(_WORD *)(4 * v5 - 2147115518) = -1;
    *(_DWORD *)(4 * v5++ - 2147115516) = InstructionsTraced;
  }
  v6 = v5 + 1;
  TraceDataBufferPosition = v6;
  if ( (unsigned int)(v6 + 2) >= 0x28 )
    goto LABEL_14;
  if ( v3 != -1 )
  {
    v7 = v6;
    *(_BYTE *)(v7 * 4 - 2147115519) = CallLevelChange;
    TraceDataBuffer[v7].s.SymbolNumber = v3;
    v8 = 2 * v3;
    v9 = TraceDataSyms[v8 / 2].SymMin;
    KdpCurrentSymbolEnd = dword_80059604[v8];
    KdpCurrentSymbolStart = v9;
    return 1;
  }
  if ( (unsigned int)(v6 + 2) >= 0x28 )
LABEL_14:
    TraceDataBufferFilled = 1;
  KdpNextCallLevelChange = CallLevelChange;
  return 0;
}
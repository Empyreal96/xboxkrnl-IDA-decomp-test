void __stdcall PotentialNewSymbol(unsigned int pc)
{
  unsigned int v1; // esi
  int v2; // eax
  unsigned int v3; // ecx
  unsigned int v4; // eax
  char v5; // al
  int v6; // ecx
  unsigned int v7; // edx
  int v8; // edx

  if ( TraceDataBufferFilled || SymNumFor(pc) == -1 )
  {
    v1 = TraceDataBufferPosition;
    TraceDataBufferFilled = 0;
    TraceDataBuffer[TraceDataBufferPosition].s.LevelChange = 0;
    if ( SymNumFor(pc) == -1 )
    {
      v5 = NextTraceDataSym;
      v6 = (unsigned __int8)NextTraceDataSym;
      *(_DWORD *)(8 * v6 - 2147117568) = KdpCurrentSymbolStart;
      v7 = KdpCurrentSymbolEnd;
      TraceDataBuffer[v1].s.SymbolNumber = v5;
      *(_DWORD *)(8 * v6 - 2147117564) = v7;
      v8 = (v6 + 1) % 256;
      NextTraceDataSym = v8;
      if ( (unsigned __int8)NumTraceDataSyms < (unsigned __int8)v8 )
        NumTraceDataSyms = v8;
    }
    else
    {
      v2 = SymNumFor(pc);
      TraceDataBuffer[v1].s.SymbolNumber = v2;
      v2 *= 8;
      v3 = *(unsigned int *)((char *)&TraceDataSyms[0].SymMin + v2);
      v4 = *(int *)((char *)dword_80059604 + v2);
      KdpCurrentSymbolStart = v3;
      KdpCurrentSymbolEnd = v4;
    }
  }
}
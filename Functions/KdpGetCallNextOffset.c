_CONTEXT *__stdcall KdpGetCallNextOffset(unsigned int Pc, _CONTEXT *ContextRecord)
{
  unsigned int v2; // edi
  unsigned int v4; // eax

  v2 = Pc;
  KdpMoveMemory((char *)&Pc + 2, (void *)Pc, 2u, 1);
  switch ( BYTE2(Pc) )
  {
    case 0xE8:
      return (_CONTEXT *)(v2 + 5);
    case 0x9A:
      return (_CONTEXT *)(v2 + 7);
    case 0xFF:
      if ( HIBYTE(Pc) == 37 )
        return KdpGetReturnAddress(ContextRecord);
      v4 = (unsigned int)HIBYTE(Pc) >> 6;
      if ( v4 )
      {
        if ( v4 != 2 )
        {
          if ( v4 == 3 )
            v4 = 0;
          return (_CONTEXT *)(((HIBYTE(Pc) & 7) == 4) + v4 + v2 + 2);
        }
      }
      else if ( (HIBYTE(Pc) & 7) != 5 )
      {
        return (_CONTEXT *)(((HIBYTE(Pc) & 7) == 4) + v4 + v2 + 2);
      }
      v4 = 4;
      return (_CONTEXT *)(((HIBYTE(Pc) & 7) == 4) + v4 + v2 + 2);
  }
  return 0;
}
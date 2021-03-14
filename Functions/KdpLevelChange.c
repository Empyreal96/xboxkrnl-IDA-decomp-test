int __stdcall KdpLevelChange(unsigned int Pc, _CONTEXT *ContextRecord, char *SpecialCall)
{
  unsigned int v3; // esi
  char v4; // al
  int v5; // eax
  char v6; // al
  _CONTEXT *v7; // ST0C_4
  char *v8; // edi
  int result; // eax
  char v10; // al
  int membuf; // [esp+8h] [ebp-8h]

  v3 = Pc;
  KdpMoveMemory(&membuf, (void *)Pc, 2u, 1);
  v4 = membuf;
  switch ( (_BYTE)membuf )
  {
    case 0x9A:
LABEL_22:
      v10 = KdpIsSpecialCall(v3, ContextRecord, v4, SBYTE1(membuf));
      goto LABEL_23;
    case 0xC2:
      goto LABEL_20;
    case 0xC3:
      if ( KdpIsTryFinallyReturn(v3, ContextRecord) )
        goto LABEL_18;
      goto LABEL_20;
  }
  if ( (unsigned __int8)membuf <= 0xC9u )
  {
LABEL_18:
    result = 0;
LABEL_19:
    *SpecialCall = 0;
    return result;
  }
  if ( (unsigned __int8)membuf <= 0xCBu )
  {
LABEL_20:
    result = -1;
    goto LABEL_19;
  }
  if ( (_BYTE)membuf == -24 )
  {
    KdpMoveMemory(&Pc, (void *)(v3 + 1), 4u, 1);
    Pc += v3 + 5;
    if ( KdpCurrentSymbolStart <= Pc && Pc < KdpCurrentSymbolEnd )
      goto LABEL_16;
    v4 = membuf;
    goto LABEL_22;
  }
  if ( (_BYTE)membuf != -1 )
    goto LABEL_18;
  v5 = BYTE1(membuf) & 0x38;
  if ( v5 == 16 )
  {
    v10 = KdpIsSpecialCall(v3, ContextRecord, 255, SBYTE1(membuf));
LABEL_23:
    *SpecialCall = v10;
    return 1;
  }
  if ( v5 != 32 )
  {
LABEL_16:
    *SpecialCall = 0;
    return 0;
  }
  v6 = KdpIsSpecialCall(v3, ContextRecord, 255, SBYTE1(membuf));
  v7 = ContextRecord;
  v8 = SpecialCall;
  *SpecialCall = v6;
  if ( KdpIsTryFinallyReturn(v3, v7) )
    result = *v8 == 0;
  else
    result = -(*v8 != 0);
  return result;
}
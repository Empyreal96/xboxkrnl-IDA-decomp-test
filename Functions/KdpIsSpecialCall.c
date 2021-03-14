// local variable allocation has failed, the output may be wrong!
char __stdcall KdpIsSpecialCall(unsigned int Pc, _CONTEXT *ContextRecord, char opcode, char modRM)
{
  unsigned int v4; // esi
  unsigned int v5; // eax
  int v6; // esi
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // eax
  char v11; // cl
  int v12; // edx
  unsigned int addrAddr; // [esp+Ch] [ebp-Ch]
  int offset; // [esp+10h] [ebp-8h]
  unsigned int callAddr; // [esp+14h] [ebp-4h]

  callAddr = 0;
  if ( opcode == -24 )
  {
    v4 = Pc;
    KdpMoveMemory(&offset, (void *)(Pc + 1), 4u, 1);
    v5 = offset + v4 + 5;
    goto LABEL_32;
  }
  if ( opcode != -1 )
  {
    if ( opcode == -102 )
    {
      KdpMoveMemory(&callAddr, (void *)(Pc + 1), 4u, 1);
      goto LABEL_31;
    }
    return 0;
  }
  if ( (modRM & 0x38) != 16 && (modRM & 0x38) != 32 || modRM & 8 )
    return 0;
  if ( (modRM & 0xC0) == -64 )
  {
    v5 = regValue(modRM & 7, ContextRecord);
    goto LABEL_32;
  }
  if ( (modRM & 0xC7) != 5 )
  {
    if ( (modRM & 7) == 4 )
    {
      v6 = Pc;
      KdpMoveMemory(&opcode + 3, (void *)(Pc + 2), 1u, 1);
      v8 = regValue(((unsigned __int8)*(&opcode + 3) >> 3) & 6, ContextRecord);
      switch ( v7 & 0xC0 )
      {
        case 64:
          v8 *= 2;
          break;
        case 128:
          v8 *= 4;
          break;
        case 192:
          v8 *= 8;
          break;
      }
      if ( modRM & 0xC0 )
      {
        if ( (modRM & 0xC0) == 64 )
        {
          if ( (v7 & 6) != 4 )
          {
            KdpMoveMemory((char *)&Pc + 3, (void *)(v6 + 3), 1u, 1);
            v10 = regValue(*(&opcode + 3) & 7, ContextRecord);
            v5 = v8 + v10 + SHIBYTE(Pc);
            goto LABEL_32;
          }
        }
        else
        {
          if ( (modRM & 0xC0) != 128 )
          {
            if ( (modRM & 0xC0) == 192 )
              RtlAssert(
                64,
                v7,
                (int *)v8,
                v6,
                "FALSE",
                "d:\\xbox-apr03\\private\\ntos\\kd64\\i386\\kdcpuapi.c",
                0x194u,
                0);
            goto LABEL_31;
          }
          if ( (v7 & 6) != 4 )
          {
            KdpMoveMemory(&offset, (void *)(v6 + 3), 4u, 1);
            v9 = regValue(*(&opcode + 3) & 7, ContextRecord);
            v5 = offset + v8 + v9;
            goto LABEL_32;
          }
        }
      }
      else
      {
        v11 = v7 & 7;
        if ( v11 != 5 )
        {
          v5 = v8 + regValue(v11, ContextRecord);
          goto LABEL_32;
        }
      }
    }
    return 0;
  }
  KdpMoveMemory(&addrAddr, (void *)(Pc + 2), 4u, 1);
  KdpMoveMemory(&callAddr, (void *)addrAddr, 4u, 1);
LABEL_31:
  v5 = callAddr;
LABEL_32:
  v12 = 0;
  if ( !KdNumberOfSpecialCalls )
    return 0;
  while ( *(_DWORD *)(4 * v12 - 2147115272) != v5 )
  {
    if ( ++v12 >= KdNumberOfSpecialCalls )
      return 0;
  }
  return 1;
}
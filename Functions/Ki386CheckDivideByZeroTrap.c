int __stdcall Ki386CheckDivideByZeroTrap(_KTRAP_FRAME *TrapFrame)
{
  _KTRAP_FRAME *v1; // ecx
  unsigned __int8 *v2; // edx
  unsigned __int8 v3; // bl
  unsigned __int8 v4; // al
  char *v5; // edx
  KMOD *v6; // esi
  unsigned __int8 v7; // bl
  unsigned int v8; // edi
  unsigned __int8 v9; // al
  unsigned int v10; // esi
  unsigned int v11; // eax
  int v12; // edx
  KMOD *Mod; // [esp+Ch] [ebp-3Ch]
  int status; // [esp+10h] [ebp-38h]
  char *pRM; // [esp+14h] [ebp-34h]
  unsigned int operandmask; // [esp+18h] [ebp-30h]
  unsigned int operandsize; // [esp+24h] [ebp-24h]
  char fPrefix; // [esp+2Eh] [ebp-1Ah]
  char ibyte; // [esp+2Fh] [ebp-19h]

  status = -1073741676;
  fPrefix = 1;
  pRM = RM32;
  operandsize = 4;
  operandmask = -1;
  v1 = TrapFrame;
  v2 = (unsigned __int8 *)TrapFrame->Eip;
  v3 = ibyte;
  while ( fPrefix )
  {
    v3 = *v2++;
    if ( (signed int)v3 > 101 )
    {
      if ( v3 == 102 )
      {
        operandsize = 2;
        operandmask = 0xFFFF;
      }
      else
      {
        if ( v3 == 103 )
          return status;
        if ( v3 != 240 && ((signed int)v3 <= 241 || (signed int)v3 > 243) )
LABEL_15:
          fPrefix = 0;
      }
    }
    else if ( (signed int)v3 < 100 && v3 != 38 && v3 != 46 && v3 != 54 && v3 != 62 )
    {
      goto LABEL_15;
    }
  }
  if ( v3 == -9 || v3 == -10 )
  {
    if ( v3 == -10 )
    {
      operandsize = 1;
      operandmask = 255;
    }
    v4 = *v2;
    v5 = (char *)(v2 + 1);
    v6 = (KMOD *)(4 * ((unsigned int)v4 >> 6) - 2147172824);
    Mod = (KMOD *)(4 * ((unsigned int)v4 >> 6) - 2147172824);
    v7 = v4 & 7;
    if ( operandsize == 1 && (v4 & 0xC0) == -64 )
      pRM = RM8;
    v8 = 0;
    if ( v7 != v6->RmDisplaceOnly )
    {
      if ( v7 == v6->RmSib )
      {
        v9 = *v5++;
        v10 = v9;
        v11 = ((unsigned int)v9 >> 3) & 7;
        if ( v11 != 4 )
        {
          v8 = *(unsigned int *)((char *)&TrapFrame->DbgEbp + (unsigned __int8)RM32[v11]) << (v10 >> 6);
          v1 = TrapFrame;
        }
        v8 += *(unsigned int *)((char *)&v1->DbgEbp + (unsigned __int8)RM32[v10 & 7]);
        v6 = Mod;
      }
      else
      {
        v8 = *(unsigned int *)((char *)&TrapFrame->DbgEbp + (unsigned __int8)pRM[v7]);
      }
    }
    if ( (unsigned __int8)(1 << v7) & v6->RmDisplace )
    {
      if ( v6->Disp == 4 )
        v12 = *(_DWORD *)v5;
      else
        v12 = *v5;
      v8 += v12;
    }
    if ( v6->Disp )
    {
      switch ( operandsize )
      {
        case 1u:
          v8 = *(unsigned __int8 *)v8;
          break;
        case 2u:
          v8 = *(unsigned __int16 *)v8;
          break;
        case 4u:
          v8 = *(_DWORD *)v8;
          break;
      }
    }
    if ( v8 & operandmask )
      status = -1073741675;
  }
  return status;
}
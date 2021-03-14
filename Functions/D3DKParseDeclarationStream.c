void __stdcall D3DK::ParseDeclarationStream(D3DK::VertexShader *pVertexShader, const unsigned int *pDeclaration, int IsFixedFunction)
{
  D3DK::VertexShader *v3; // ebx
  int *i; // edi
  unsigned int v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  int v8; // eax
  unsigned __int8 v9; // di
  unsigned int v10; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  signed int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int streamIndex; // [esp+Ch] [ebp-8h]
  unsigned int offset; // [esp+10h] [ebp-4h]
  unsigned int token; // [esp+1Ch] [ebp+8h]

  v3 = pVertexShader;
  offset = 0;
  streamIndex = 0;
LABEL_2:
  for ( i = (int *)pDeclaration; ; D3DK::DXGRIP(i, "Unidentified token type: 0x%lx", v5) )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v5 = *i;
        v6 = *i;
        ++i;
        v7 = v6 & 0xE0000000;
        token = v5;
        pDeclaration = (const unsigned int *)i;
        if ( v7 > 0x60000000 )
          break;
        if ( v7 == 1610612736 )
        {
          v16 = v5 & 0x1F;
          v17 = v16 + 3;
          v18 = (int)v3 + 16 * v16;
          *(&v3->Signature + 4 * v17) = 0;
          *(_DWORD *)(v18 + 44) = 0;
          *(_DWORD *)(v18 + 52) = 2;
          *(_BYTE *)(v18 + 57) = (v5 >> 20) & 0xF;
          *(_BYTE *)(v18 + 56) = ((v5 & 0x10000000) != 0) + 1;
        }
        else if ( v7 )
        {
          if ( v7 == 0x20000000 )
          {
            D3DK::ASSERTMSG(i, (v5 & 0xFFFFFF0) == 0, "Bad declaration STREAM token: 0x%lx", v5);
            streamIndex = v5 & 0xF;
            offset = 0;
          }
          else
          {
            if ( v7 != 0x40000000 )
              goto LABEL_43;
            if ( !(v5 & 0x10000000) )
            {
              D3DK::ASSERTMSG(i, (v5 & 0xF00FFE0) == 0, "Bad declaration REG token: 0x%lx", v5);
              v9 = BYTE2(v5);
              v10 = v5 & 0x1F;
              if ( v10 > 0xF )
              {
                D3DK::DXGRIP((int *)BYTE2(token), "Can't specify a register more than 15");
                v10 = 15;
              }
              if ( (v9 & 0xF0u) > 0x70 || (v9 & 0xFu) > 6 )
                D3DK::DXGRIP((int *)BYTE2(token), "Invalid type encoding");
              v11 = v10;
              if ( IsFixedFunction && v10 >= 9 && v10 <= 0xC )
                v11 = v10 + 7;
              v12 = 16 * (v11 + 3);
              v13 = (int)v3 + 16 * v11;
              *(unsigned int *)((char *)&v3->Signature + v12) = offset;
              *(_DWORD *)(v13 + 44) = streamIndex;
              *(_DWORD *)(v13 + 52) = BYTE2(token);
              *(_BYTE *)(v13 + 56) = 0;
              if ( !IsFixedFunction )
                goto LABEL_38;
              if ( v10 >= 9 && v10 <= 0xC )
              {
                v14 = v9 >> 4;
                if ( v14 == 7 )
                {
                  v14 = 4;
                }
                else if ( BYTE2(token) == 22 )
                {
                  v14 = 3;
                }
                ++v3->TextureCount;
                *((_DWORD *)v3 + v10 - 2) = v14;
              }
              switch ( v10 )
              {
                case 3u:
                  v15 = v3->Flags | 0x400;
                  break;
                case 4u:
                  v15 = v3->Flags | 0x800;
                  break;
                case 7u:
                  v15 = v3->Flags | 0x1000;
                  break;
                case 8u:
                  v15 = v3->Flags | 0x2000;
                  break;
                default:
LABEL_38:
                  offset += (unsigned __int8)D3DK::g_BytesPerUnit[v9 & 0xF]
                          * (unsigned __int8)D3DK::g_UnitsOfElement[v9 >> 4];
                  goto LABEL_2;
              }
              v3->Flags = v15;
              goto LABEL_38;
            }
            D3DK::ASSERTMSG(i, (v5 & 0x7F0FFFF) == 0, "Bad declaration SKIP token: 0x%lx", v5);
            v8 = (v5 >> 16) & 0xF;
            if ( !(v5 & 0x8000000) )
              v8 *= 4;
            offset += v8;
          }
        }
      }
      if ( v7 != 0x80000000 )
        break;
      D3DK::ASSERTMSG(i, (v5 & 0x1FFFF00) == 0, "Bad delcaration CONST token: 0x%lx", v5);
      i += 4 * ((v5 >> 25) & 0xF);
    }
    if ( v7 == -536870912 )
      break;
LABEL_43:
    ;
  }
}
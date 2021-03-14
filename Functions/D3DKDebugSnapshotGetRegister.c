void __thiscall D3DK::DebugSnapshot::GetRegister(D3DK::DebugSnapshot *this, unsigned int dwReg, unsigned int i)
{
  D3DK::DebugSnapshot *v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // ecx
  signed int v6; // esi
  unsigned int v7; // edi
  signed int v8; // ecx
  D3DK::_regval *v9; // eax
  __int16 v10; // cx
  __int16 v11; // cx
  int *v12; // edi
  D3DK::_regval *v13; // eax
  __int16 v14; // cx
  int v15; // [esp+4h] [ebp-14h]
  unsigned int dwDepth; // [esp+8h] [ebp-10h]
  unsigned int v17; // [esp+Ch] [ebp-Ch]
  unsigned int dwEnd; // [esp+10h] [ebp-8h]
  unsigned int dwIter; // [esp+14h] [ebp-4h]

  v3 = this;
  if ( D3DK::g_pDevice->m_dwSnapshot == 18 )
  {
    v4 = 3;
    dwEnd = 3;
  }
  else
  {
    v4 = 1;
    dwEnd = 2;
  }
  v5 = v4;
  dwIter = v4;
  if ( v4 <= dwEnd )
  {
    v6 = i;
    while ( 1 )
    {
      v7 = dwReg;
      if ( v5 != 2 )
        break;
      if ( dwReg == 14 )
      {
        v3->cpt.sum.a = 0;
      }
      else
      {
        if ( dwReg != 15 )
        {
          v8 = 16;
LABEL_13:
          if ( v6 == 8 )
          {
            v17 = dwReg | v8;
            if ( dwReg == 3 || dwReg == 14 || dwReg == 15 )
              LOBYTE(v7) = 0;
            D3DDevice_SetRenderStateNotInline(D3DRS_PSFINALCOMBINERINPUTSABCD, (dwReg | v8 | ((dwReg | v8) << 8)) << 8);
            D3DDevice_SetRenderStateNotInline(
              D3DRS_PSFINALCOMBINERINPUTSEFG,
              ((unsigned __int8)(v7 & 0xEF) << 8) | 0x1080);
            v7 = dwReg;
          }
          else
          {
            v17 = dwReg | v8;
            D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v6 + 34), ((dwReg | v8) << 24) | 0xC0200000);
            D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)v6, (dwReg << 24) | 0xD0301010);
            D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v6 + 45), 0xC0u);
            D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v6 + 26), 0xC0u);
          }
          D3DK::DebugSnapshot::DrawVertices(v3);
          D3DK::DebugSnapshot::GetColorAndDepth(v3, (int *)v7, &i, &dwDepth);
          v15 = v7 - 1;
          switch ( v7 )
          {
            case 1u:
              v9 = &v3->cpt.c0[v6];
              goto LABEL_34;
            case 2u:
              v9 = &v3->cpt.c1[v6];
              goto LABEL_34;
            case 3u:
              v9 = &v3->cpt.fog;
              goto LABEL_34;
            case 4u:
              v9 = &v3->cpt.v0[v6];
              goto LABEL_34;
            case 5u:
              v9 = &v3->cpt.v1[v6];
              goto LABEL_34;
            case 8u:
              v9 = &v3->cpt.t0[v6];
              goto LABEL_34;
            case 9u:
              v9 = &v3->cpt.t1[v6];
              goto LABEL_34;
            case 0xAu:
              v9 = &v3->cpt.t2[v6];
              goto LABEL_34;
            case 0xBu:
              v9 = &v3->cpt.t3[v6];
              goto LABEL_34;
            case 0xCu:
              v9 = &v3->cpt.r0[v6];
              goto LABEL_34;
            case 0xDu:
              v9 = &v3->cpt.r1[v6];
              goto LABEL_34;
            case 0xEu:
              v9 = &v3->cpt.sum;
              goto LABEL_34;
            case 0xFu:
              v9 = &v3->cpt.prod;
LABEL_34:
              if ( !v9 )
                goto LABEL_42;
              switch ( dwIter )
              {
                case 1u:
                  v9->r = BYTE2(i);
                  break;
                case 2u:
                  v9->a = (unsigned __int8)i;
                  goto LABEL_42;
                case 3u:
                  v10 = BYTE2(i);
                  v9->a = HIBYTE(i);
                  v9->r = v10;
                  break;
                default:
                  goto LABEL_42;
              }
              v11 = (unsigned __int8)i;
              v9->g = BYTE1(i);
              v9->b = v11;
LABEL_42:
              if ( v6 != 8 )
              {
                D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v6 + 34), (v17 << 24) | 0xC0202020);
                v12 = (int *)((v7 << 24) | 0xD0303030);
                D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)v6, (unsigned int)v12);
                D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v6 + 45), 0xC00u);
                D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v6 + 26), 0xC00u);
                D3DK::DebugSnapshot::DrawVertices(v3);
                D3DK::DebugSnapshot::GetColorAndDepth(v3, v12, &i, &dwDepth);
                switch ( v15 )
                {
                  case 0:
                    v13 = &v3->cpt.c0[v6];
                    goto LABEL_54;
                  case 1:
                    v13 = &v3->cpt.c1[v6];
                    goto LABEL_54;
                  case 3:
                    v13 = &v3->cpt.v0[v6];
                    goto LABEL_54;
                  case 4:
                    v13 = &v3->cpt.v1[v6];
                    goto LABEL_54;
                  case 7:
                    v13 = &v3->cpt.t0[v6];
                    goto LABEL_54;
                  case 8:
                    v13 = &v3->cpt.t1[v6];
                    goto LABEL_54;
                  case 9:
                    v13 = &v3->cpt.t2[v6];
                    goto LABEL_54;
                  case 10:
                    v13 = &v3->cpt.t3[v6];
                    goto LABEL_54;
                  case 11:
                    v13 = &v3->cpt.r0[v6];
                    goto LABEL_54;
                  case 12:
                    v13 = &v3->cpt.r1[v6];
LABEL_54:
                    if ( !v13 )
                      goto LABEL_66;
                    switch ( dwIter )
                    {
                      case 1u:
                        goto LABEL_60;
                      case 2u:
                        if ( (unsigned __int8)i != 255 )
                          v13->a = (unsigned __int8)i - 255;
                        break;
                      case 3u:
                        if ( HIBYTE(i) != 255 )
                          v13->a = HIBYTE(i) - 255;
LABEL_60:
                        if ( BYTE2(i) != 255 )
                          v13->r = BYTE2(i) - 255;
                        LOBYTE(v14) = i;
                        if ( BYTE1(i) != 255 )
                          v13->g = BYTE1(i) - 255;
                        v14 = (unsigned __int8)v14;
                        if ( (unsigned __int8)v14 != 255 )
                          v13->b = v14 - 255;
                        break;
                    }
                    break;
                  default:
                    goto LABEL_66;
                }
              }
              break;
            default:
              goto LABEL_42;
          }
          goto LABEL_66;
        }
        v3->cpt.prod.a = 0;
      }
LABEL_66:
      v5 = dwIter++ + 1;
      if ( dwIter > dwEnd )
        return;
    }
    v8 = 0;
    goto LABEL_13;
  }
}
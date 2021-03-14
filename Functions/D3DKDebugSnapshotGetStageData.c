void __thiscall D3DK::DebugSnapshot::GetStageData(D3DK::DebugSnapshot *this, unsigned int i)
{
  D3DK::DebugSnapshot *v2; // ebx
  _D3DRENDERSTATETYPE v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int *v6; // edi
  __int16 v7; // dx
  __int16 v8; // ax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  int *v11; // edi
  __int16 v12; // dx
  __int16 v13; // ax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  D3DK::_regval *v16; // ebx
  int *v17; // edi
  __int16 v18; // dx
  __int16 v19; // ax
  D3DK::DebugSnapshot *v20; // edi
  __int16 v21; // ax
  unsigned int v22; // ecx
  unsigned int v23; // eax
  D3DK::_regval *v24; // ebx
  int *v25; // edi
  __int16 v26; // dx
  __int16 v27; // ax
  D3DK::DebugSnapshot *v28; // edi
  __int16 v29; // ax
  unsigned int v30; // ecx
  unsigned int v31; // eax
  D3DK::_regval *v32; // ebx
  int *v33; // edi
  __int16 v34; // dx
  __int16 v35; // ax
  D3DK::DebugSnapshot *v36; // edi
  __int16 v37; // ax
  unsigned int v38; // ecx
  unsigned int v39; // eax
  D3DK::_regval *v40; // ebx
  int *v41; // edi
  __int16 v42; // dx
  __int16 v43; // ax
  D3DK::DebugSnapshot *v44; // edi
  __int16 v45; // ax
  D3DK::DebugSnapshot *v46; // edi
  unsigned int pDepth; // [esp+Ch] [ebp-10h]
  unsigned int v48; // [esp+10h] [ebp-Ch]
  unsigned int v49; // [esp+14h] [ebp-8h]
  D3DK::DebugSnapshot *v50; // [esp+18h] [ebp-4h]

  v2 = this;
  v50 = this;
  D3DK::DebugSnapshot::RestoreUserState(this);
  D3DK::DebugSnapshot::SetPassThroughState(v2);
  v3 = i;
  if ( i != 8 )
  {
    D3DDevice_SetRenderStateNotInline(D3DRS_PSCOMBINERCOUNT, i + 1);
    goto LABEL_34;
  }
  D3DK::DebugSnapshot::GetRegister(v2, 3u, 8u);
  if ( D3DK::g_pDevice->m_dwSnapshot == 18 )
  {
    v4 = 3;
    v5 = 3;
  }
  else
  {
    v5 = 1;
    v4 = 2;
  }
  v48 = v4;
  v49 = v5;
  if ( v5 <= v4 )
  {
    v6 = (int *)&v2->cpt.sum.a;
    do
    {
      if ( v49 == 2 )
      {
        *(_WORD *)v6 = 0;
      }
      else
      {
        D3DDevice_SetRenderStateNotInline(D3DRS_PSFINALCOMBINERINPUTSABCD, 0xE0E00u);
        D3DDevice_SetRenderStateNotInline(D3DRS_PSFINALCOMBINERINPUTSEFG, 0x1080u);
        D3DK::DebugSnapshot::DrawVertices(v2);
        D3DK::DebugSnapshot::GetColorAndDepth(v2, v6, &i, &pDepth);
        if ( v2 != (D3DK::DebugSnapshot *)-788 )
        {
          switch ( v49 )
          {
            case 1u:
              goto LABEL_15;
            case 2u:
              *(_WORD *)v6 = (unsigned __int8)i;
              break;
            case 3u:
              *(_WORD *)v6 = HIBYTE(i);
LABEL_15:
              v7 = BYTE1(i);
              v8 = (unsigned __int8)i;
              v2->cpt.sum.r = BYTE2(i);
              v2->cpt.sum.g = v7;
              v2->cpt.sum.b = v8;
              break;
          }
        }
      }
      ++v49;
    }
    while ( v49 <= v48 );
  }
  if ( D3DK::g_pDevice->m_dwSnapshot == 18 )
  {
    v9 = 3;
    v10 = 3;
  }
  else
  {
    v10 = 1;
    v9 = 2;
  }
  v48 = v9;
  v49 = v10;
  if ( v10 <= v9 )
  {
    v11 = (int *)&v2->cpt.prod.a;
    do
    {
      if ( v49 == 2 )
      {
        *(_WORD *)v11 = 0;
      }
      else
      {
        D3DDevice_SetRenderStateNotInline(D3DRS_PSFINALCOMBINERINPUTSABCD, 0xF0F00u);
        D3DDevice_SetRenderStateNotInline(D3DRS_PSFINALCOMBINERINPUTSEFG, 0x1080u);
        D3DK::DebugSnapshot::DrawVertices(v2);
        D3DK::DebugSnapshot::GetColorAndDepth(v2, v11, &i, &pDepth);
        if ( v2 != (D3DK::DebugSnapshot *)-796 )
        {
          switch ( v49 )
          {
            case 1u:
              v2->cpt.prod.r = BYTE2(i);
              goto LABEL_32;
            case 2u:
              *(_WORD *)v11 = (unsigned __int8)i;
              break;
            case 3u:
              v12 = BYTE2(i);
              *(_WORD *)v11 = HIBYTE(i);
              v2->cpt.prod.r = v12;
LABEL_32:
              v13 = (unsigned __int8)i;
              v2->cpt.prod.g = BYTE1(i);
              v2->cpt.prod.b = v13;
              break;
          }
        }
      }
      ++v49;
    }
    while ( v49 <= v48 );
  }
LABEL_34:
  D3DK::DebugSnapshot::GetRegister(v2, 4u, v3);
  D3DK::DebugSnapshot::GetRegister(v2, 5u, v3);
  D3DK::DebugSnapshot::GetRegister(v2, 8u, v3);
  D3DK::DebugSnapshot::GetRegister(v2, 9u, v3);
  if ( D3DK::g_pDevice->m_dwSnapshot == 18 )
  {
    v14 = 3;
    v15 = 3;
  }
  else
  {
    v15 = 1;
    v14 = 2;
  }
  v48 = v14;
  v49 = v15;
  if ( v15 <= v14 )
  {
    v16 = &v50->cpt.t2[v3];
    do
    {
      v17 = (int *)(v49 != 2 ? 0 : 0x10);
      if ( v3 == 8 )
      {
        D3DDevice_SetRenderStateNotInline(
          D3DRS_PSFINALCOMBINERINPUTSABCD,
          ((v49 != 2 ? 0 : 0x10) | ((v49 != 2 ? 0 : 0x10) << 8) | 0xA0A) << 8);
        D3DDevice_SetRenderStateNotInline(D3DRS_PSFINALCOMBINERINPUTSEFG, 0x1A80u);
      }
      else
      {
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 34), ((v49 != 2 ? 0 : 0x10) << 24) | 0xCA200000);
        D3DDevice_SetRenderStateNotInline(v3, 0xDA301010);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 45), 0xC0u);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 26), 0xC0u);
      }
      D3DK::DebugSnapshot::DrawVertices(v50);
      D3DK::DebugSnapshot::GetColorAndDepth(v50, v17, &i, &pDepth);
      if ( !v16 )
        goto LABEL_50;
      switch ( v49 )
      {
        case 1u:
          v16->r = BYTE2(i);
          break;
        case 2u:
          v16->a = (unsigned __int8)i;
          goto LABEL_50;
        case 3u:
          v18 = BYTE2(i);
          v16->a = HIBYTE(i);
          v16->r = v18;
          break;
        default:
          goto LABEL_50;
      }
      v19 = (unsigned __int8)i;
      v16->g = BYTE1(i);
      v16->b = v19;
LABEL_50:
      if ( v3 != 8 )
      {
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 34), ((_DWORD)v17 << 24) | 0xCA202020);
        D3DDevice_SetRenderStateNotInline(v3, 0xDA303030);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 45), 0xC00u);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 26), 0xC00u);
        v20 = v50;
        D3DK::DebugSnapshot::DrawVertices(v50);
        D3DK::DebugSnapshot::GetColorAndDepth(v20, (int *)v20, &i, &pDepth);
        if ( v16 )
        {
          switch ( v49 )
          {
            case 1u:
              goto LABEL_57;
            case 2u:
              if ( (unsigned __int8)i != 255 )
                v16->a = (unsigned __int8)i - 255;
              break;
            case 3u:
              if ( HIBYTE(i) != 255 )
                v16->a = HIBYTE(i) - 255;
LABEL_57:
              if ( BYTE2(i) != 255 )
                v16->r = BYTE2(i) - 255;
              LOBYTE(v21) = i;
              if ( BYTE1(i) != 255 )
                v16->g = BYTE1(i) - 255;
              v21 = (unsigned __int8)v21;
              if ( (unsigned __int8)v21 != 255 )
                v16->b = v21 - 255;
              break;
          }
        }
      }
      ++v49;
    }
    while ( v49 <= v48 );
  }
  if ( D3DK::g_pDevice->m_dwSnapshot == 18 )
  {
    v22 = 3;
    v23 = 3;
  }
  else
  {
    v23 = 1;
    v22 = 2;
  }
  v48 = v22;
  v49 = v23;
  if ( v23 <= v22 )
  {
    v24 = &v50->cpt.t3[v3];
    while ( 1 )
    {
      v25 = (int *)(v49 != 2 ? 0 : 0x10);
      if ( v3 == 8 )
      {
        D3DDevice_SetRenderStateNotInline(
          D3DRS_PSFINALCOMBINERINPUTSABCD,
          ((v49 != 2 ? 0 : 0x10) | ((v49 != 2 ? 0 : 0x10) << 8) | 0xB0B) << 8);
        D3DDevice_SetRenderStateNotInline(D3DRS_PSFINALCOMBINERINPUTSEFG, 0x1B80u);
      }
      else
      {
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 34), ((v49 != 2 ? 0 : 0x10) << 24) | 0xCB200000);
        D3DDevice_SetRenderStateNotInline(v3, 0xDB301010);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 45), 0xC0u);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 26), 0xC0u);
      }
      D3DK::DebugSnapshot::DrawVertices(v50);
      D3DK::DebugSnapshot::GetColorAndDepth(v50, v25, &i, &pDepth);
      if ( !v24 )
        goto LABEL_80;
      if ( v49 == 1 )
        goto LABEL_79;
      if ( v49 != 2 )
        break;
      v24->a = (unsigned __int8)i;
LABEL_80:
      if ( v3 != 8 )
      {
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 34), ((_DWORD)v25 << 24) | 0xCB202020);
        D3DDevice_SetRenderStateNotInline(v3, 0xDB303030);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 45), 0xC00u);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 26), 0xC00u);
        v28 = v50;
        D3DK::DebugSnapshot::DrawVertices(v50);
        D3DK::DebugSnapshot::GetColorAndDepth(v28, (int *)v28, &i, &pDepth);
        if ( v24 )
        {
          switch ( v49 )
          {
            case 1u:
              goto LABEL_87;
            case 2u:
              if ( (unsigned __int8)i != 255 )
                v24->a = (unsigned __int8)i - 255;
              break;
            case 3u:
              if ( HIBYTE(i) != 255 )
                v24->a = HIBYTE(i) - 255;
LABEL_87:
              if ( BYTE2(i) != 255 )
                v24->r = BYTE2(i) - 255;
              LOBYTE(v29) = i;
              if ( BYTE1(i) != 255 )
                v24->g = BYTE1(i) - 255;
              v29 = (unsigned __int8)v29;
              if ( (unsigned __int8)v29 != 255 )
                v24->b = v29 - 255;
              break;
          }
        }
      }
      if ( ++v49 > v48 )
        goto LABEL_94;
    }
    if ( v49 != 3 )
      goto LABEL_80;
    v24->a = HIBYTE(i);
LABEL_79:
    v26 = BYTE1(i);
    v27 = (unsigned __int8)i;
    v24->r = BYTE2(i);
    v24->g = v26;
    v24->b = v27;
    goto LABEL_80;
  }
LABEL_94:
  if ( D3DK::g_pDevice->m_dwSnapshot == 18 )
  {
    v30 = 3;
    v31 = 3;
  }
  else
  {
    v31 = 1;
    v30 = 2;
  }
  v48 = v30;
  v49 = v31;
  if ( v31 <= v30 )
  {
    v32 = &v50->cpt.r0[v3];
    do
    {
      v33 = (int *)(v49 != 2 ? 0 : 0x10);
      if ( v3 == 8 )
      {
        D3DDevice_SetRenderStateNotInline(
          D3DRS_PSFINALCOMBINERINPUTSABCD,
          ((v49 != 2 ? 0 : 0x10) | ((v49 != 2 ? 0 : 0x10) << 8) | 0xC0C) << 8);
        D3DDevice_SetRenderStateNotInline(D3DRS_PSFINALCOMBINERINPUTSEFG, 0x1C80u);
      }
      else
      {
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 34), ((v49 != 2 ? 0 : 0x10) << 24) | 0xCC200000);
        D3DDevice_SetRenderStateNotInline(v3, 0xDC301010);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 45), 0xC0u);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 26), 0xC0u);
      }
      D3DK::DebugSnapshot::DrawVertices(v50);
      D3DK::DebugSnapshot::GetColorAndDepth(v50, v33, &i, &pDepth);
      if ( !v32 )
        goto LABEL_113;
      switch ( v49 )
      {
        case 1u:
          v32->r = BYTE2(i);
          break;
        case 2u:
          v32->a = (unsigned __int8)i;
          goto LABEL_113;
        case 3u:
          v34 = BYTE2(i);
          v32->a = HIBYTE(i);
          v32->r = v34;
          break;
        default:
          goto LABEL_113;
      }
      v35 = (unsigned __int8)i;
      v32->g = BYTE1(i);
      v32->b = v35;
LABEL_113:
      if ( v3 != 8 )
      {
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 34), ((_DWORD)v33 << 24) | 0xCC202020);
        D3DDevice_SetRenderStateNotInline(v3, 0xDC303030);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 45), 0xC00u);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 26), 0xC00u);
        v36 = v50;
        D3DK::DebugSnapshot::DrawVertices(v50);
        D3DK::DebugSnapshot::GetColorAndDepth(v36, (int *)v36, &i, &pDepth);
        if ( v32 )
        {
          switch ( v49 )
          {
            case 1u:
              goto LABEL_120;
            case 2u:
              if ( (unsigned __int8)i != 255 )
                v32->a = (unsigned __int8)i - 255;
              break;
            case 3u:
              if ( HIBYTE(i) != 255 )
                v32->a = HIBYTE(i) - 255;
LABEL_120:
              if ( BYTE2(i) != 255 )
                v32->r = BYTE2(i) - 255;
              LOBYTE(v37) = i;
              if ( BYTE1(i) != 255 )
                v32->g = BYTE1(i) - 255;
              v37 = (unsigned __int8)v37;
              if ( (unsigned __int8)v37 != 255 )
                v32->b = v37 - 255;
              break;
          }
        }
      }
      ++v49;
    }
    while ( v49 <= v48 );
  }
  if ( D3DK::g_pDevice->m_dwSnapshot == 18 )
  {
    v38 = 3;
    v39 = 3;
  }
  else
  {
    v39 = 1;
    v38 = 2;
  }
  v48 = v38;
  v49 = v39;
  if ( v39 <= v38 )
  {
    v40 = &v50->cpt.r1[v3];
    while ( 1 )
    {
      v41 = (int *)(v49 != 2 ? 0 : 0x10);
      if ( v3 == 8 )
      {
        D3DDevice_SetRenderStateNotInline(
          D3DRS_PSFINALCOMBINERINPUTSABCD,
          ((v49 != 2 ? 0 : 0x10) | ((v49 != 2 ? 0 : 0x10) << 8) | 0xD0D) << 8);
        D3DDevice_SetRenderStateNotInline(D3DRS_PSFINALCOMBINERINPUTSEFG, 0x1D80u);
      }
      else
      {
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 34), ((v49 != 2 ? 0 : 0x10) << 24) | 0xCD200000);
        D3DDevice_SetRenderStateNotInline(v3, 0xDD301010);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 45), 0xC0u);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 26), 0xC0u);
      }
      D3DK::DebugSnapshot::DrawVertices(v50);
      D3DK::DebugSnapshot::GetColorAndDepth(v50, v41, &i, &pDepth);
      if ( !v40 )
        goto LABEL_143;
      if ( v49 == 1 )
        goto LABEL_142;
      if ( v49 != 2 )
        break;
      v40->a = (unsigned __int8)i;
LABEL_143:
      if ( v3 != 8 )
      {
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 34), ((_DWORD)v41 << 24) | 0xCD202020);
        D3DDevice_SetRenderStateNotInline(v3, 0xDD303030);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 45), 0xC00u);
        D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v3 + 26), 0xC00u);
        v44 = v50;
        D3DK::DebugSnapshot::DrawVertices(v50);
        D3DK::DebugSnapshot::GetColorAndDepth(v44, (int *)v44, &i, &pDepth);
        if ( v40 )
        {
          switch ( v49 )
          {
            case 1u:
              goto LABEL_150;
            case 2u:
              if ( (unsigned __int8)i != 255 )
                v40->a = (unsigned __int8)i - 255;
              break;
            case 3u:
              if ( HIBYTE(i) != 255 )
                v40->a = HIBYTE(i) - 255;
LABEL_150:
              if ( BYTE2(i) != 255 )
                v40->r = BYTE2(i) - 255;
              LOBYTE(v45) = i;
              if ( BYTE1(i) != 255 )
                v40->g = BYTE1(i) - 255;
              v45 = (unsigned __int8)v45;
              if ( (unsigned __int8)v45 != 255 )
                v40->b = v45 - 255;
              break;
          }
        }
      }
      if ( ++v49 > v48 )
        goto LABEL_157;
    }
    if ( v49 != 3 )
      goto LABEL_143;
    v40->a = HIBYTE(i);
LABEL_142:
    v42 = BYTE1(i);
    v43 = (unsigned __int8)i;
    v40->r = BYTE2(i);
    v40->g = v42;
    v40->b = v43;
    goto LABEL_143;
  }
LABEL_157:
  v46 = v50;
  D3DK::DebugSnapshot::GetRegister(v50, 1u, v3);
  D3DK::DebugSnapshot::GetRegister(v46, 2u, v3);
}
// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DK::LazySetTextureTransform(D3DK::CDevice *pDevice)
{
  D3DK::CDevice *v1; // ebx
  int *v2; // edi
  int v3; // esi
  unsigned int *v4; // eax
  signed int v5; // eax
  D3DK::VertexShader *v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // ebx
  int v9; // esi
  double v10; // st7
  double v11; // st6
  double v12; // st7
  double v13; // st6
  double v14; // st5
  double v15; // st7
  double v16; // st6
  double v17; // st7
  double v18; // st6
  double v19; // st7
  double v20; // st6
  double v21; // st5
  double v22; // st7
  double v23; // st6
  double v24; // st7
  double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st5
  double v29; // st7
  double v30; // st6
  double v31; // st7
  double v32; // st6
  double v33; // st5
  double v34; // st7
  double v35; // st6
  double v36; // st5
  double v37; // st7
  double v38; // st6
  double v39; // st7
  double v40; // st6
  double v41; // st5
  double v42; // st7
  double v43; // st6
  double v44; // st5
  double v45; // st7
  double v46; // st6
  double v47; // st5
  double v48; // st7
  double v49; // st6
  double v50; // st5
  double v51; // st7
  double v52; // st6
  double v53; // st5
  double v54; // st7
  double v55; // st6
  double v56; // st5
  double v57; // st7
  double v58; // st6
  double v59; // st5
  double v60; // st7
  double v61; // st6
  double v62; // st5
  double v63; // st7
  double v64; // st6
  double v65; // st5
  double v66; // st7
  double v67; // st6
  double v68; // st5
  double v69; // st7
  double v70; // st6
  double v71; // st5
  double v72; // st6
  double v73; // st5
  bool v74; // cf
  int *v75; // [esp+4h] [ebp-Ch]
  signed int method; // [esp+8h] [ebp-8h]
  unsigned int *pPush; // [esp+Ch] [ebp-4h]
  unsigned int *pPusha; // [esp+Ch] [ebp-4h]

  ++D3DK::g_PerfCounters.m_PerformanceCounters[27].Count;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == 27
    && D3DK::g_PerfCounters.m_PerformanceCounters[27].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  v1 = pDevice;
  v1->m_DirtyFlags &= 0xFFFFFFFB;
  if ( !(pDevice->m_pVertexShader->Flags & 6) )
  {
    method = 1056;
    v75 = dword_800C2238;
    v2 = (int *)&pDevice->m_Transform[2].m[2][3];
    while ( 1 )
    {
      v3 = *(v75 - 19);
      v4 = XMETAL_StartPush(v2, &v1->m_Pusher);
      pPush = v4;
      if ( v3 )
        break;
      XMETAL_Push1f(v2, v4, method, 0.0);
      XMETAL_EndPush(v2, &v1->m_Pusher, pPush + 2);
LABEL_34:
      v2 += 16;
      v74 = (unsigned int)(method + 4) < 0x430;
      method += 4;
      v75 += 32;
      if ( !v74 )
        return;
    }
    if ( *v75 & 0xFFFF0000 )
    {
      v5 = 3;
    }
    else
    {
      v6 = v1->m_pVertexShader;
      v7 = *v75 & 0xFFFF;
      if ( v7 >= v6->TextureCount )
        v5 = 2;
      else
        v5 = v6->Dimensionality[v7];
    }
    v8 = ((unsigned __int8)v3 >> 8) | 16 * (16 * v5 | (unsigned __int8)v3);
    XMETAL_Push1f(v2, pPush, method, COERCE_FLOAT(1));
    XMETAL_PushCount(v2, pPush + 2, (unsigned int)((char *)v2 - 620 - (_DWORD)pDevice), 0x10u);
    v9 = (int)(pPush + 3);
    pPusha = pPush + 19;
    if ( v8 > 0x241 )
    {
      if ( v8 != 800 )
      {
        if ( v8 != 816 )
        {
          if ( v8 == 817 )
          {
            v51 = *((float *)v2 + 1);
            v52 = *((float *)v2 - 3);
            v53 = *((float *)v2 - 7);
            *(_DWORD *)v9 = *(v2 - 11);
            *(float *)(v9 + 4) = v53;
            *(float *)(v9 + 8) = v52;
            *(float *)(v9 + 12) = v51;
            v54 = *((float *)v2 + 2);
            v55 = *((float *)v2 - 2);
            v56 = *((float *)v2 - 6);
            *(float *)(v9 + 16) = *((float *)v2 - 10);
            *(float *)(v9 + 20) = v56;
            *(float *)(v9 + 24) = v55;
            *(float *)(v9 + 28) = v54;
            *(_DWORD *)(v9 + 32) = 0;
            *(_DWORD *)(v9 + 36) = 0;
            *(_DWORD *)(v9 + 40) = 0;
            *(_DWORD *)(v9 + 44) = 0;
            v57 = *((float *)v2 + 3);
            v58 = *((float *)v2 - 1);
            v59 = *((float *)v2 - 5);
            *(float *)(v9 + 48) = *((float *)v2 - 9);
            *(float *)(v9 + 52) = v59;
            *(float *)(v9 + 56) = v58;
            *(float *)(v9 + 60) = v57;
            goto LABEL_33;
          }
LABEL_25:
          D3DK::ASSERTMSG(v2, v8 == 833, "Unhandled texture transform type");
          v39 = *((float *)v2 + 1);
          v40 = *((float *)v2 - 3);
          v41 = *((float *)v2 - 7);
          *(_DWORD *)v9 = *(v2 - 11);
          *(float *)(v9 + 4) = v41;
          *(float *)(v9 + 8) = v40;
          *(float *)(v9 + 12) = v39;
          v42 = *((float *)v2 + 2);
          v43 = *((float *)v2 - 2);
          v44 = *((float *)v2 - 6);
          *(float *)(v9 + 16) = *((float *)v2 - 10);
          *(float *)(v9 + 20) = v44;
          *(float *)(v9 + 24) = v43;
          *(float *)(v9 + 28) = v42;
          v45 = *((float *)v2 + 3);
          v46 = *((float *)v2 - 1);
          v47 = *((float *)v2 - 5);
          *(float *)(v9 + 32) = *((float *)v2 - 9);
          *(float *)(v9 + 36) = v47;
          *(float *)(v9 + 40) = v46;
          *(float *)(v9 + 44) = v45;
          v48 = *((float *)v2 + 4);
          v49 = *(float *)v2;
          v50 = *((float *)v2 - 4);
          *(float *)(v9 + 48) = *((float *)v2 - 8);
          *(float *)(v9 + 52) = v50;
          *(float *)(v9 + 56) = v49;
          *(float *)(v9 + 60) = v48;
LABEL_33:
          XMETAL_EndPush(v2, &pDevice->m_Pusher, pPusha);
          v1 = pDevice;
          goto LABEL_34;
        }
        v60 = *((float *)v2 + 1);
        v61 = *((float *)v2 - 3);
        v62 = *((float *)v2 - 7);
        *(_DWORD *)v9 = *(v2 - 11);
        *(float *)(v9 + 4) = v62;
        *(float *)(v9 + 8) = v61;
        *(float *)(v9 + 12) = v60;
        v63 = *((float *)v2 + 2);
        v64 = *((float *)v2 - 2);
        v65 = *((float *)v2 - 6);
        *(float *)(v9 + 16) = *((float *)v2 - 10);
        *(float *)(v9 + 20) = v65;
        *(float *)(v9 + 24) = v64;
        *(float *)(v9 + 28) = v63;
        v66 = *((float *)v2 + 3);
        v67 = *((float *)v2 - 1);
        v68 = *((float *)v2 - 5);
        *(float *)(v9 + 32) = *((float *)v2 - 9);
        *(float *)(v9 + 36) = v68;
        *(float *)(v9 + 40) = v67;
        *(float *)(v9 + 44) = v66;
LABEL_31:
        *(_DWORD *)(v9 + 48) = 0;
        *(_DWORD *)(v9 + 52) = 0;
        *(_DWORD *)(v9 + 60) = 1065353216;
        goto LABEL_32;
      }
      v69 = *((float *)v2 + 1);
      v70 = *((float *)v2 - 3);
      v71 = *((float *)v2 - 7);
      *(_DWORD *)v9 = *(v2 - 11);
      *(float *)(v9 + 4) = v71;
      *(float *)(v9 + 8) = v70;
      *(float *)(v9 + 12) = v69;
      v26 = *((float *)v2 + 2);
      v72 = *((float *)v2 - 2);
      v73 = *((float *)v2 - 6);
      *(float *)(v9 + 16) = *((float *)v2 - 10);
      *(float *)(v9 + 20) = v73;
      *(float *)(v9 + 24) = v72;
    }
    else
    {
      if ( v8 == 577 )
      {
        v29 = *((float *)v2 - 3);
        v30 = *((float *)v2 - 7);
        *(_DWORD *)v9 = *(v2 - 11);
        *(float *)(v9 + 4) = v30;
        *(_DWORD *)(v9 + 8) = 0;
        *(float *)(v9 + 12) = v29;
        v31 = *((float *)v2 - 2);
        v32 = *((float *)v2 - 6);
        v33 = *((float *)v2 - 10);
        *(_DWORD *)(v9 + 24) = 0;
        *(float *)(v9 + 16) = v33;
        *(float *)(v9 + 20) = v32;
        *(float *)(v9 + 28) = v31;
        v34 = *((float *)v2 - 1);
        v35 = *((float *)v2 - 5);
        v36 = *((float *)v2 - 9);
        *(_DWORD *)(v9 + 40) = 0;
        *(float *)(v9 + 32) = v36;
        *(float *)(v9 + 36) = v35;
        *(float *)(v9 + 44) = v34;
        v37 = *(float *)v2;
        v38 = *((float *)v2 - 4);
        *(float *)(v9 + 48) = *((float *)v2 - 8);
        *(float *)(v9 + 52) = v38;
        *(float *)(v9 + 60) = v37;
        goto LABEL_32;
      }
      if ( v8 != 544 )
      {
        if ( v8 != 560 )
        {
          if ( v8 == 561 )
          {
            v10 = *((float *)v2 - 3);
            v11 = *((float *)v2 - 7);
            *(_DWORD *)v9 = *(v2 - 11);
            *(float *)(v9 + 4) = v11;
            *(_DWORD *)(v9 + 8) = 0;
            *(float *)(v9 + 12) = v10;
            v12 = *((float *)v2 - 2);
            v13 = *((float *)v2 - 6);
            v14 = *((float *)v2 - 10);
            *(_DWORD *)(v9 + 24) = 0;
            *(float *)(v9 + 16) = v14;
            *(float *)(v9 + 20) = v13;
            *(float *)(v9 + 28) = v12;
            *(_DWORD *)(v9 + 32) = 0;
            *(_DWORD *)(v9 + 36) = 0;
            *(_DWORD *)(v9 + 40) = 0;
            *(_DWORD *)(v9 + 44) = 0;
            v15 = *((float *)v2 - 1);
            v16 = *((float *)v2 - 5);
            *(float *)(v9 + 48) = *((float *)v2 - 9);
            *(float *)(v9 + 52) = v16;
            *(float *)(v9 + 60) = v15;
LABEL_32:
            *(_DWORD *)(v9 + 56) = 0;
            goto LABEL_33;
          }
          goto LABEL_25;
        }
        v17 = *((float *)v2 - 3);
        v18 = *((float *)v2 - 7);
        *(_DWORD *)v9 = *(v2 - 11);
        *(float *)(v9 + 4) = v18;
        *(_DWORD *)(v9 + 8) = 0;
        *(float *)(v9 + 12) = v17;
        v19 = *((float *)v2 - 2);
        v20 = *((float *)v2 - 6);
        v21 = *((float *)v2 - 10);
        *(_DWORD *)(v9 + 24) = 0;
        *(float *)(v9 + 16) = v21;
        *(float *)(v9 + 20) = v20;
        *(float *)(v9 + 28) = v19;
        v22 = *((float *)v2 - 1);
        v23 = *((float *)v2 - 5);
        *(float *)(v9 + 32) = *((float *)v2 - 9);
        *(float *)(v9 + 36) = v23;
        *(float *)(v9 + 44) = v22;
        goto LABEL_30;
      }
      v24 = *((float *)v2 - 3);
      v25 = *((float *)v2 - 7);
      *(_DWORD *)v9 = *(v2 - 11);
      *(float *)(v9 + 4) = v25;
      *(_DWORD *)(v9 + 8) = 0;
      *(float *)(v9 + 12) = v24;
      v26 = *((float *)v2 - 2);
      v27 = *((float *)v2 - 6);
      v28 = *((float *)v2 - 10);
      *(_DWORD *)(v9 + 24) = 0;
      *(float *)(v9 + 16) = v28;
      *(float *)(v9 + 20) = v27;
    }
    *(float *)(v9 + 28) = v26;
    *(_DWORD *)(v9 + 32) = 0;
    *(_DWORD *)(v9 + 36) = 0;
    *(_DWORD *)(v9 + 44) = 0;
LABEL_30:
    *(_DWORD *)(v9 + 40) = 0;
    goto LABEL_31;
  }
}
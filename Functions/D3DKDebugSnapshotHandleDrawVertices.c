int __thiscall D3DK::DebugSnapshot::HandleDrawVertices(D3DK::DebugSnapshot *this)
{
  D3DK::DebugSnapshot *v1; // esi
  unsigned int *v2; // ebx
  int *v3; // edi
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  D3DK::CDevice *v10; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // edi
  signed __int16 *v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // eax
  unsigned int v39; // eax
  unsigned int v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // eax
  unsigned int v44; // eax
  unsigned int v45; // eax
  unsigned int v46; // eax
  unsigned int v47; // eax
  unsigned int v48; // eax
  unsigned int v49; // eax
  unsigned int v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // eax
  unsigned int v53; // eax
  unsigned int v54; // eax
  unsigned int v55; // eax
  unsigned int v56; // eax
  unsigned int v57; // eax
  unsigned int v58; // eax
  unsigned int v59; // eax
  unsigned int v60; // eax
  unsigned int v61; // eax
  unsigned int v62; // eax
  unsigned int v63; // eax
  unsigned int v64; // eax
  unsigned int v65; // eax
  unsigned int dwTestDepth; // [esp+10h] [ebp-8h]
  unsigned int i; // [esp+14h] [ebp-4h]

  v1 = this;
  D3DK::DebugSnapshot::SaveUserState(this);
  v2 = &v1->cpt.dwPreDepth;
  v3 = (int *)&v1->cpt;
  D3DK::DebugSnapshot::GetColorAndDepth(v1, (int *)&v1->cpt, &v1->cpt.dwPreColor, &v1->cpt.dwPreDepth);
  D3DK::DebugSnapshot::SetPassThroughState(v1);
  D3DK::DebugSnapshot::DrawVertices(v1);
  D3DK::DebugSnapshot::GetColorAndDepth(v1, (int *)&v1->cpt, &i, &dwTestDepth);
  if ( i == v1->cpt.dwPreColor && dwTestDepth == *v2 )
  {
    D3DK::DebugSnapshot::RestoreUserState(v1);
    D3DK::DebugSnapshot::DrawVertices(v1);
    return 0;
  }
  if ( D3DK::g_pDevice->m_pPixelShader )
  {
    v1->cpt.dwCombinerCount = 0;
    v1->cpt.dwCombinerCount = 0;
    i = 0;
    D3DK::DebugSnapshot::GetStageData(v1, 8u);
    D3DK::DebugSnapshot::SetColorAndDepth(v1, v3, *v3, *v2);
    D3DK::DebugSnapshot::RestoreUserState(v1);
    D3DK::DebugSnapshot::DrawVertices(v1);
    D3DK::DebugSnapshot::GetColorAndDepth(v1, v3, &v1->cpt.dwPostColor, &v1->cpt.dwPostDepth);
    if ( v1->dwCaptureCount < 0x2000 )
    {
      *D3DK::g_pDevice->m_pShaderCapturePtr = 50331653;
      ++D3DK::g_pDevice->m_pShaderCapturePtr;
      ++v1->dwCaptureCount;
    }
    if ( v1->dwCaptureCount < 0x2000 )
    {
      *D3DK::g_pDevice->m_pShaderCapturePtr = *v3;
      ++D3DK::g_pDevice->m_pShaderCapturePtr;
      v13 = v1->dwCaptureCount + 1;
      v1->dwCaptureCount = v13;
      if ( v13 < 0x2000 )
      {
        *D3DK::g_pDevice->m_pShaderCapturePtr = *v2;
        ++D3DK::g_pDevice->m_pShaderCapturePtr;
        v14 = v1->dwCaptureCount + 1;
        v1->dwCaptureCount = v14;
        if ( v14 < 0x2000 )
        {
          *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.dwPostColor;
          ++D3DK::g_pDevice->m_pShaderCapturePtr;
          v15 = v1->dwCaptureCount + 1;
          v1->dwCaptureCount = v15;
          if ( v15 < 0x2000 )
          {
            *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.dwPostDepth;
            ++D3DK::g_pDevice->m_pShaderCapturePtr;
            ++v1->dwCaptureCount;
          }
        }
      }
    }
    v16 = v1->cpt.dwCombinerCount;
    v17 = 0;
    i = 0;
    if ( v16 )
    {
      v18 = &v1->cpt.r0[0].r;
      do
      {
        if ( v1->dwCaptureCount < 0x2000 )
        {
          *D3DK::g_pDevice->m_pShaderCapturePtr = 67108889;
          ++D3DK::g_pDevice->m_pShaderCapturePtr;
          v19 = v1->dwCaptureCount + 1;
          v1->dwCaptureCount = v19;
          if ( v19 < 0x2000 )
          {
            *D3DK::g_pDevice->m_pShaderCapturePtr = *(_DWORD *)(4 * v17 - 2146687920);
            ++D3DK::g_pDevice->m_pShaderCapturePtr;
            v20 = v1->dwCaptureCount + 1;
            v1->dwCaptureCount = v20;
            if ( v20 < 0x2000 )
            {
              *D3DK::g_pDevice->m_pShaderCapturePtr = *(_DWORD *)(4 * i - 2146688056);
              ++D3DK::g_pDevice->m_pShaderCapturePtr;
              v21 = v1->dwCaptureCount + 1;
              v1->dwCaptureCount = v21;
              if ( v21 < 0x2000 )
              {
                *D3DK::g_pDevice->m_pShaderCapturePtr = *(_DWORD *)(4 * i - 2146687876);
                ++D3DK::g_pDevice->m_pShaderCapturePtr;
                v22 = v1->dwCaptureCount + 1;
                v1->dwCaptureCount = v22;
                if ( v22 < 0x2000 )
                {
                  *D3DK::g_pDevice->m_pShaderCapturePtr = *(_DWORD *)(4 * i - 2146687952);
                  ++D3DK::g_pDevice->m_pShaderCapturePtr;
                  v23 = v1->dwCaptureCount + 1;
                  v1->dwCaptureCount = v23;
                  if ( v23 < 0x2000 )
                  {
                    *D3DK::g_pDevice->m_pShaderCapturePtr = *v18 | (*(v18 - 1) << 16);
                    ++D3DK::g_pDevice->m_pShaderCapturePtr;
                    v24 = v1->dwCaptureCount + 1;
                    v1->dwCaptureCount = v24;
                    if ( v24 < 0x2000 )
                    {
                      *D3DK::g_pDevice->m_pShaderCapturePtr = v18[2] | (v18[1] << 16);
                      ++D3DK::g_pDevice->m_pShaderCapturePtr;
                      v25 = v1->dwCaptureCount + 1;
                      v1->dwCaptureCount = v25;
                      if ( v25 < 0x2000 )
                      {
                        *D3DK::g_pDevice->m_pShaderCapturePtr = v18[36] | (v18[35] << 16);
                        ++D3DK::g_pDevice->m_pShaderCapturePtr;
                        v26 = v1->dwCaptureCount + 1;
                        v1->dwCaptureCount = v26;
                        if ( v26 < 0x2000 )
                        {
                          *D3DK::g_pDevice->m_pShaderCapturePtr = v18[38] | (v18[37] << 16);
                          ++D3DK::g_pDevice->m_pShaderCapturePtr;
                          v27 = v1->dwCaptureCount + 1;
                          v1->dwCaptureCount = v27;
                          if ( v27 < 0x2000 )
                          {
                            *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 72) | (*(v18 - 73) << 16);
                            ++D3DK::g_pDevice->m_pShaderCapturePtr;
                            v28 = v1->dwCaptureCount + 1;
                            v1->dwCaptureCount = v28;
                            if ( v28 < 0x2000 )
                            {
                              *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 70) | (*(v18 - 71) << 16);
                              ++D3DK::g_pDevice->m_pShaderCapturePtr;
                              v29 = v1->dwCaptureCount + 1;
                              v1->dwCaptureCount = v29;
                              if ( v29 < 0x2000 )
                              {
                                *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 36) | (*(v18 - 37) << 16);
                                ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                v30 = v1->dwCaptureCount + 1;
                                v1->dwCaptureCount = v30;
                                if ( v30 < 0x2000 )
                                {
                                  *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 34) | (*(v18 - 35) << 16);
                                  ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                  v31 = v1->dwCaptureCount + 1;
                                  v1->dwCaptureCount = v31;
                                  if ( v31 < 0x2000 )
                                  {
                                    *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 288) | (*(v18 - 289) << 16);
                                    ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                    v32 = v1->dwCaptureCount + 1;
                                    v1->dwCaptureCount = v32;
                                    if ( v32 < 0x2000 )
                                    {
                                      *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 286) | (*(v18 - 287) << 16);
                                      ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                      v33 = v1->dwCaptureCount + 1;
                                      v1->dwCaptureCount = v33;
                                      if ( v33 < 0x2000 )
                                      {
                                        *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 252) | (*(v18 - 253) << 16);
                                        ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                        v34 = v1->dwCaptureCount + 1;
                                        v1->dwCaptureCount = v34;
                                        if ( v34 < 0x2000 )
                                        {
                                          *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 250) | (*(v18 - 251) << 16);
                                          ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                          v35 = v1->dwCaptureCount + 1;
                                          v1->dwCaptureCount = v35;
                                          if ( v35 < 0x2000 )
                                          {
                                            *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 216) | (*(v18 - 217) << 16);
                                            ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                            v36 = v1->dwCaptureCount + 1;
                                            v1->dwCaptureCount = v36;
                                            if ( v36 < 0x2000 )
                                            {
                                              *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 214) | (*(v18 - 215) << 16);
                                              ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                              v37 = v1->dwCaptureCount + 1;
                                              v1->dwCaptureCount = v37;
                                              if ( v37 < 0x2000 )
                                              {
                                                *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 180) | (*(v18 - 181) << 16);
                                                ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                                v38 = v1->dwCaptureCount + 1;
                                                v1->dwCaptureCount = v38;
                                                if ( v38 < 0x2000 )
                                                {
                                                  *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 178) | (*(v18 - 179) << 16);
                                                  ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                                  v39 = v1->dwCaptureCount + 1;
                                                  v1->dwCaptureCount = v39;
                                                  if ( v39 < 0x2000 )
                                                  {
                                                    *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 144) | (*(v18 - 145) << 16);
                                                    ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                                    v40 = v1->dwCaptureCount + 1;
                                                    v1->dwCaptureCount = v40;
                                                    if ( v40 < 0x2000 )
                                                    {
                                                      *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 142) | (*(v18 - 143) << 16);
                                                      ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                                      v41 = v1->dwCaptureCount + 1;
                                                      v1->dwCaptureCount = v41;
                                                      if ( v41 < 0x2000 )
                                                      {
                                                        *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 108) | (*(v18 - 109) << 16);
                                                        ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                                        v42 = v1->dwCaptureCount + 1;
                                                        v1->dwCaptureCount = v42;
                                                        if ( v42 < 0x2000 )
                                                        {
                                                          *D3DK::g_pDevice->m_pShaderCapturePtr = *(v18 - 106) | (*(v18 - 107) << 16);
                                                          ++D3DK::g_pDevice->m_pShaderCapturePtr;
                                                          ++v1->dwCaptureCount;
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        v43 = v1->cpt.dwCombinerCount;
        v17 = i + 1;
        v18 += 4;
        ++i;
      }
      while ( i < v43 );
    }
    if ( v1->dwCaptureCount >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = 83886103;
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v44 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v44;
    if ( v44 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = 0;
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v45 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v45;
    if ( v45 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = 0;
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v46 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v46;
    if ( v46 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.r0[8].r | (v1->cpt.r0[8].a << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v47 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v47;
    if ( v47 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.r0[8].b | (v1->cpt.r0[8].g << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v48 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v48;
    if ( v48 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.r1[8].r | (v1->cpt.r1[8].a << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v49 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v49;
    if ( v49 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.r1[8].b | (v1->cpt.r1[8].g << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v50 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v50;
    if ( v50 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.c0[8].r | (v1->cpt.c0[8].a << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v51 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v51;
    if ( v51 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.c0[8].b | (v1->cpt.c0[8].g << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v52 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v52;
    if ( v52 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.c1[8].r | (v1->cpt.c1[8].a << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v53 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v53;
    if ( v53 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.c1[8].b | (v1->cpt.c1[8].g << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v54 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v54;
    if ( v54 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.v0[8].r | (v1->cpt.v0[8].a << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v55 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v55;
    if ( v55 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.v0[8].b | (v1->cpt.v0[8].g << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v56 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v56;
    if ( v56 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.v1[8].r | (v1->cpt.v1[8].a << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v57 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v57;
    if ( v57 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.v1[8].b | (v1->cpt.v1[8].g << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v58 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v58;
    if ( v58 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.t0[8].r | (v1->cpt.t0[8].a << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v59 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v59;
    if ( v59 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.t0[8].b | (v1->cpt.t0[8].g << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v60 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v60;
    if ( v60 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.t1[8].r | (v1->cpt.t1[8].a << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v61 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v61;
    if ( v61 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.t1[8].b | (v1->cpt.t1[8].g << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v62 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v62;
    if ( v62 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.t2[8].r | (v1->cpt.t2[8].a << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v63 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v63;
    if ( v63 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.t2[8].b | (v1->cpt.t2[8].g << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v64 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v64;
    if ( v64 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.t3[8].r | (v1->cpt.t3[8].a << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v65 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v65;
    if ( v65 >= 0x2000 )
      return 0;
    v10 = D3DK::g_pDevice;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.t3[8].b | (v1->cpt.t3[8].g << 16);
  }
  else
  {
    D3DK::DebugSnapshot::RestoreUserState(v1);
    D3DK::DebugSnapshot::SetColorAndDepth(v1, v3, *v3, *v2);
    D3DK::DebugSnapshot::DrawVertices(v1);
    D3DK::DebugSnapshot::GetColorAndDepth(v1, v3, &v1->cpt.dwPostColor, &v1->cpt.dwPostDepth);
    if ( v1->dwCaptureCount >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = 50331653;
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v5 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v5;
    if ( v5 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = *v3;
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v6 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v6;
    if ( v6 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = *v2;
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v7 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v7;
    if ( v7 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.dwPostColor;
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v8 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v8;
    if ( v8 >= 0x2000 )
      return 0;
    *D3DK::g_pDevice->m_pShaderCapturePtr = v1->cpt.dwPostDepth;
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v9 = v1->dwCaptureCount + 1;
    v1->dwCaptureCount = v9;
    if ( v9 >= 0x2000 )
      return 0;
    v10 = D3DK::g_pDevice;
    *D3DK::g_pDevice->m_pShaderCapturePtr = 117440513;
  }
  ++v10->m_pShaderCapturePtr;
  ++v1->dwCaptureCount;
  return 0;
}
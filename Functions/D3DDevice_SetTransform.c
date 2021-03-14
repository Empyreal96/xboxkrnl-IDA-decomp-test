// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetTransform(_D3DTRANSFORMSTATETYPE State, _D3DMATRIX *pMatrix)
{
  int *v2; // eax
  _D3DMATRIX *v3; // edx
  int *v4; // edi
  double v5; // st7
  unsigned int v6; // eax
  D3DK::CDevice *v7; // eax
  int savedregs; // [esp+Ch] [ebp+0h]

  ++D3DK::g_PerfCounters.m_APICounters[171];
  if ( (unsigned int)State >= 0xA )
    D3DK::DXGRIP((int *)State, "Invalid state value passed to SetTransform");
  if ( !pMatrix )
    D3DK::DXGRIP((int *)State, "Invalid pointer");
  if ( (unsigned int)State < 6 || (unsigned int)State > 9 )
  {
    if ( State )
    {
      if ( State == 1 )
      {
        ++D3DK::g_PerfCounters.m_PerformanceCounters[3].Count;
        if ( D3DK::g_PerfCounters.m_Breakperfctr == 3
          && D3DK::g_PerfCounters.m_PerformanceCounters[3].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
        {
          __debugbreak();
        }
      }
      else if ( (unsigned int)State >= 2 && (unsigned int)State <= 5 )
      {
        ++D3DK::g_PerfCounters.m_PerformanceCounters[4].Count;
        if ( D3DK::g_PerfCounters.m_Breakperfctr == 4
          && D3DK::g_PerfCounters.m_PerformanceCounters[4].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
        {
          __debugbreak();
        }
      }
    }
    else
    {
      ++D3DK::g_PerfCounters.m_PerformanceCounters[2].Count;
      if ( D3DK::g_PerfCounters.m_Breakperfctr == 2
        && D3DK::g_PerfCounters.m_PerformanceCounters[2].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
      {
        __debugbreak();
      }
    }
  }
  else
  {
    ++D3DK::g_PerfCounters.m_PerformanceCounters[1].Count;
    if ( D3DK::g_PerfCounters.m_Breakperfctr == 1
      && D3DK::g_PerfCounters.m_PerformanceCounters[1].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
    {
      __debugbreak();
    }
  }
  v2 = (int *)((char *)D3DK::g_pDevice + 64 * (State + 34));
  if ( !memcmp(pMatrix, v2, 0x40u) )
  {
    ++D3DK::g_PerfCounters.m_PerformanceCounters[19].Count;
    if ( D3DK::g_PerfCounters.m_Breakperfctr == 19
      && D3DK::g_PerfCounters.m_PerformanceCounters[19].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
    {
      __debugbreak();
    }
  }
  v3 = pMatrix;
  qmemcpy(v2, pMatrix, 0x40u);
  v4 = v2 + 16;
  D3DK::g_pDevice->m_DirtyFlags |= *(_DWORD *)(4 * State - 2146982200);
  if ( State == 1 )
  {
    if ( pMatrix->_33 == pMatrix->_34 || pMatrix->_33 == 0.0 )
    {
      D3DK::WARNING(v4, "Cannot compute WNear and WFar from the supplied projection matrix");
      D3DK::WARNING(v4, "Setting wNear to 0.0 and wFar to 1.0");
      v3 = pMatrix;
      D3DK::g_pDevice->m_WNear = 0.0;
      D3DK::g_pDevice->m_WFar = 1.0;
    }
    else
    {
      D3DK::g_pDevice->m_WNear = pMatrix->_44 - pMatrix->_43 / pMatrix->_33 * pMatrix->_34;
      D3DK::g_pDevice->m_WFar = (pMatrix->_44 - pMatrix->_43) / (pMatrix->_33 - pMatrix->_34) * pMatrix->_34
                              + pMatrix->_44;
    }
    v5 = 1.0 / D3DK::g_pDevice->m_WFar;
    v6 = D3DK::g_pDevice->m_StateFlags & 0xFFFFFFFD;
    D3DK::g_pDevice->m_StateFlags = v6;
    D3DK::g_pDevice->m_InverseWFar = v5;
    if ( v3->_14 == 0.0 && v3->_24 == 0.0 && v3->_34 == 0.0 && LODWORD(v3->_44) == 1065353216 )
      D3DK::g_pDevice->m_StateFlags = v6 | 2;
    D3DK::UpdateProjectionViewportTransform(COERCE_FLOAT(&savedregs));
    D3DK::CommonSetPassthroughProgram(v7, (int *)D3DK::g_pDevice);
  }
}
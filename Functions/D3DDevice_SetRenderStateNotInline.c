// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetRenderStateNotInline(_D3DRENDERSTATETYPE State, unsigned int Value)
{
  int *v2; // edi
  signed int v3; // eax

  if ( *(_DWORD *)(8 * State - 2146703836) )
    v2 = *(int **)(8 * State - 2146703832);
  else
    v2 = (int *)Value;
  if ( !D3DDevice_SetRenderState_ParameterCheck(v2, State, (unsigned int)v2) )
  {
    v3 = *(_DWORD *)(4 * State - 2146688056);
    ++D3DK::g_PerfCounters.m_APICounters[157];
    ++*(_DWORD *)(4 * State - 2146701260);
    if ( v2 == (int *)v3 )
    {
      v3 = D3DK::g_PerfCounters.m_Breakperfctr;
      ++D3DK::g_PerfCounters.m_PerformanceCounters[16].Count;
      if ( D3DK::g_PerfCounters.m_Breakperfctr == 16 )
      {
        v3 = D3DK::g_PerfCounters.m_PerformanceCounters[16].Count + 1;
        if ( D3DK::g_PerfCounters.m_PerformanceCounters[16].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
          __debugbreak();
      }
    }
    if ( (signed int)State >= 82 )
    {
      if ( (signed int)State >= 116 )
        (*(void (__stdcall **)(int *))(4 * State - 2146985648))(v2);
      else
        D3DDevice_SetRenderState_Deferred((_D3DRENDERSTATETYPE)v3, State, v2);
    }
    else
    {
      D3DDevice_SetRenderState_Simple(v3, *(_DWORD *)(4 * State - 2146428848), (unsigned int)v2, v2);
      *(_DWORD *)(4 * State - 2146688056) = v2;
    }
  }
}
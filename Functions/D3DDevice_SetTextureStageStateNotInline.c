// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetTextureStageStateNotInline(unsigned int Stage, _D3DTEXTURESTAGESTATETYPE Type, unsigned int Value)
{
  unsigned int *v3; // eax
  int v4; // ecx

  ++D3DK::g_PerfCounters.m_APICounters[163];
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)Value, Stage, Type, Value) )
  {
    ++*(_DWORD *)(4 * Type - 2146700684);
    v3 = (unsigned int *)(4 * (Type + 32 * Stage) - 2146688568);
    if ( Value == *v3 )
    {
      ++D3DK::g_PerfCounters.m_PerformanceCounters[17].Count;
      if ( D3DK::g_PerfCounters.m_Breakperfctr == 17
        && D3DK::g_PerfCounters.m_PerformanceCounters[17].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
      {
        __debugbreak();
      }
    }
    if ( (signed int)Type >= 22 )
    {
      switch ( Type )
      {
        case 28:
          D3DDevice_SetTextureState_TexCoordIndex(Stage, Value);
          break;
        case 29:
          D3DDevice_SetTextureState_BorderColor(Stage, Value);
          break;
        case 30:
          D3DDevice_SetTextureState_ColorKeyColor(Stage, Value);
          break;
        default:
          if ( (signed int)Type <= 27 )
            D3DDevice_SetTextureState_BumpEnv((int *)Value, Stage, Type, Value);
          break;
      }
    }
    else
    {
      v4 = *(_DWORD *)(4 * Type - 2146914056);
      *v3 = Value;
      D3DK::g_pDevice->m_DirtyFlags |= v4;
    }
  }
}
unsigned int __usercall D3DPERF_DumpPerfProfCounts@<eax>(int *a1@<edi>)
{
  int *v1; // edi
  unsigned int *v2; // esi
  int *v4; // [esp-8h] [ebp-8h]

  if ( D3DK::g_PerfCounters.m_ProfileSamples )
  {
    v4 = a1;
    v1 = (int *)&g_GpuStates[0].Name;
    v2 = D3DK::g_PerfCounters.m_ProfileBusyCounts;
    do
    {
      DbgPrint(v1, "%20s: %Lu (%Lu%%)\n", *v1, *v2, 100 * *v2 / D3DK::g_PerfCounters.m_ProfileSamples);
      ++v2;
      v1 += 2;
    }
    while ( (signed int)v2 < (signed int)D3DK::g_PerfCounters.m_RenderStateOverrides );
    a1 = v4;
  }
  return DbgPrint(a1, "%20s: %Lu\n", "total samples", D3DK::g_PerfCounters.m_ProfileSamples);
}
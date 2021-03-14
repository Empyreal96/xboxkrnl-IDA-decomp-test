// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_GetScissors(unsigned int *pCount, int *pExclusive, _D3DRECT *pRects)
{
  ++D3DK::g_PerfCounters.m_APICounters[78];
  if ( pCount )
    *pCount = D3DK::g_pDevice->m_ScissorsCount;
  if ( pExclusive )
    *pExclusive = D3DK::g_pDevice->m_ScissorsExclusive;
  if ( pRects )
    qmemcpy(pRects, D3DK::g_pDevice->m_ScissorsRects, 16 * D3DK::g_pDevice->m_ScissorsCount);
}
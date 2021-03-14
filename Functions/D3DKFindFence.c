D3DK::Fence *__userpurge D3DK::FindFence@<eax>(int *a1@<edi>, unsigned int TargetTime)
{
  unsigned int v2; // ebx
  unsigned int v3; // ecx
  unsigned int v4; // edx
  int *v5; // edi
  unsigned int v6; // eax

  v2 = TargetTime;
  if ( !(TargetTime & 1) )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "TargetTime & PUSHER_TIME_VALID_FLAG");
  if ( TargetTime == D3DK::g_pDevice->m_CpuTime )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "TargetTime != pDevice->m_CpuTime");
  v3 = D3DK::g_pDevice->m_CpuTime;
  v4 = D3DK::g_pDevice->m_CpuTime - TargetTime;
  if ( v4 > 0x80 )
  {
    v6 = D3DK::g_pDevice->m_PusherLastSegment;
    if ( v3 - *((_DWORD *)&D3DK::g_pDevice->m_Pusher.m_pPut + 3 * v6 + 9) <= v4 )
    {
      do
        v6 = ((_BYTE)v6 + 1) & 0xF;
      while ( v3 - *((_DWORD *)&D3DK::g_pDevice->m_Pusher.m_pPut + 3 * v6 + 9) > v4 );
      v5 = (int *)(&D3DK::g_pDevice->m_Pusher.m_pPut + 3 * v6 + 9);
    }
    else
    {
      v5 = (int *)((char *)D3DK::g_pDevice + 12 * (((v3 >> 1) & 0x3F) + 19));
    }
    v2 = TargetTime;
  }
  else
  {
    v5 = (int *)((char *)D3DK::g_pDevice + 12 * (((TargetTime >> 1) & 0x3F) + 19));
  }
  if ( !v5[1] )
    D3DK::DXGRIP(v5, "Assertion failure: %s", "pFence->pEncoding != NULL");
  if ( !(*(_BYTE *)v5 & 1) )
    D3DK::DXGRIP(v5, "Assertion failure: %s", "pFence->Time & PUSHER_TIME_VALID_FLAG");
  if ( D3DK::g_pDevice->m_CpuTime - *v5 > D3DK::g_pDevice->m_CpuTime - v2 )
    D3DK::DXGRIP(v5, "Assertion failure: %s", "pDevice->Age(pFence->Time) <= pDevice->Age(TargetTime)");
  return (D3DK::Fence *)v5;
}
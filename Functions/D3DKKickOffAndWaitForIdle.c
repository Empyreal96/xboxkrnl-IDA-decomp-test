void __usercall D3DK::KickOffAndWaitForIdle(int *a1@<edi>)
{
  D3DK::BlockOnTime(D3DK::g_pDevice->m_CpuTime, 0);
  if ( D3DK::g_pDevice->m_Miniport.m_PusherGetRunSize != D3DK::g_pDevice->m_PusherPutRunSize )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "pDevice->m_Miniport.m_PusherGetRunSize == pDevice->m_PusherPutRunSize");
}
// write access to const memory has been detected, the output may be wrong!
unsigned int __usercall D3DDevice_End@<eax>(int *a1@<edi>)
{
  int *v1; // edi
  unsigned int v2; // eax
  int *v3; // edi
  unsigned int v4; // eax
  unsigned int result; // eax
  int *v6; // [esp-4h] [ebp-8h]

  ++D3DK::g_PerfCounters.m_APICounters[48];
  if ( !D3DK::g_CurrentPrimitiveType )
    D3DK::DXGRIP(a1, "D3DDevice_End - End without a matching begin.");
  v6 = a1;
  D3DK::g_CurrentPrimitiveType = 0;
  v1 = (int *)XMETAL_StartPush(a1, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f(v1, (unsigned int *)v1, 0x17FCu, 0.0);
  XMETAL_EndPush(v1 + 2, &D3DK::g_pDevice->m_Pusher, (unsigned int *)v1 + 2);
  v2 = (char *)D3DK::g_pDevice->m_Pusher.m_pPut - (char *)g_StartPut;
  v3 = v6;
  if ( (v2 & 0x80000000) != 0 )
    v2 += D3DK::g_pDevice->m_PusherLastSize;
  if ( v2 > D3DK::CDevice::m_PushBufferSize >> 1 )
    D3DK::WARNING(
      v6,
      "Vertex or index data for this call exceeded half of the push-buffer size.\n"
      "Reduce the call size or increase the push-buffer size with SetPushBufferSize.\n");
  v4 = D3DK::g_pDevice->m_StateFlags;
  if ( !(v4 & 0x800) )
    D3DK::DXGRIP(v3, "Assertion failure: %s", "m_StateFlags & STATE_BEGINENDBRACKET");
  result = D3DK::g_pDevice->m_StateFlags;
  if ( result & 0x1000 )
    result = D3DK::SetFence(1u);
  D3DK::g_pDevice->m_StateFlags &= 0xFFFFE7FF;
  return result;
}
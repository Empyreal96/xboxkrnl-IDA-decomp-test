// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetRenderState_Dxt1NoiseEnable(unsigned int Value)
{
  float v1; // ebx
  unsigned int *v2; // esi

  ++D3DK::g_PerfCounters.m_APICounters[130];
  v1 = 0.0;
  if ( (D3DK::g_TextureFormat[BYTE1(D3DK::g_pDevice->m_pRenderTarget->Format)] & 0x3C) == 32 )
    v1 = *(float *)&Value;
  if ( LODWORD(v1) & 0xFFFFFFFE )
    D3DK::DXGRIP(
      (int *)D3DK::g_pDevice,
      "Assertion failure: %s",
      "(STATE_DXTNOISEENABLE == TRUE) && ((noiseEnable & ~1) == 0)");
  if ( LODWORD(v1) != (D3DK::g_pDevice->m_StateFlags & 1) )
  {
    D3DK::g_pDevice->m_StateFlags ^= 1u;
    v2 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v2, 0x110u, 0.0);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v2 + 2, 0x1D8Cu, v1);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v2 + 4, 0x100u, COERCE_FLOAT(796));
    XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v2 + 6);
  }
  dword_800C25EC = Value;
}
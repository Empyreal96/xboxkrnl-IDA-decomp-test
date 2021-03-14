void D3DK::InitializeKelvin()
{
  unsigned int *v0; // esi
  unsigned int *v1; // esi

  v0 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  XMETAL_PushCount((int *)D3DK::g_pDevice, v0, 0x180u, 3u);
  v0[1] = 2;
  v0[2] = 3;
  v0[3] = 3;
  XMETAL_PushCount((int *)D3DK::g_pDevice, v0 + 4, 0x190u, 6u);
  v0[5] = 4;
  v0[6] = 9;
  v0[7] = 10;
  v0[8] = 3;
  v0[9] = 3;
  v0[10] = 8;
  XMETAL_PushCount((int *)D3DK::g_pDevice, v0 + 11, 0x1A8u, 1u);
  v0[12] = 12;
  XMETAL_Push1f((int *)D3DK::g_pDevice, v0 + 13, 0x1D6Cu, 0.0);
  XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v0 + 15);
  v1 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f((int *)D3DK::g_pDevice, v1, 0x9FCu, COERCE_FLOAT(1));
  XMETAL_Push4f((int *)D3DK::g_pDevice, v1 + 2, 0xA50u, 0.0, 0.0, 0.0, 1.0);
  XMETAL_Push1f((int *)D3DK::g_pDevice, v1 + 7, 0x16BCu, COERCE_FLOAT(1));
  XMETAL_Push1f((int *)D3DK::g_pDevice, v1 + 9, 0x1E78u, COERCE_FLOAT(2162688));
  XMETAL_Push1f((int *)D3DK::g_pDevice, v1 + 11, 0x1D80u, COERCE_FLOAT(1));
  XMETAL_Push1f((int *)D3DK::g_pDevice, v1 + 13, 0x1E68u, 3.4028237e38/*+Inf*/);
  XMETAL_Push1f((int *)D3DK::g_pDevice, v1 + 15, 0x1D78u, COERCE_FLOAT(1));
  XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v1 + 17);
  D3DDevice_SetShaderConstantMode((int *)D3DK::g_pDevice, 0);
}
void __stdcall D3DK::RestoreVertexShaders(const unsigned int *pProgram, unsigned int Dwords)
{
  char *v2; // edi
  unsigned int v3; // ecx
  unsigned int *v4; // edi
  int *v5; // edi

  memset(D3DK::g_LoadedVertexShaderSlot, 1u, 4 * (Dwords >> 4));
  v2 = &D3DK::g_LoadedVertexShaderSlot[4 * (Dwords >> 4)];
  v3 = (Dwords >> 2) & 3;
  memset(v2, 1, v3);
  v4 = XMETAL_StartPush((int *)&v2[v3], &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f((int *)v4, v4, 0x1E9Cu, 0.0);
  v5 = (int *)D3DK::ParseProgram(v4 + 2, pProgram, Dwords);
  D3DK::PushedRaw(v5, (unsigned int *)v5);
  XMETAL_EndPush(v5, &D3DK::g_pDevice->m_Pusher, (unsigned int *)v5);
}
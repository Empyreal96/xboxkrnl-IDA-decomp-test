// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetShaderConstantMode(int *a1@<edi>, unsigned int Mode)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // ebx
  int *v5; // edi
  unsigned int *v6; // ebx
  char *v7; // edi

  ++D3DK::g_PerfCounters.m_APICounters[160];
  v2 = D3DK::g_pDevice->m_StateFlags;
  if ( Mode & 0x10 )
    v3 = v2 | 0x200;
  else
    v3 = v2 & 0xFFFFFDFF;
  v4 = Mode & 0xFFFFFFEF;
  D3DK::g_pDevice->m_StateFlags = v3;
  if ( (Mode & 0xFFFFFFEF) > 2 )
    D3DK::DXGRIP(a1, "Invalid mode");
  if ( D3DK::g_pDevice->m_StateFlags & 0x20 && v4 )
    D3DK::DXGRIP(a1, "Can't set constant mode while recording a state block");
  D3DK::g_pDevice->m_ConstantMode = v4;
  if ( !v4 )
  {
    v5 = (int *)(D3DK::g_pDevice->m_DirtyFlags | 0x26);
    D3DK::g_pDevice->m_DirtyFlags = (unsigned int)v5;
    v6 = XMETAL_StartPush(v5, &D3DK::g_pDevice->m_Pusher);
    XMETAL_Push1f(v5, v6, 0x1EA4u, COERCE_FLOAT(60));
    XMETAL_PushCount(v5, v6 + 2, 0xB80u, 0xCu);
    v7 = (char *)(v6 + 3);
    v6 += 15;
    qmemcpy(v7, D3DK::g_FixedFunctionPipelineConstants, 0x30u);
    v7 += 48;
    D3DK::PushMatrixTransposed((int *)v7, v6, 0x840u, &D3DK::g_IdentityMatrix);
    D3DK::PushMatrixTransposed((int *)v7, v6 + 17, 0x880u, &D3DK::g_IdentityMatrix);
    D3DK::PushMatrixTransposed((int *)v7, v6 + 34, 0x8C0u, &D3DK::g_IdentityMatrix);
    D3DK::PushMatrixTransposed((int *)v7, v6 + 51, 0x900u, &D3DK::g_IdentityMatrix);
    XMETAL_Push4f((int *)v7, v6 + 68, 0x9D0u, 0.0, 0.0, 1.0, 0.0);
    XMETAL_EndPush((int *)v7, &D3DK::g_pDevice->m_Pusher, v6 + 73);
  }
}
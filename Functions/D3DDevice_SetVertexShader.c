// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetVertexShader(int *a1@<edi>, unsigned int Handle)
{
  unsigned int v2; // ebx
  D3DK::VertexShader *v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int *v6; // edi
  D3DK::CDevice *v7; // eax
  unsigned int *v8; // eax
  D3DK::CDevice *v9; // eax
  int *v10; // eax
  int *v11; // edi
  D3DK::CDevice *v12; // eax
  unsigned int *v13; // eax
  unsigned int previousFlags; // [esp+14h] [ebp+8h]

  v2 = Handle;
  ++D3DK::g_PerfCounters.m_APICounters[179];
  if ( Handle == D3DK::g_pDevice->m_VertexShaderHandle )
  {
    ++D3DK::g_PerfCounters.m_PerformanceCounters[18].Count;
    if ( D3DK::g_PerfCounters.m_Breakperfctr == 18
      && D3DK::g_PerfCounters.m_PerformanceCounters[18].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
    {
      __debugbreak();
    }
  }
  previousFlags = D3DK::g_pDevice->m_pVertexShader->Flags;
  if ( v2 & 1 )
  {
    v3 = (D3DK::VertexShader *)(v2 - 1);
    if ( *(_DWORD *)(v2 - 1) != 1450403940 )
      D3DK::DXGRIP((int *)v3, "Invalid vertex shader object (already deleted?)");
    if ( !(v3->Flags & 4) && D3DK::g_pDevice->m_ConstantMode == 1 )
      D3DK::DXGRIP((int *)v3, "Can't use fixed function pipeline if D3DSCM_192CONSTANTS is enabled");
  }
  else
  {
    D3DK::ValidateFVF(a1, v2);
    if ( D3DK::g_pDevice->m_ConstantMode == 1 && v2 && (v2 & 0xE) != 4 )
      D3DK::DXGRIP(a1, "Can't use fixed function pipeline if D3DSCM_192CONSTANTS is enabled");
    v3 = &D3DK::g_FvfVertexShader;
    D3DK::InitializeVertexShaderFromFvf(&D3DK::g_FvfVertexShader, v2);
  }
  v4 = D3DK::g_pDevice->m_DirtyFlags | 0x3A4;
  D3DK::g_pDevice->m_DirtyFlags = v4;
  if ( previousFlags != v3->Flags )
    D3DK::g_pDevice->m_DirtyFlags = v4 | 2;
  D3DK::g_pDevice->m_pVertexShader = v3;
  D3DK::g_pDevice->m_VertexShaderHandle = v2;
  v5 = v3->Flags;
  if ( v5 & 4 )
  {
    D3DDevice_LoadVertexShader((int *)v3, v2, 0);
    D3DDevice_SelectVertexShader(v2, 0);
  }
  else if ( v5 & 2 )
  {
    v6 = XMETAL_StartPush((int *)v3, &D3DK::g_pDevice->m_Pusher);
    XMETAL_Push1f((int *)v6, v6, 0x1EA0u, 0.0);
    XMETAL_Push2f((int *)v6, v6 + 2, 0x1E94u, COERCE_FLOAT(6), 0.0);
    v8 = D3DK::CommonSetViewport(v7, (unsigned int *)D3DK::g_pDevice, (int *)v6 + 5);
    XMETAL_EndPush((int *)v6, &D3DK::g_pDevice->m_Pusher, v8);
    D3DK::CommonSetPassthroughProgram(v9, (int *)D3DK::g_pDevice);
    *(_DWORD *)D3DK::g_LoadedVertexShaderSlot = 0;
    dword_800C210C = (unsigned __int8)D3DK::g_LoadedVertexShaderSlot[0];
    dword_800C2110 = (unsigned __int8)D3DK::g_LoadedVertexShaderSlot[0];
  }
  else
  {
    v10 = (int *)XMETAL_StartPush((int *)v3, &D3DK::g_pDevice->m_Pusher);
    v11 = v10;
    XMETAL_Push1f(v10, (unsigned int *)v10, 0x1E94u, COERCE_FLOAT(4));
    v13 = D3DK::CommonSetViewport(v12, (unsigned int *)D3DK::g_pDevice, v11 + 2);
    XMETAL_EndPush(v11, &D3DK::g_pDevice->m_Pusher, v13);
  }
}
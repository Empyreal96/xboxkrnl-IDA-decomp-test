// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SelectVertexShader(unsigned int Handle, unsigned int Address)
{
  int *v2; // edi
  D3DK::VertexShader *v3; // edi
  unsigned int v4; // eax
  unsigned int *v5; // eax
  unsigned int *v6; // ebx
  D3DK::CDevice *v7; // eax
  unsigned int *v8; // eax
  unsigned int *v9; // ebx

  v2 = (int *)Address;
  ++D3DK::g_PerfCounters.m_APICounters[114];
  if ( Address >= 0x88 )
    D3DK::DXGRIP((int *)Address, "Start address can't be larger than 135");
  if ( !D3DK::g_LoadedVertexShaderSlot[Address] )
    D3DK::DXGRIP((int *)Address, "Can't select a vertex state shader if it hasn't been loaded");
  if ( Handle )
  {
    v3 = (D3DK::VertexShader *)(Handle - 1);
    if ( !(Handle & 1) )
      D3DK::DXGRIP((int *)v3, "Must be a vertex shader program, not an FVF");
    if ( v3->Signature != 1450403940 )
      D3DK::DXGRIP((int *)v3, "Invalid vertex shader object (already deleted?)");
    if ( Address + v3->ProgramSize > 0x88 )
      D3DK::DXGRIP((int *)v3, "End address larger than 136");
    v4 = D3DK::g_pDevice->m_DirtyFlags | 0x3A0;
    D3DK::g_pDevice->m_pVertexShader = v3;
    D3DK::g_pDevice->m_VertexShaderHandle = Handle;
    D3DK::g_pDevice->m_DirtyFlags = v4;
    v5 = XMETAL_StartPush((int *)v3, &D3DK::g_pDevice->m_Pusher);
    v6 = v5;
    XMETAL_Push2f((int *)v3, v5, 0x1E94u, COERCE_FLOAT(6), COERCE_FLOAT(v3->Flags & 1));
    v8 = D3DK::CommonSetViewport(v7, (unsigned int *)D3DK::g_pDevice, (int *)v6 + 3);
    XMETAL_EndPush((int *)v3, &D3DK::g_pDevice->m_Pusher, v8);
    v2 = (int *)Address;
  }
  v9 = XMETAL_StartPush(v2, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f(v2, v9, 0x1EA0u, *(float *)&v2);
  XMETAL_EndPush(v2, &D3DK::g_pDevice->m_Pusher, v9 + 2);
}
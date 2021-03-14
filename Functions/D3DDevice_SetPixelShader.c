// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetPixelShader(unsigned int Handle)
{
  unsigned int v1; // ecx
  unsigned int v2; // edx
  unsigned int *v3; // eax
  unsigned int *v4; // esi
  int v5; // esi
  unsigned int *v6; // ebx
  unsigned int *v7; // ebx
  D3DK::PixelShader *pOldShader; // [esp+10h] [ebp-4h]

  ++D3DK::g_PerfCounters.m_APICounters[123];
  if ( Handle && *(_DWORD *)Handle != 1349740644 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid pixel shader object (already deleted?)");
  pOldShader = D3DK::g_pDevice->m_pPixelShader;
  D3DK::g_pDevice->m_pPixelShader = (D3DK::PixelShader *)Handle;
  if ( Handle )
  {
    D3DK::g_pDevice->m_ShaderUsesSpecFog = *(_DWORD *)(*(_DWORD *)(Handle + 12) + 32) | *(_DWORD *)(*(_DWORD *)(Handle + 12)
                                                                                                  + 36);
    D3DK::g_pDevice->m_ShaderAdjustsTexMode = *(_DWORD *)(*(_DWORD *)(Handle + 12) + 236) & 0x100;
    v5 = *(_DWORD *)(Handle + 12);
    D3DK::g_pDevice->m_PSShaderStageProgram = *(_DWORD *)(v5 + 216);
    D3DK::g_pDevice->m_DirtyFlags |= 0x400u;
    v6 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
    if ( !pOldShader )
      v6 = D3DK::CommonSetTextureBumpEnv(0, (unsigned int *)D3DK::g_pDevice, v6);
    XMETAL_PushCount((int *)D3DK::g_pDevice, v6, 0x260u, 8u);
    qmemcpy(v6 + 1, (const void *)v5, 0x20u);
    XMETAL_PushCount((int *)v6 + 9, v6 + 9, 0xA60u, 0x20u);
    qmemcpy(v6 + 10, (const void *)(v5 + 40), 0x80u);
    XMETAL_Push1f((int *)v6 + 42, v6 + 42, 0x17F8u, *(float *)(v5 + 168));
    XMETAL_PushCount((int *)v6 + 42, v6 + 44, 0x1E20u, 2u);
    v6[45] = *(_DWORD *)(v5 + 172);
    v6[46] = *(_DWORD *)(v5 + 176);
    XMETAL_PushCount((int *)v6 + 42, v6 + 47, 0x1E40u, 9u);
    qmemcpy(v6 + 48, (const void *)(v5 + 180), 0x24u);
    XMETAL_PushCount((int *)v6 + 57, v6 + 57, 0x1E74u, 2u);
    v6[58] = *(_DWORD *)(v5 + 220);
    v6[59] = *(_DWORD *)(v5 + 224);
    if ( D3DK::g_pDevice->m_ShaderUsesSpecFog )
    {
      XMETAL_PushCount((int *)D3DK::g_pDevice, v6 + 60, 0x288u, 2u);
      v6[61] = *(_DWORD *)(v5 + 32);
      v6[62] = *(_DWORD *)(v5 + 36);
      v7 = v6 + 63;
    }
    else
    {
      v7 = v6 + 60;
    }
    XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v7);
    if ( !(D3DK::g_pDevice->m_StateFlags & 0x10) )
    {
      qmemcpy(D3D__RenderState, (const void *)v5, 0xE4u);
      dword_800C2598 = *(_DWORD *)(v5 + 216);
    }
  }
  else
  {
    v1 = D3DK::g_pDevice->m_ShaderUsesSpecFog;
    v2 = D3DK::g_pDevice->m_DirtyFlags | 0x408;
    D3DK::g_pDevice->m_DirtyFlags = v2;
    if ( v1 )
      D3DK::g_pDevice->m_DirtyFlags = v2 | 0x40;
    D3DDevice_SetRenderState_TextureFactor((int *)D3DK::g_pDevice, 0);
    v3 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
    v4 = D3DK::CommonSetTextureBumpEnv((D3DK::CDevice *)v3, (unsigned int *)D3DK::g_pDevice, v3);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v4, 0x1E78u, COERCE_FLOAT(2162688));
    XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v4 + 2);
  }
}
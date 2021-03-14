// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetViewport(_D3DVIEWPORT8 *pViewport)
{
  _D3DVIEWPORT8 *v1; // edi
  D3DSurface *v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ebx
  unsigned int v5; // edx
  unsigned int v6; // ebx
  signed int v7; // eax
  unsigned int *v8; // eax
  unsigned int *v9; // eax
  unsigned int top; // [esp+Ch] [ebp-Ch]
  unsigned int left; // [esp+10h] [ebp-8h]
  unsigned int v12; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h]
  D3DSurface *pSurface; // [esp+20h] [ebp+8h]

  v1 = pViewport;
  ++D3DK::g_PerfCounters.m_APICounters[183];
  if ( !pViewport )
    D3DK::DXGRIP((int *)pViewport, "Invalid viewport pointer");
  if ( D3DK::g_pDevice->m_pRenderTarget == D3DK::g_pDevice->m_FrameBufferSurfaces )
  {
    v2 = &D3DK::g_pDevice->m_FrameBufferSurfaces[1];
    pSurface = &D3DK::g_pDevice->m_FrameBufferSurfaces[1];
  }
  else
  {
    pSurface = D3DK::g_pDevice->m_pRenderTarget;
    v2 = D3DK::g_pDevice->m_pRenderTarget;
  }
  left = v1->X > 0 ? v1->X : 0;
  v3 = v2->Size;
  top = v1->Y > 0 ? v1->Y : 0;
  if ( v3 )
    v4 = (v2->Size & 0xFFF) + 1;
  else
    v4 = 1 << ((v2->Format >> 20) & 0xF);
  v5 = v1->Width + v1->X;
  if ( v5 >= v4 )
  {
    if ( v3 )
      v5 = (v3 & 0xFFF) + 1;
    else
      v5 = 1 << ((pSurface->Format >> 20) & 0xF);
  }
  if ( v3 )
    v12 = ((v3 >> 12) & 0xFFF) + 1;
  else
    v12 = 1 << (HIBYTE(pSurface->Format) & 0xF);
  v6 = v1->Height;
  if ( v6 + v1->Y >= v12 )
  {
    if ( v3 )
      v7 = ((v3 >> 12) & 0xFFF) + 1;
    else
      v7 = 1 << (HIBYTE(pSurface->Format) & 0xF);
  }
  else
  {
    v7 = v6 + v1->Y;
  }
  D3DK::g_pDevice->m_Viewport.X = left;
  D3DK::g_pDevice->m_Viewport.Y = top;
  D3DK::g_pDevice->m_Viewport.Width = v5 - left;
  D3DK::g_pDevice->m_Viewport.Height = v7 - top;
  D3DK::g_pDevice->m_Viewport.MinZ = v1->MinZ;
  D3DK::g_pDevice->m_Viewport.MaxZ = v1->MaxZ;
  D3DK::UpdateProjectionViewportTransform(COERCE_FLOAT(&savedregs));
  D3DDevice_SetScissors(0, 0, 0);
  v8 = XMETAL_StartPush((int *)v1, &D3DK::g_pDevice->m_Pusher);
  v9 = D3DK::CommonSetViewport((D3DK::CDevice *)v8, (unsigned int *)D3DK::g_pDevice, (int *)v8);
  XMETAL_EndPush((int *)v1, &D3DK::g_pDevice->m_Pusher, v9);
  D3DK::g_pDevice->m_DirtyFlags |= 1u;
}
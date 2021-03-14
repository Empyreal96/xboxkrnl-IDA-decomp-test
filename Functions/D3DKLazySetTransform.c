// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DK::LazySetTransform(int a1@<ebp>, D3DK::CDevice *pDevice)
{
  signed int v2; // eax
  unsigned int *v3; // esi
  unsigned int *v4; // esi
  _D3DMATRIX inverseModelViewBlend; // [esp+0h] [ebp-150h]
  _D3DMATRIX inverseModelView; // [esp+40h] [ebp-110h]
  _D3DMATRIX modelViewBlend; // [esp+C0h] [ebp-90h]
  int v16; // [esp+144h] [ebp-Ch]
  int v17; // [esp+148h] [ebp-8h]
  int retaddr; // [esp+150h] [ebp+0h]

  v16 = a1;
  v17 = retaddr;
  ++D3DK::g_PerfCounters.m_PerformanceCounters[29].Count;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == 29
    && D3DK::g_PerfCounters.m_PerformanceCounters[29].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  v2 = pDevice->m_DirtyFlags & 0xFFFFFFFD;
  pDevice->m_DirtyFlags = v2;
  if ( v2 >= 0 && !(pDevice->m_pVertexShader->Flags & 6) )
  {
    v3 = XMETAL_StartPush((int *)pDevice, &pDevice->m_Pusher);
    D3DK::MatrixProduct4x4((_D3DMATRIX *)((char *)&modelViewBlend + 52), &pDevice->m_Transform[6], pDevice->m_Transform);
    D3DK::PushMatrixTransposed((int *)pDevice, v3, 0x480u, (_D3DMATRIX *)((char *)&modelViewBlend + 52));
    v4 = v3 + 17;
    if ( pDevice->m_TexGenInverseNeeded )
    {
      D3DK::Inverse4x4(
        (_D3DMATRIX *)((char *)&inverseModelViewBlend + 52),
        (_D3DMATRIX *)((char *)&modelViewBlend + 52),
        1);
      D3DK::PushInverseModelViewMatrix((int *)pDevice, v4, 0x580u, (_D3DMATRIX *)((char *)&inverseModelViewBlend + 52));
      v4 += 13;
    }
    D3DK::MatrixProduct4x4(
      (_D3DMATRIX *)((char *)&inverseModelView + 52),
      (_D3DMATRIX *)((char *)&modelViewBlend + 52),
      &pDevice->m_ProjectionViewportTransform);
    D3DK::PushMatrixTransposed((int *)pDevice, v4, 0x680u, (_D3DMATRIX *)((char *)&inverseModelView + 52));
    XMETAL_EndPush((int *)pDevice, &pDevice->m_Pusher, v4 + 17);
  }
}
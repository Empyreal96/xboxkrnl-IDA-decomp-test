void __usercall D3DK::UpdateProjectionViewportTransform(float a1@<ebp>)
{
  double v1; // st7
  double v2; // st6
  float v3; // [esp-Ch] [ebp-6Ch]
  _D3DMATRIX viewportTransform; // [esp+0h] [ebp-60h]
  float v5; // [esp+40h] [ebp-20h]
  float v6; // [esp+44h] [ebp-1Ch]
  float v7; // [esp+48h] [ebp-18h]
  float fm43; // [esp+4Ch] [ebp-14h]
  float fm42; // [esp+50h] [ebp-10h]
  float fm41; // [esp+54h] [ebp-Ch]
  float fm33; // [esp+58h] [ebp-8h]
  float retaddr; // [esp+60h] [ebp+0h]

  fm41 = a1;
  fm33 = retaddr;
  v1 = (double)D3DK::g_pDevice->m_Viewport.Width * D3DK::g_pDevice->m_SuperSampleScaleX * 0.5;
  v7 = v1;
  v2 = (double)D3DK::g_pDevice->m_Viewport.Height * D3DK::g_pDevice->m_SuperSampleScaleY * -0.5;
  fm42 = v2;
  v6 = -v2;
  fm43 = (D3DK::g_pDevice->m_Viewport.MaxZ - D3DK::g_pDevice->m_Viewport.MinZ) * D3DK::g_pDevice->m_ZScale;
  v5 = D3DK::g_pDevice->m_ZScale * D3DK::g_pDevice->m_Viewport.MinZ;
  memset(&v3, 0, 0x40u);
  v3 = v1;
  viewportTransform._13 = fm42;
  viewportTransform._41 = 1.0;
  viewportTransform._24 = fm43;
  *(_QWORD *)&viewportTransform.m[2][1] = __PAIR__(LODWORD(v6), LODWORD(v7));
  viewportTransform._34 = v5;
  D3DK::MatrixProduct4x4(
    &D3DK::g_pDevice->m_ProjectionViewportTransform,
    &D3DK::g_pDevice->m_Transform[1],
    (_D3DMATRIX *)&v3);
  D3DK::g_pDevice->m_DirtyFlags |= 2u;
}
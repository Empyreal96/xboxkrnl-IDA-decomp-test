void __usercall D3DK::InitializeD3dState(int *a1@<edi>)
{
  _D3DTRANSFORMSTATETYPE v1; // esi
  _D3DRENDERSTATETYPE v2; // edi
  unsigned int *v3; // ebx
  unsigned int v4; // esi
  unsigned int v5; // edi
  _D3DTEXTURESTAGESTATETYPE v6; // esi

  D3DK::VerifyHeaderFileEncodings(a1);
  v1 = 0;
  do
    D3DDevice_SetTransform(v1++, &D3DK::g_IdentityMatrix);
  while ( (unsigned int)v1 < 0xA );
  v2 = 57;
  v3 = (unsigned int *)D3DK::g_InitialRenderStates;
  v4 = 0;
  do
  {
    if ( v4 != 308 )
      D3DDevice_SetRenderStateNotInline(v2, *v3);
    v4 += 4;
    ++v2;
    ++v3;
  }
  while ( v4 < 0x15C );
  D3DDevice_SetRenderStateNotInline(D3DRS_ZENABLE, D3DK::g_pDevice->m_pAutoDepthBuffer != 0);
  v5 = 0;
  do
  {
    v6 = 0;
    do
    {
      D3DDevice_SetTextureStageStateNotInline(v5, v6, (unsigned __int8)D3DK::g_InitialTextureStates[v6]);
      ++v6;
    }
    while ( (unsigned int)v6 < 0x20 );
    D3DDevice_SetTextureStageStateNotInline(v5, D3DTSS_TEXCOORDINDEX, v5);
    ++v5;
  }
  while ( v5 < 4 );
  D3DDevice_SetTextureStageStateNotInline(0, 0, 4u);
  D3DDevice_SetTextureStageStateNotInline(0, D3DTSS_ALPHAOP, 2u);
}
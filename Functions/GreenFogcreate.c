void __usercall GreenFog::create(GreenFog *this@<ecx>, int *a2@<edi>)
{
  GreenFog *v2; // esi
  int v3; // ecx
  GreenFogVertexBuffer *v4; // eax
  GreenFogVertexBuffer *v5; // eax
  GreenFogVertexBuffer *v6; // eax
  GreenFogVertexBuffer *v7; // eax
  signed int v8; // eax
  GreenFogVertexBuffer *v9; // ecx
  double v10; // st5
  BaseStream *v11; // eax
  BaseStream *v12; // eax
  BaseStream *v13; // eax
  BaseStream *v14; // eax
  unsigned int dwShaderVertexDecl[5]; // [esp+Ch] [ebp-1Ch]
  BaseStream *p_bs_verts; // [esp+20h] [ebp-8h]
  GreenFogVertexBuffer *p_verts; // [esp+24h] [ebp-4h]

  v2 = this;
  GreenFog::destroy(this, a2);
  D3DDevice_CreateTexture(0, (int)v2, 0x400u, 0x200u, 1u, 1u, D3DFMT_A8R8G8B8, 0, &v2->pIntensityTextureU);
  D3DDevice_CreateTexture(0, (int)v2, 0x400u, 0x200u, 1u, 1u, D3DFMT_A8R8G8B8, 0, &v2->pIntensityTextureR);
  D3DDevice_CreateDepthStencilSurface(0, 0x400u, 0x200u, D3DFMT_LIN_D24S8, 0x1021u, &v2->pIntensityZ);
  D3DDevice_CreateVertexBuffer(0, v3, (int)v2, 0x70u, 0, 0, 0, &v2->pQuadVB);
  D3DVertexBuffer_Lock(0, v2->pQuadVB, 0, 0, (char **)&p_verts, 0);
  v4 = p_verts;
  p_verts->pos.x = -1.0;
  v4->pos.y = -1.0;
  v4->pos.z = 1.0;
  v5 = p_verts + 1;
  v5->pos.x = -1.0;
  v5->pos.y = 1.0;
  v5->pos.z = 1.0;
  v6 = p_verts + 2;
  v6->pos.x = 1.0;
  v6->pos.y = 1.0;
  v6->pos.z = 1.0;
  v7 = p_verts + 3;
  v7->pos.x = 1.0;
  v7->pos.y = -1.0;
  v7->pos.z = 1.0;
  p_verts->tu0 = 0.0;
  p_verts->tv0 = 1.0;
  p_verts[1].tu0 = 0.0;
  p_verts[1].tv0 = 0.0;
  p_verts[2].tu0 = 1.0;
  p_verts[2].tv0 = 0.0;
  p_verts[3].tu0 = 1.0;
  p_verts[3].tv0 = 1.0;
  v8 = 0;
  do
  {
    p_verts[v8].tv1 = (p_verts[v8].tu0 * 2.0 - 1.0) * -2.5;
    v9 = &p_verts[v8];
    v10 = p_verts[v8].tv0;
    ++v8;
    v9->tu1 = (v10 * 2.0 - 1.0) * -1.875;
  }
  while ( v8 < 4 );
  D3DDevice_CreateVertexBuffer(0, (int)v9, (int)v2, 0x30u, 0, 0, 0, &v2->pIntensityQuadVB);
  D3DVertexBuffer_Lock(0, v2->pIntensityQuadVB, 0, 0, (char **)&p_bs_verts, 0);
  v11 = p_bs_verts;
  p_bs_verts->p.x = -1.0;
  v11->p.y = -1.0;
  v11->p.z = 1.0;
  v12 = p_bs_verts + 1;
  v12->p.x = -1.0;
  v12->p.y = 1.0;
  v12->p.z = 1.0;
  v13 = p_bs_verts + 2;
  v13->p.x = 1.0;
  v13->p.y = 1.0;
  v13->p.z = 1.0;
  v14 = p_bs_verts + 3;
  v14->p.x = 1.0;
  v14->p.y = -1.0;
  v14->p.z = 1.0;
  dwShaderVertexDecl[4] = -1;
  dwShaderVertexDecl[0] = 0x20000000;
  dwShaderVertexDecl[1] = 1077018624;
  dwShaderVertexDecl[2] = 1075970049;
  dwShaderVertexDecl[3] = 1075970050;
  v2->dwFogPShader = (unsigned int)XBoxStartupApp::loadPixelShader(&gApp, &gApp.nWidth, g_greenfog_xpu);
  v2->dwFogVShader = (unsigned int)XBoxStartupApp::loadVertexShader(g_greenfog_xvu, dwShaderVertexDecl);
  GreenFog::restart(v2);
}
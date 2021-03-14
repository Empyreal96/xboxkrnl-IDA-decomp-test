// write access to const memory has been detected, the output may be wrong!
void __usercall VBlob::create(VBlob *this@<ecx>, int *a2@<edi>)
{
  VBlob *v2; // esi
  int *v3; // edi
  int v4; // ecx
  int v5; // ecx
  unsigned int v6; // eax
  const char *v7; // eax
  unsigned int v8; // eax
  unsigned int dwBlobShaderVertexDecl[5]; // [esp+Ch] [ebp-20h]
  unsigned int dwBlobletShaderVertexDecl[3]; // [esp+20h] [ebp-Ch]

  v2 = this;
  gpVBlob = this;
  D3DDevice_CreateVertexBuffer(a2, (int)this, (int)this, 0x50u, 0, 0, 0, &this->pHaloQuadVB);
  VBlob::generateUnitSphere(
    8,
    &v2->m_pBlobletVB,
    &v2->m_pBlobletIB,
    0,
    &v2->m_dwNumBlobletVertices,
    &v2->m_dwNumBlobletIndices);
  v3 = (int *)&v2->m_dwNumVertices;
  VBlob::generateUnitSphere(
    32,
    &v2->m_pBlobVBConst,
    &v2->m_pBlobIB,
    &v2->m_pUnitSphereNormals,
    &v2->m_dwNumVertices,
    &v2->m_dwNumIndices);
  D3DDevice_CreateVertexBuffer(v3, v4, (int)v2, 16 * *v3, 0, 0, 0, &v2->m_pBlobVBChangingR);
  D3DDevice_CreateVertexBuffer(v3, v5, (int)v2, 16 * *v3, 0, 0, 0, &v2->m_pBlobVBChangingU);
  v2->m_NumVertsPerFace = v2->m_dwNumVertices / 6;
  VBlob::restart(v2);
  if ( v2->m_dwPShaderBlob )
  {
    D3DDevice_DeletePixelShader(v2->m_dwPShaderBlob);
    v2->m_dwPShaderBlob = 0;
  }
  v2->m_dwPShaderBlob = (unsigned int)XBoxStartupApp::loadPixelShader(&gApp, &gApp.nWidth, g_vblob_xpu);
  if ( v2->m_dwPShaderBloblet )
  {
    D3DDevice_DeletePixelShader(v2->m_dwPShaderBloblet);
    v2->m_dwPShaderBloblet = 0;
  }
  dwBlobShaderVertexDecl[4] = -1;
  v2->m_dwPShaderBloblet = (unsigned int)XBoxStartupApp::loadPixelShader(&gApp, &gApp.nWidth, g_vbloblet_xpu);
  v6 = v2->m_dwVShaderBlob;
  dwBlobShaderVertexDecl[0] = 0x20000000;
  dwBlobShaderVertexDecl[1] = 1077018624;
  dwBlobShaderVertexDecl[2] = 536870913;
  dwBlobShaderVertexDecl[3] = 1078067201;
  if ( v6 )
  {
    D3DDevice_DeleteVertexShader(v6);
    v2->m_dwVShaderBlob = 0;
  }
  v7 = XBoxStartupApp::loadVertexShader(g_vblob_xvu, dwBlobShaderVertexDecl);
  dwBlobletShaderVertexDecl[2] = -1;
  v2->m_dwVShaderBlob = (unsigned int)v7;
  v8 = v2->m_dwVShaderBloblet;
  dwBlobletShaderVertexDecl[0] = 0x20000000;
  dwBlobletShaderVertexDecl[1] = 1077018624;
  if ( v8 )
  {
    D3DDevice_DeleteVertexShader(v8);
    v2->m_dwVShaderBloblet = 0;
  }
  v2->m_dwVShaderBloblet = (unsigned int)XBoxStartupApp::loadVertexShader(g_vbloblet_xvu, dwBlobletShaderVertexDecl);
}
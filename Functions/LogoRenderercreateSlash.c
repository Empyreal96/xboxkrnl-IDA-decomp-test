void __usercall LogoRenderer::createSlash(LogoRenderer *this@<ecx>, int *a2@<edi>)
{
  LogoRenderer *v2; // ebx
  unsigned __int16 *v3; // eax
  unsigned __int16 *v4; // eax
  int v5; // ecx
  unsigned int v6; // ST00_4
  int v7; // ecx
  signed int v8; // esi
  float f_cos_w; // ST10_4
  unsigned __int16 *v10; // eax
  int v11; // ecx
  int v12; // [esp+14h] [ebp-8h]
  xbl_vertex *pv; // [esp+18h] [ebp-4h]

  v2 = this;
  v3 = this->indices_xboxlogolip_0;
  pv = 0;
  this->nLipIndices = 336;
  this->nLipVerts = 210;
  this->pLipIndices = v3;
  D3DDevice_CreateVertexBuffer(a2, (int)this, 0, 0x1068u, 0, 0x102u, 0, &this->pLipVB);
  D3DVertexBuffer_Lock(a2, v2->pLipVB, 0, 0, (char **)&pv, 0);
  qmemcpy(pv, v2->verts_xboxlogolip_0, 20 * v2->nLipVerts);
  v2->pLipTex = CreateGradientTexture(0x10u, 0x80u, 0xFF000100, 0xFF4B9B4B);
  v4 = v2->indices_xboxlogosurface_0;
  v2->nSurfaceIndices = 225;
  v2->nSurfaceVerts = 77;
  v2->pSurfaceIndices = v4;
  D3DDevice_CreateVertexBuffer(0, v5, (int)&v2->pSurfaceVB, 0x604u, 0, 0x102u, 0, &v2->pSurfaceVB);
  D3DVertexBuffer_Lock(0, v2->pSurfaceVB, 0, 0, (char **)&pv, 0);
  qmemcpy(pv, v2->verts_xboxlogosurface_0, 20 * v2->nSurfaceVerts);
  v2->pSurfaceTex = CreateHighlightTexture(256, 6, 0, 0.5, 0.5);
  v2->pSurfaceTopIndices = v2->indices_xboxlogosurfacetop_0;
  v6 = 20 * v2->nSurfaceVerts;
  v2->nSurfaceTopIndices = 105;
  v2->nSurfaceTopVerts = 34;
  D3DDevice_CreateVertexBuffer(0, v7, (int)&v2->pSurfaceTopVB, v6, 0, 0x102u, 0, &v2->pSurfaceTopVB);
  D3DVertexBuffer_Lock(0, v2->pSurfaceTopVB, 0, 0, (char **)&pv, 0);
  qmemcpy(pv, v2->verts_xboxlogosurfacetop_0, 20 * v2->nSurfaceTopVerts);
  v8 = 0;
  if ( (signed int)v2->nSurfaceTopVerts > 0 )
  {
    v12 = 0;
    do
    {
      f_cos_w = pv[v12].v0 - 1.0;
      if ( fast_fabs(f_cos_w) <= 0.0099999998 )
        pv[v12].v0 = -1.0;
      ++v12;
      ++v8;
    }
    while ( v8 < (signed int)v2->nSurfaceTopVerts );
  }
  v2->pSurfaceTopTex = CreateGradientTexture(0x10u, 0x80u, 0xFF000000, 0xFFFFFFFF);
  v10 = v2->indices_xboxlogointerior_0;
  v2->nInteriorIndices = 1008;
  v2->nInteriorVerts = 501;
  v2->pInteriorIndices = v10;
  D3DDevice_CreateVertexBuffer(0, v11, (int)&v2->pInteriorVB, 0x2724u, 0, 0x102u, 0, &v2->pInteriorVB);
  D3DVertexBuffer_Lock(0, v2->pInteriorVB, 0, 0, (char **)&pv, 0);
  qmemcpy(pv, v2->verts_xboxlogointerior_0, 20 * v2->nInteriorVerts);
}
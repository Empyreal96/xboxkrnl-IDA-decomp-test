void __fastcall SceneRenderer::create(SceneRenderer *this, int a2)
{
  SceneRenderer *v2; // esi
  signed int v3; // ebx
  int *v4; // eax
  int v5; // edx
  int v6; // ecx
  int *v7; // eax
  int v8; // edx
  __int16 **v9; // ebx
  __int16 *v10; // eax
  int v11; // edx
  __int16 **v12; // ebx
  __int16 *v13; // eax
  int v14; // edx
  int v15; // edx
  int v16; // ecx
  int *v17; // eax
  int v18; // edi
  int v19; // edx
  int v20; // ecx
  RotAnimSeq *p_indices; // [esp+Ch] [ebp-4h]
  PosAnimSeq *p_indicesa; // [esp+Ch] [ebp-4h]

  v2 = this;
  v3 = 0;
  do
  {
    v4 = MemAlloc(a2, (int)this, (int)v2, 0x6Cu);
    v2->pSetHiDet[v3] = (PrimitiveSet *)v4;
    PrimitiveSet::Init((PrimitiveSet *)v4);
    v7 = MemAlloc(v5, v6, (int)v2, 0x6Cu);
    v2->pSetLoDet[v3] = (PrimitiveSet *)v7;
    PrimitiveSet::Init((PrimitiveSet *)v7);
    ++v3;
  }
  while ( v3 < 6 );
  v2->pQuats = SceneRenderer::decompressQuats(a2, (int)v2, (int)v2, theQuats, theQuatSigns, numQuats);
  p_indices = theRotAnimSeq;
  v9 = v2->pQuatIdSeq;
  do
  {
    v10 = SceneRenderer::decompressIndices(v8, (int)v2, (int)v2, p_indices->quatIds, 30);
    ++p_indices;
    *v9 = v10;
    ++v9;
  }
  while ( (signed int)p_indices < (signed int)&word_8011147A );
  v2->pPos = SceneRenderer::decompressVecs((int)v2, v8, thePos, numPos);
  p_indicesa = thePosAnimSeq;
  v12 = v2->pPosIdSeq;
  do
  {
    v13 = SceneRenderer::decompressIndices(v11, (int)v2, (int)v2, p_indicesa->posIds, 30);
    ++p_indicesa;
    *v12 = v13;
    ++v12;
  }
  while ( (signed int)p_indicesa < (signed int)&numPos );
  SceneRenderer::createSceneGeometry((int)v2, v11, v2->pSetHiDet, 0);
  SceneRenderer::createSceneGeometry((int)v2, v14, v2->pSetLoDet, 1);
  v2->bUseLoDetail = 0;
  D3DDevice_CreateTexture(0, (int)v2, 0x200u, 0x200u, 1u, 0, D3DFMT_LIN_D16, 0, &v2->pSBufDepthLo);
  D3DDevice_CreateTexture(0, (int)v2, 0x200u, 0x200u, 1u, 0, D3DFMT_LIN_D16, 0, &v2->pSBufDepthHi);
  memset(&v2->fakeTarget, 0, sizeof(v2->fakeTarget));
  XGSetSurfaceHeader(0x200u, 0x200u, D3DFMT_LIN_R5G6B5, &v2->fakeTarget, 0, 0);
  v2->pSBufTarget = &v2->fakeTarget;
  D3DDevice_GetDepthStencilSurface((int *)&v2->fZOffset, &v2->pZBuffer);
  D3DDevice_GetRenderTarget((int *)&v2->fZOffset, &v2->pRenderTarget);
  v2->fZOffset = 10.0;
  v2->fZSlopeScale = 4.0;
  v2->nRotAnims = 29;
  v2->nPosAnims = 32;
  v17 = MemAlloc(v15, v16, (int)v2, 0x740u);
  v18 = v2->nPosAnims;
  v2->pRotAnims = (_D3DMATRIX *)v17;
  v2->pPosAnims = (_D3DVECTOR *)MemAlloc(v19, v20, (int)v2, 12 * v18);
}
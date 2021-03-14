void __thiscall SceneRenderer::destroy(SceneRenderer *this)
{
  SceneRenderer *v1; // esi
  signed int v2; // ebx
  PrimitiveSet **v3; // edi
  PrimitiveSet **v4; // edi
  void **v5; // edi
  signed int v6; // ebx
  void **v7; // edi
  signed int v8; // ebx
  int *v9; // edi
  D3DResource **v10; // esi

  v1 = this;
  v2 = 0;
  do
  {
    v3 = &v1->pSetHiDet[v2];
    PrimitiveSet::UnInit(*v3);
    MemFree(*v3);
    *v3 = 0;
    v4 = &v1->pSetLoDet[v2];
    PrimitiveSet::UnInit(*v4);
    MemFree(*v4);
    *v4 = 0;
    ++v2;
  }
  while ( v2 < 6 );
  MemFree(v1->pRotAnims);
  MemFree(v1->pPosAnims);
  MemFree(v1->pQuats);
  v5 = (void **)v1->pQuatIdSeq;
  v6 = 29;
  do
  {
    MemFree(*v5);
    ++v5;
    --v6;
  }
  while ( v6 );
  MemFree(v1->pPos);
  v7 = (void **)v1->pPosIdSeq;
  v8 = 32;
  do
  {
    MemFree(*v7);
    ++v7;
    --v8;
  }
  while ( v8 );
  v9 = (int *)&v1->pSBufDepthLo;
  if ( v1->pSBufDepthLo )
    D3DResource_Release(v9, (D3DResource *)&v1->pSBufDepthLo->Common);
  *v9 = 0;
  v10 = (D3DResource **)&v1->pSBufDepthHi;
  if ( *v10 )
    D3DResource_Release(v9, *v10);
  *v10 = 0;
}
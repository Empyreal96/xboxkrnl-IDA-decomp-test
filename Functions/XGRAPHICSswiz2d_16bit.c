void __userpurge XGRAPHICS::swiz2d_16bit(int *a1@<edi>, const void *pSrc, void *pDest, int Width, int Height)
{
  __m128 *v5; // esi
  unsigned int v6; // ebx
  int v7; // ecx
  int v8; // edx
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  int v11; // esi
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __m128 v14; // xmm6
  __m128 *v15; // esi
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm5
  __m128 v20; // xmm7
  __m128 *v21; // esi
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  unsigned int AddValU; // [esp+0h] [ebp-Ch]
  unsigned int AddValV; // [esp+4h] [ebp-8h]
  unsigned int MaskU; // [esp+8h] [ebp-4h]

  if ( (unsigned __int8)pDest & 0xF )
    XGRAPHICS::DXGRIP(a1, "Error: Destination memory must be 16-byte aligned");
  XGRAPHICS::GetMasks2((unsigned int)&MaskU, Width, Height, &MaskU, (unsigned int *)&Height);
  AddValU = MaskU & 0xFFFFFFC0;
  AddValV = Height & 0xFFFFFF80;
  v5 = (__m128 *)pSrc;
  v6 = 0;
  v7 = 0;
  v8 = 2 * Width;
  do
  {
    do
    {
      v9 = *v5;
      v10 = *(__m128 *)((char *)v5 + v8);
      v11 = (int)v5 + v8;
      v12 = *(__m128 *)(v11 + v8);
      v13 = *(__m128 *)(v11 + 4 * Width);
      v14 = _mm_unpackhi_ps(*(__m128 *)(v11 + v8), v13);
      v15 = (__m128 *)(v11 + 8 * Width);
      v16 = _mm_unpackhi_ps(v9, v10);
      v17 = _mm_unpacklo_ps(v12, v13);
      v18 = *v15;
      v19 = *(__m128 *)((char *)v15 + v8);
      v20 = *(__m128 *)((char *)v15 + 4 * Width);
      v21 = (__m128 *)((char *)v15 - v8);
      v22 = _mm_unpacklo_ps(v9, v10);
      v23 = *v21;
      _mm_stream_ps((float *)((char *)pDest + 2 * (v7 | v6)), v22);
      _mm_stream_ps((float *)((char *)pDest + 2 * (v7 | v6) + 16), v17);
      _mm_stream_ps((float *)((char *)pDest + 2 * (v7 | v6) + 32), v16);
      _mm_stream_ps((float *)((char *)pDest + 2 * (v7 | v6) + 48), v14);
      _mm_stream_ps((float *)((char *)pDest + 2 * (v7 | v6) + 64), _mm_unpacklo_ps(v23, v18));
      _mm_stream_ps((float *)((char *)pDest + 2 * (v7 | v6) + 80), _mm_unpacklo_ps(v19, v20));
      _mm_stream_ps((float *)((char *)pDest + 2 * (v7 | v6) + 96), _mm_unpackhi_ps(v23, v18));
      _mm_stream_ps((float *)((char *)pDest + 2 * (v7 | v6) + 112), _mm_unpackhi_ps(v19, v20));
      v5 = (__m128 *)((char *)v21 + -v8 - v8 - v8 - v8 + 16);
      v6 = MaskU & (v6 - AddValU);
    }
    while ( v6 );
    v5 = (__m128 *)((char *)&v5[Width] - 2 * Width);
    v7 = Height & (v7 - AddValV);
  }
  while ( v7 );
}
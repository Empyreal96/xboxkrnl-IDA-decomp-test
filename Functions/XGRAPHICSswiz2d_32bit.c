void __userpurge XGRAPHICS::swiz2d_32bit(int *a1@<edi>, const void *pSrc, void *pDest, int Width, int Height)
{
  __m128 *v5; // esi
  unsigned int v6; // ebx
  int v7; // ecx
  int v8; // edx
  __m128 v9; // xmm0
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 *v15; // esi
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm6
  __m128 v20; // xmm1
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  __m128 v23; // xmm7
  unsigned int AddValU; // [esp+0h] [ebp-Ch]
  unsigned int AddValV; // [esp+4h] [ebp-8h]
  unsigned int MaskU; // [esp+8h] [ebp-4h]

  if ( (unsigned __int8)pDest & 0xF )
    XGRAPHICS::DXGRIP(a1, "Error: Destination memory must be 16-byte aligned");
  XGRAPHICS::GetMasks2((unsigned int)&MaskU, Width, Height, &MaskU, (unsigned int *)&Height);
  AddValU = MaskU & 0xFFFFFFC0;
  AddValV = Height & 0xFFFFFFE0;
  v5 = (__m128 *)pSrc;
  v6 = 0;
  v7 = 0;
  v8 = 4 * Width;
  do
  {
    do
    {
      v9 = *v5;
      v10 = v5[1];
      v11 = *(__m128 *)((char *)v5 + v8);
      v12 = *(__m128 *)((char *)&v5[1] + v8);
      v13 = v9;
      v14 = v10;
      v15 = (__m128 *)((char *)v5 + 8 * Width);
      v16 = _mm_movelh_ps(v9, v11);
      v17 = _mm_movehl_ps(v11, v13);
      v18 = _mm_movelh_ps(v10, v12);
      v19 = _mm_movehl_ps(v12, v14);
      v20 = *v15;
      v21 = v15[1];
      v22 = *(__m128 *)((char *)v15 + v8);
      v23 = *(__m128 *)((char *)&v15[1] + v8);
      _mm_stream_ps((float *)pDest + (v7 | v6), v16);
      _mm_stream_ps((float *)pDest + (v7 | v6) + 4, v17);
      _mm_stream_ps((float *)pDest + (v7 | v6) + 16, v18);
      _mm_stream_ps((float *)pDest + (v7 | v6) + 20, v19);
      _mm_stream_ps((float *)pDest + (v7 | v6) + 8, _mm_movelh_ps(v20, v22));
      _mm_stream_ps((float *)pDest + (v7 | v6) + 12, _mm_movehl_ps(v22, v20));
      _mm_stream_ps((float *)pDest + (v7 | v6) + 24, _mm_movelh_ps(v21, v23));
      _mm_stream_ps((float *)pDest + (v7 | v6) + 28, _mm_movehl_ps(v23, v21));
      v5 = (__m128 *)((char *)v15 + -v8 - v8 + 32);
      v6 = MaskU & (v6 - AddValU);
    }
    while ( v6 );
    v5 = (__m128 *)((char *)&v5[Width] - 4 * Width);
    v7 = Height & (v7 - AddValV);
  }
  while ( v7 );
}
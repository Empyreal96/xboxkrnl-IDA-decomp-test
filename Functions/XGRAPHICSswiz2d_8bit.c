void __stdcall XGRAPHICS::swiz2d_8bit(const void *pSrc, void *pDest, int Width, int Height)
{
  __m64 *v4; // esi
  unsigned int v5; // ebx
  int v6; // ecx
  __m64 v7; // mm0
  __m64 v8; // mm1
  int v9; // esi
  __m64 v10; // mm4
  __m64 v11; // mm5
  int v12; // eax
  __m64 v13; // mm6
  __m64 *v14; // esi
  __m64 v15; // mm2
  __m64 v16; // mm4
  __m64 v17; // mm3
  __m64 v18; // mm5
  __m64 v19; // mm7
  __m64 *v20; // esi
  __m64 v21; // mm0
  __m64 v22; // mm1
  unsigned int AddValU; // [esp+Ch] [ebp-Ch]
  unsigned int AddValV; // [esp+10h] [ebp-8h]
  unsigned int MaskU; // [esp+14h] [ebp-4h]

  XGRAPHICS::GetMasks2((unsigned int)&MaskU, Width, Height, &MaskU, (unsigned int *)&Height);
  AddValU = MaskU & 0xFFFFFFC0;
  AddValV = Height & 0xFFFFFF80;
  v4 = (__m64 *)pSrc;
  v5 = 0;
  v6 = 0;
  do
  {
    do
    {
      v7 = (__m64)v4->m64_u64;
      v8 = *(__m64 *)((char *)v4 + Width);
      v9 = (int)v4 + Width;
      v10 = *(__m64 *)(v9 + Width);
      v11 = *(__m64 *)(v9 + 2 * Width);
      v12 = v6 | v5;
      v13 = _m_punpckhwd(*(__m64 *)(v9 + Width), v11);
      v14 = (__m64 *)(v9 + 4 * Width);
      v15 = _m_punpckhwd(v7, v8);
      v16 = _m_punpcklwd(v10, v11);
      v17 = (__m64)v14->m64_u64;
      v18 = *(__m64 *)((char *)v14 + Width);
      v19 = *(__m64 *)((char *)v14 + 2 * Width);
      v20 = (__m64 *)((char *)v14 - Width);
      v21 = _m_punpcklwd(v7, v8);
      v22 = (__m64)v20->m64_u64;
      *(__m64 *)((char *)pDest + v12) = v21;
      *(__m64 *)((char *)pDest + v12 + 8) = v16;
      *(__m64 *)((char *)pDest + v12 + 16) = v15;
      *(__m64 *)((char *)pDest + v12 + 24) = v13;
      *(__m64 *)((char *)pDest + v12 + 32) = _m_punpcklwd(v22, v17);
      *(__m64 *)((char *)pDest + v12 + 40) = _m_punpcklwd(v18, v19);
      *(__m64 *)((char *)pDest + v12 + 48) = _m_punpckhwd(v22, v17);
      *(__m64 *)((char *)pDest + v12 + 56) = _m_punpckhwd(v18, v19);
      v4 = (__m64 *)((char *)v20 + -Width - Width - Width - Width + 8);
      v5 = MaskU & (v5 - AddValU);
    }
    while ( v5 );
    v4 = (__m64 *)((char *)&v4[Width] - Width);
    v6 = Height & (v6 - AddValV);
  }
  while ( v6 );
  _m_femms();
}
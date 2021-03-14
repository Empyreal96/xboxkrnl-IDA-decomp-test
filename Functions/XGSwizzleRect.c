void __stdcall XGSwizzleRect(const void *pSource, unsigned int Pitch, tagRECT *pRect, void *pDest, unsigned int Width, unsigned int Height, tagPOINT *const pPoint, unsigned int BytesPerPixel)
{
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // esi
  int v13; // ecx
  unsigned int v14; // ebx
  unsigned int v15; // eax
  unsigned int v16; // edi
  int v17; // esi
  int v18; // eax
  unsigned int v19; // esi
  int v20; // eax
  unsigned int v21; // eax
  __m128 *v22; // esi
  float *v23; // edi
  unsigned int v24; // edx
  unsigned int v25; // ebx
  unsigned int v26; // ecx
  __m128 v27; // xmm0
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm6
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  __m128 *v33; // esi
  __m128 v34; // xmm0
  __m128 v35; // xmm2
  __m128 v36; // xmm4
  __m128 v37; // xmm6
  __m128 v38; // xmm1
  __m128 v39; // xmm5
  __m128 v40; // xmm3
  __m128 v41; // xmm7
  unsigned int v42; // eax
  unsigned int v43; // esi
  __m128 *v44; // esi
  char *v45; // edi
  unsigned int v46; // edx
  unsigned int v47; // ebx
  unsigned int v48; // ecx
  __m128 v49; // xmm0
  __m128 v50; // xmm1
  int v51; // esi
  __m128 v52; // xmm4
  __m128 v53; // xmm5
  __m128 v54; // xmm6
  __m128 *v55; // esi
  __m128 v56; // xmm2
  __m128 v57; // xmm4
  __m128 v58; // xmm3
  __m128 v59; // xmm5
  __m128 v60; // xmm7
  __m128 *v61; // esi
  __m128 v62; // xmm0
  __m128 v63; // xmm1
  __m64 *v64; // esi
  char *v65; // edi
  unsigned int v66; // edx
  unsigned int v67; // ebx
  unsigned int v68; // ecx
  __m64 v69; // mm0
  __m64 v70; // mm1
  int v71; // esi
  __m64 v72; // mm4
  __m64 v73; // mm5
  int v74; // eax
  __m64 v75; // mm6
  __m64 *v76; // esi
  __m64 v77; // mm2
  __m64 v78; // mm4
  __m64 v79; // mm3
  __m64 v80; // mm5
  __m64 v81; // mm7
  __m64 *v82; // esi
  __m64 v83; // mm0
  __m64 v84; // mm1
  unsigned int HeightMasks[3]; // [esp+Ch] [ebp-9Ch]
  unsigned int WidthMasks[3]; // [esp+18h] [ebp-90h]
  unsigned int MinBlockHeight[3]; // [esp+24h] [ebp-84h]
  unsigned int MinBlockWidth[3]; // [esp+30h] [ebp-78h]
  XGRAPHICS::XGINTERNALSWIZZLE s; // [esp+3Ch] [ebp-6Ch]
  unsigned int WidthStore; // [esp+B0h] [ebp+8h]
  unsigned int WidthStorea; // [esp+B0h] [ebp+8h]
  unsigned int WidthStoreb; // [esp+B0h] [ebp+8h]
  unsigned int WidthStorec; // [esp+B0h] [ebp+8h]
  char *EsiStore; // [esp+B4h] [ebp+Ch]
  char *EsiStorea; // [esp+B4h] [ebp+Ch]
  char *EsiStoreb; // [esp+B4h] [ebp+Ch]
  unsigned int StartU; // [esp+B8h] [ebp+10h]
  unsigned int StartUa; // [esp+B8h] [ebp+10h]
  unsigned int AddValU; // [esp+BCh] [ebp+14h]
  unsigned int WMask; // [esp+C4h] [ebp+1Ch]
  unsigned int WMaska; // [esp+C4h] [ebp+1Ch]
  unsigned int StartV; // [esp+C8h] [ebp+20h]
  unsigned int StartVa; // [esp+C8h] [ebp+20h]

  MinBlockWidth[0] = 16;
  MinBlockWidth[1] = 16;
  WidthMasks[0] = 7;
  WidthMasks[1] = 7;
  WidthMasks[2] = 7;
  HeightMasks[0] = 7;
  HeightMasks[1] = 7;
  MinBlockWidth[2] = 8;
  MinBlockHeight[0] = 8;
  MinBlockHeight[1] = 8;
  MinBlockHeight[2] = 8;
  HeightMasks[2] = 3;
  if ( (Width - 1) & Width || (Height - 1) & Height )
    XGRAPHICS::DXGRIP((int *)8, "XGSwizzleRect - Width and Height must be power of 2!");
  if ( Width < 1 || Width > 0x1000 || Height < 1 || Height > 0x1000 )
    XGRAPHICS::DXGRIP((int *)8, "XGSwizzleRect - Width and Height must be between 1 and 4096");
  if ( BytesPerPixel != 4 && BytesPerPixel != 2 && BytesPerPixel != 1 )
    XGRAPHICS::DXGRIP((int *)8, "XGSwizzleRect - BytesPerPixel must be 1, 2, or 4!");
  if ( Width <= 2 || Height <= 1 )
  {
    qmemcpy(pDest, pSource, BytesPerPixel * Height * Width);
    return;
  }
  if ( !pRect && !pPoint && !Pitch )
  {
    if ( BytesPerPixel == 4 )
    {
      if ( Width >= 8 && Height >= 8 )
      {
        XGRAPHICS::swiz2d_32bit((int *)8, pSource, pDest, Width, Height);
        return;
      }
    }
    else if ( BytesPerPixel == 2 )
    {
      if ( Width >= 0x10 && Height >= 8 )
      {
        XGRAPHICS::swiz2d_16bit((int *)8, pSource, pDest, Width, Height);
        return;
      }
    }
    else if ( Width >= 0x10 && Height >= 8 )
    {
      XGRAPHICS::swiz2d_8bit(pSource, pDest, Width, Height);
      return;
    }
  }
  Swizzler::Swizzler(&s.swiz);
  s.bpp = BytesPerPixel;
  s.Height = Height;
  s.Width = Width;
  if ( pPoint )
  {
    v8 = pPoint->y;
    s.DLeft = pPoint->x;
    s.DTop = v8;
  }
  else
  {
    s.DLeft = 0;
    s.DTop = 0;
  }
  s.pDest = pDest;
  s.pSource = pSource;
  if ( pRect )
  {
    v9 = pRect->top;
    s.RHeight = pRect->bottom - v9;
    v10 = pRect->left;
    s.RWidth = pRect->right - pRect->left;
    s.SLeft = v10;
    s.STop = v9;
  }
  else
  {
    s.SLeft = 0;
    s.STop = 0;
    s.RHeight = Height;
    s.RWidth = Width;
  }
  v11 = Pitch;
  if ( !Pitch )
    v11 = BytesPerPixel * Width;
  s.Pitch = v11;
  Swizzler::Init(&s.swiz, Width, Height, 0);
  s.mask[0] = s.swiz.m_MaskU;
  s.mask[1] = s.swiz.m_MaskV;
  if ( s.DLeft + s.RWidth > Width || s.DTop + s.RHeight > Height )
    XGRAPHICS::DXGRIP(
      (int *)Height,
      "XGSwizzleRect - The swizzled rectangle must fit completely inside of the destination texture, this routine does no clipping.");
  v12 = s.Pitch;
  if ( s.Pitch < BytesPerPixel * s.RWidth )
    XGRAPHICS::DXGRIP(
      (int *)Height,
      "XGSwizzleRect - The pitch of the source rectangle must be at least as big as the rectangle width * BytesPerPixel.");
  v13 = s.RHeight;
  if ( s.RHeight && s.RWidth )
  {
    WidthStore = BytesPerPixel >> 1;
    v14 = WidthMasks[WidthStore];
    if ( s.DLeft & 1 )
    {
      s.xOff = 0;
      s.yOff = 0;
      s.uWidth = 1;
      s.uHeight = s.RHeight;
      if ( s.bpp == 4 )
      {
        XGRAPHICS::XGInternalSwizzler<unsigned long>::Swizzle1x1Column(&s);
      }
      else if ( s.bpp == 2 )
      {
        XGRAPHICS::XGInternalSwizzler<unsigned short>::Swizzle1x1Column(&s);
      }
      else
      {
        XGRAPHICS::XGInternalSwizzler<unsigned char>::Swizzle1x1Column(&s);
      }
      ++s.SLeft;
      ++s.DLeft;
      if ( !--s.RWidth )
        return;
      v12 = s.Pitch;
      v13 = s.RHeight;
    }
    v15 = s.DTop;
    if ( s.RWidth & 1 )
    {
      s.xOff = --s.RWidth;
      s.yOff = 0;
      s.uWidth = 1;
      s.uHeight = v13;
      if ( s.bpp == 4 )
      {
        XGRAPHICS::XGInternalSwizzler<unsigned long>::Swizzle1x1Column(&s);
      }
      else if ( s.bpp == 2 )
      {
        XGRAPHICS::XGInternalSwizzler<unsigned short>::Swizzle1x1Column(&s);
      }
      else
      {
        XGRAPHICS::XGInternalSwizzler<unsigned char>::Swizzle1x1Column(&s);
      }
      if ( !s.RWidth )
        return;
      v12 = s.Pitch;
      v15 = s.DTop;
    }
    if ( (~v14 & (s.DLeft + v14)) >= (~v14 & (s.DLeft + s.RWidth))
      || (v16 = HeightMasks[WidthStore],
          (~HeightMasks[WidthStore] & (v16 + v15)) >= (~HeightMasks[WidthStore] & (v15 + s.RHeight)))
      || s.Width < MinBlockWidth[WidthStore]
      || s.Height < MinBlockHeight[WidthStore] )
    {
      s.xOff = 0;
      s.yOff = 0;
      s.uHeight = s.RHeight;
      s.uWidth = s.RWidth;
      if ( s.bpp == 4 )
      {
        XGRAPHICS::XGInternalSwizzler<__int64>::Swizzle2x1(&s);
      }
      else if ( s.bpp == 2 )
      {
        XGRAPHICS::XGInternalSwizzler<unsigned long>::Swizzle2x1(&s);
      }
      else
      {
        XGRAPHICS::XGInternalSwizzler<unsigned short>::Swizzle2x1(&s);
      }
    }
    else
    {
      if ( v16 & v15 )
      {
        v17 = v16 & -v15;
        s.uWidth = s.RWidth;
        s.xOff = 0;
        s.yOff = 0;
        s.uHeight = v16 & -v15;
        if ( s.bpp == 4 )
        {
          XGRAPHICS::XGInternalSwizzler<__int64>::Swizzle2x1(&s);
        }
        else if ( s.bpp == 2 )
        {
          XGRAPHICS::XGInternalSwizzler<unsigned long>::Swizzle2x1(&s);
        }
        else
        {
          XGRAPHICS::XGInternalSwizzler<unsigned short>::Swizzle2x1(&s);
        }
        s.STop += v17;
        s.DTop += v17;
        s.RHeight -= v17;
        v12 = s.Pitch;
      }
      v18 = s.RHeight & v16;
      if ( s.RHeight & v16 )
      {
        s.RHeight -= v18;
        s.yOff = s.RHeight;
        s.uHeight = v18;
        s.xOff = 0;
        s.uWidth = s.RWidth;
        if ( s.bpp == 4 )
        {
          XGRAPHICS::XGInternalSwizzler<__int64>::Swizzle2x1(&s);
        }
        else if ( s.bpp == 2 )
        {
          XGRAPHICS::XGInternalSwizzler<unsigned long>::Swizzle2x1(&s);
        }
        else
        {
          XGRAPHICS::XGInternalSwizzler<unsigned short>::Swizzle2x1(&s);
        }
        v12 = s.Pitch;
      }
      if ( s.DLeft & v14 )
      {
        v19 = v14 & -s.DLeft;
        s.uHeight = s.RHeight;
        s.xOff = 0;
        s.yOff = 0;
        s.uWidth = v14 & -s.DLeft;
        if ( s.bpp == 4 )
        {
          XGRAPHICS::XGInternalSwizzler<__int64>::Swizzle2x1(&s);
        }
        else if ( s.bpp == 2 )
        {
          XGRAPHICS::XGInternalSwizzler<unsigned long>::Swizzle2x1(&s);
        }
        else
        {
          XGRAPHICS::XGInternalSwizzler<unsigned short>::Swizzle2x1(&s);
        }
        s.DLeft += v19;
        s.SLeft += v19;
        s.RWidth -= v19;
        v12 = s.Pitch;
      }
      v20 = s.RWidth & v14;
      if ( s.RWidth & v14 )
      {
        s.RWidth -= v20;
        s.yOff = 0;
        s.uWidth = v20;
        s.uHeight = s.RHeight;
        s.xOff = s.RWidth;
        if ( s.bpp == 4 )
        {
          XGRAPHICS::XGInternalSwizzler<__int64>::Swizzle2x1(&s);
        }
        else if ( s.bpp == 2 )
        {
          XGRAPHICS::XGInternalSwizzler<unsigned long>::Swizzle2x1(&s);
        }
        else
        {
          XGRAPHICS::XGInternalSwizzler<unsigned short>::Swizzle2x1(&s);
        }
        v12 = s.Pitch;
      }
      AddValU = s.swiz.m_MaskU & 0xFFFFFFC0;
      if ( s.bpp == 4 )
      {
        WMask = s.swiz.m_MaskV & 0xFFFFFFE0;
        StartU = Swizzler::SwizzleU(&s.swiz, s.DLeft);
        v21 = Swizzler::SwizzleV(&s.swiz, s.DTop);
        s.RWidth >>= 3;
        s.RHeight >>= 2;
        StartV = v21;
        s.pSource = (char *)s.pSource + 4 * s.SLeft + s.STop * v12;
        WidthStorea = s.RWidth;
        if ( (_DWORD)s.pDest & 0xF )
          XGRAPHICS::DXGRIP((int *)v16, "XBSwizzleRect: pDest must be 16-byte aligned");
        v22 = (__m128 *)s.pSource;
        v23 = (float *)s.pDest;
        v24 = 4 * s.Width;
        v25 = StartU;
        v26 = StartV;
        EsiStore = (char *)s.pSource;
        do
        {
          do
          {
            v27 = *v22;
            v28 = v22[1];
            v29 = *(__m128 *)((char *)v22 + v24);
            v30 = *(__m128 *)((char *)&v22[1] + v24);
            v31 = v27;
            v32 = v28;
            v33 = (__m128 *)((char *)v22 + 2 * v24);
            v34 = _mm_movelh_ps(v27, v29);
            v35 = _mm_movehl_ps(v29, v31);
            v36 = _mm_movelh_ps(v28, v30);
            v37 = _mm_movehl_ps(v30, v32);
            v38 = *v33;
            v39 = v33[1];
            v40 = *(__m128 *)((char *)v33 + v24);
            v41 = *(__m128 *)((char *)&v33[1] + v24);
            _mm_stream_ps(&v23[v26 | v25], v34);
            _mm_stream_ps(&v23[(v26 | v25) + 4], v35);
            _mm_stream_ps(&v23[(v26 | v25) + 16], v36);
            _mm_stream_ps(&v23[(v26 | v25) + 20], v37);
            _mm_stream_ps(&v23[(v26 | v25) + 8], _mm_movelh_ps(v38, v40));
            _mm_stream_ps(&v23[(v26 | v25) + 12], _mm_movehl_ps(v40, v38));
            _mm_stream_ps(&v23[(v26 | v25) + 24], _mm_movelh_ps(v39, v41));
            _mm_stream_ps(&v23[(v26 | v25) + 28], _mm_movehl_ps(v41, v39));
            v22 = (__m128 *)((char *)v33 + -v24 - v24 + 32);
            v25 = s.swiz.m_MaskU & (v25 - AddValU);
            --s.RWidth;
          }
          while ( s.RWidth );
          v25 = StartU;
          s.RWidth = WidthStorea;
          v22 = (__m128 *)&EsiStore[4 * s.Pitch];
          v26 = s.swiz.m_MaskV & (v26 - WMask);
          EsiStore += 4 * s.Pitch;
          --s.RHeight;
        }
        while ( s.RHeight );
      }
      else
      {
        WMaska = s.swiz.m_MaskV & 0xFFFFFF80;
        StartUa = Swizzler::SwizzleU(&s.swiz, s.DLeft);
        v42 = Swizzler::SwizzleV(&s.swiz, s.DTop);
        v43 = s.STop * v12;
        s.RWidth >>= 3;
        StartVa = v42;
        if ( s.bpp == 2 )
        {
          s.RHeight >>= 3;
          s.pSource = (char *)s.pSource + 2 * s.SLeft + v43;
          WidthStoreb = s.RWidth;
          if ( (_DWORD)s.pDest & 0xF )
            XGRAPHICS::DXGRIP((int *)v16, "XBSwizzleRect: pDest must be 16-byte aligned");
          v44 = (__m128 *)s.pSource;
          v45 = (char *)s.pDest;
          v46 = 2 * s.Width;
          v47 = StartUa;
          v48 = StartVa;
          EsiStorea = (char *)s.pSource;
          do
          {
            do
            {
              v49 = *v44;
              v50 = *(__m128 *)((char *)v44 + v46);
              v51 = (int)v44 + v46;
              v52 = *(__m128 *)(v51 + v46);
              v53 = *(__m128 *)(v51 + 2 * v46);
              v54 = _mm_unpackhi_ps(*(__m128 *)(v51 + v46), v53);
              v55 = (__m128 *)(v51 + 4 * v46);
              v56 = _mm_unpackhi_ps(v49, v50);
              v57 = _mm_unpacklo_ps(v52, v53);
              v58 = *v55;
              v59 = *(__m128 *)((char *)v55 + v46);
              v60 = *(__m128 *)((char *)v55 + 2 * v46);
              v61 = (__m128 *)((char *)v55 - v46);
              v62 = _mm_unpacklo_ps(v49, v50);
              v63 = *v61;
              _mm_stream_ps((float *)&v45[2 * (v48 | v47)], v62);
              _mm_stream_ps((float *)&v45[2 * (v48 | v47) + 16], v57);
              _mm_stream_ps((float *)&v45[2 * (v48 | v47) + 32], v56);
              _mm_stream_ps((float *)&v45[2 * (v48 | v47) + 48], v54);
              _mm_stream_ps((float *)&v45[2 * (v48 | v47) + 64], _mm_unpacklo_ps(v63, v58));
              _mm_stream_ps((float *)&v45[2 * (v48 | v47) + 80], _mm_unpacklo_ps(v59, v60));
              _mm_stream_ps((float *)&v45[2 * (v48 | v47) + 96], _mm_unpackhi_ps(v63, v58));
              _mm_stream_ps((float *)&v45[2 * (v48 | v47) + 112], _mm_unpackhi_ps(v59, v60));
              v44 = (__m128 *)((char *)v61 + -v46 - v46 - v46 - v46 + 16);
              v47 = s.swiz.m_MaskU & (v47 - AddValU);
              --s.RWidth;
            }
            while ( s.RWidth );
            v47 = StartUa;
            s.RWidth = WidthStoreb;
            v44 = (__m128 *)&EsiStorea[8 * s.Pitch];
            v48 = s.swiz.m_MaskV & (v48 - WMaska);
            EsiStorea += 8 * s.Pitch;
            --s.RHeight;
          }
          while ( s.RHeight );
        }
        else
        {
          s.RHeight >>= 3;
          s.pSource = (char *)s.pSource + v43 + s.bpp * s.SLeft;
          WidthStorec = s.RWidth;
          v64 = (__m64 *)s.pSource;
          v65 = (char *)s.pDest;
          v66 = s.Width;
          v67 = StartUa;
          v68 = v42;
          EsiStoreb = (char *)s.pSource;
          do
          {
            do
            {
              v69 = (__m64)v64->m64_u64;
              v70 = *(__m64 *)((char *)v64 + v66);
              v71 = (int)v64 + v66;
              v72 = *(__m64 *)(v71 + v66);
              v73 = *(__m64 *)(v71 + 2 * v66);
              v74 = v68 | v67;
              v75 = _m_punpckhwd(*(__m64 *)(v71 + v66), v73);
              v76 = (__m64 *)(v71 + 4 * v66);
              v77 = _m_punpckhwd(v69, v70);
              v78 = _m_punpcklwd(v72, v73);
              v79 = (__m64)v76->m64_u64;
              v80 = *(__m64 *)((char *)v76 + v66);
              v81 = *(__m64 *)((char *)v76 + 2 * v66);
              v82 = (__m64 *)((char *)v76 - v66);
              v83 = _m_punpcklwd(v69, v70);
              v84 = (__m64)v82->m64_u64;
              *(__m64 *)&v65[v74] = v83;
              *(__m64 *)&v65[v74 + 8] = v78;
              *(__m64 *)&v65[v74 + 16] = v77;
              *(__m64 *)&v65[v74 + 24] = v75;
              *(__m64 *)&v65[v74 + 32] = _m_punpcklwd(v84, v79);
              *(__m64 *)&v65[v74 + 40] = _m_punpcklwd(v80, v81);
              *(__m64 *)&v65[v74 + 48] = _m_punpckhwd(v84, v79);
              *(__m64 *)&v65[v74 + 56] = _m_punpckhwd(v80, v81);
              v64 = (__m64 *)((char *)v82 + -v66 - v66 - v66 - v66 + 8);
              v67 = s.swiz.m_MaskU & (v67 - AddValU);
              --s.RWidth;
            }
            while ( s.RWidth );
            v67 = StartUa;
            s.RWidth = WidthStorec;
            v64 = (__m64 *)&EsiStoreb[8 * s.Pitch];
            v68 = s.swiz.m_MaskV & (v68 - WMaska);
            EsiStoreb += 8 * s.Pitch;
            --s.RHeight;
          }
          while ( s.RHeight );
          _m_femms();
        }
      }
    }
  }
}
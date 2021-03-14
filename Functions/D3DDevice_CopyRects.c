// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_CopyRects(D3DSurface *pSourceSurface, tagRECT *pSourceRectsArray, unsigned int cRects, D3DSurface *pDestinationSurface, tagPOINT *pDestPointsArray)
{
  unsigned int v5; // esi
  unsigned __int8 v6; // bl
  int v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // esi
  signed int v10; // eax
  signed int v11; // ebx
  unsigned int v12; // esi
  int *v13; // edx
  signed int v14; // eax
  signed int v15; // eax
  unsigned int v16; // edx
  tagPOINT *v17; // edi
  unsigned int v18; // eax
  tagRECT *v19; // ecx
  unsigned int v20; // ebx
  int *v21; // esi
  int v22; // eax
  int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // edx
  unsigned int v26; // esi
  _DWORD *v27; // eax
  _DWORD *v28; // esi
  D3DK::CDevice *v29; // edi
  D3DBaseTexture *v30; // eax
  tagRECT Rectangles[16]; // [esp+Ch] [ebp-1D0h]
  tagPOINT Points[16]; // [esp+10Ch] [ebp-D0h]
  unsigned int DSlice; // [esp+18Ch] [ebp-50h]
  unsigned int SSlice; // [esp+190h] [ebp-4Ch]
  unsigned int DDepth; // [esp+194h] [ebp-48h]
  unsigned int SDepth; // [esp+198h] [ebp-44h]
  unsigned int destinationBase; // [esp+19Ch] [ebp-40h]
  unsigned int SPitch; // [esp+1A0h] [ebp-3Ch]
  unsigned int DPitch; // [esp+1A4h] [ebp-38h]
  unsigned int BytesPerPixel; // [esp+1A8h] [ebp-34h]
  int IsSwizzledFormat; // [esp+1ACh] [ebp-30h]
  unsigned int SwizzledRows; // [esp+1B0h] [ebp-2Ch]
  unsigned int DHeight; // [esp+1B4h] [ebp-28h]
  unsigned int DWidth; // [esp+1B8h] [ebp-24h]
  unsigned int SwizzledColumns; // [esp+1BCh] [ebp-20h]
  D3DK::CDevice *pDevice; // [esp+1C0h] [ebp-1Ch]
  unsigned int SHeight; // [esp+1C4h] [ebp-18h]
  unsigned int DestPitch; // [esp+1C8h] [ebp-14h]
  unsigned int SWidth; // [esp+1CCh] [ebp-10h]
  unsigned int SourcePitch; // [esp+1D0h] [ebp-Ch]
  tagRECT *pRectangles; // [esp+1D4h] [ebp-8h]
  unsigned int RectangleCount; // [esp+1D8h] [ebp-4h]

  ++D3DK::g_PerfCounters.m_APICounters[21];
  v5 = BYTE1(pSourceSurface->Format);
  v6 = D3DK::g_TextureFormat[v5];
  BytesPerPixel = ((unsigned int)v6 >> 3) & 7;
  SourcePitch = D3DK::PixelJar::GetPitch((D3DPixelContainer *)&pSourceSurface->Common);
  DestPitch = D3DK::PixelJar::GetPitch((D3DPixelContainer *)&pDestinationSurface->Common);
  v7 = v6 & 1 || D3DK::IsCompressedD3DFORMAT(v5);
  pDevice = D3DK::g_pDevice;
  IsSwizzledFormat = v7;
  D3DK::PixelJar::GetSize((D3DPixelContainer *)&pSourceSurface->Common, 0, &SWidth, &SHeight, &SDepth, &SPitch, &SSlice);
  D3DK::PixelJar::GetSize(
    (D3DPixelContainer *)&pDestinationSurface->Common,
    0,
    &DWidth,
    &DHeight,
    &DDepth,
    &DPitch,
    &DSlice);
  if ( !v7 && (SPitch < 0x40 || DPitch < 0x40) )
    D3DK::DXGRIP(
      (int *)pSourceSurface,
      "D3DDevice_CopyRects - The source and destination surfaces must have a pitch of at least 64 bytes");
  if ( pDevice->m_StateFlags & 4 )
    D3DK::DXGRIP((int *)pSourceSurface, "Can't call CopyRects while recording a push-buffer");
  if ( BYTE1(pSourceSurface->Format) != BYTE1(pDestinationSurface->Format) )
    D3DK::DXGRIP(
      (int *)pSourceSurface,
      "D3DDevice_CopyRects - The source and destination surfaces must have the same format.");
  if ( !v7 && SourcePitch > 0x1FC0 )
    D3DK::DXGRIP(
      (int *)pSourceSurface,
      "D3DDevice_CopyRects - CopyRects does not work on surfaces who pitch is greater than 8128 bytes.");
  if ( !cRects )
    cRects = 1;
  if ( v7 )
  {
    v8 = D3DK::PixelJar::GetSlice((D3DPixelContainer *)&pSourceSurface->Common);
    v9 = v8;
    BytesPerPixel = 1;
    if ( v8 > 0x1FC0 )
    {
      if ( v8 & 0xFFF )
        D3DK::DXGRIP((int *)pSourceSurface, "Assertion failure: %s", "Slice % 4096 == 0");
      v10 = 4096;
      SwizzledColumns = 4096;
      SwizzledRows = v9 >> 12;
    }
    else
    {
      v10 = (v8 + 63) & 0xFFFFFFC0;
      SwizzledColumns = v9;
      SwizzledRows = 1;
    }
    SourcePitch = v10;
    DestPitch = v10;
  }
  destinationBase = (unsigned int)D3DK::CMiniport::SetDmaRange(&pDevice->m_Miniport, 0xBu, pDestinationSurface);
  do
  {
    v11 = 16;
    if ( cRects <= 0x10 )
      v11 = cRects;
    cRects -= v11;
    RectangleCount = v11;
    if ( pSourceRectsArray )
    {
      pRectangles = pSourceRectsArray;
      pSourceRectsArray += 16;
    }
    else
    {
      pRectangles = Rectangles;
      if ( v11 )
      {
        v12 = pSourceSurface->Size;
        v13 = &Rectangles[0].bottom;
        do
        {
          *(v13 - 2) = 0;
          if ( v12 )
            v14 = ((v12 >> 12) & 0xFFF) + 1;
          else
            v14 = 1 << (HIBYTE(pSourceSurface->Format) & 0xF);
          *v13 = v14;
          *(v13 - 3) = 0;
          if ( v12 )
            v15 = (v12 & 0xFFF) + 1;
          else
            v15 = 1 << ((pSourceSurface->Format >> 20) & 0xF);
          *(v13 - 1) = v15;
          v13 += 4;
          --v11;
        }
        while ( v11 );
      }
    }
    v16 = RectangleCount;
    if ( pDestPointsArray )
    {
      v17 = pDestPointsArray;
      pDestPointsArray += 16;
    }
    else
    {
      v18 = 0;
      v17 = Points;
      if ( RectangleCount )
      {
        v19 = pRectangles;
        do
        {
          Points[v18].x = v19->left;
          Points[v18++].y = v19->top;
          ++v19;
        }
        while ( v18 < v16 );
      }
    }
    v20 = 0;
    if ( v16 )
    {
      v21 = &pRectangles->right;
      do
      {
        if ( D3DK::g_TextureFormat[BYTE1(pSourceSurface->Format)] & 1
          || D3DK::IsCompressedD3DFORMAT(BYTE1(pSourceSurface->Format)) )
        {
          if ( v17[v20].x || v17[v20].y || *(v21 - 1) || *(v21 - 2) || *v21 != SWidth || v21[1] != SHeight )
            D3DK::DXGRIP(&v17->x, "D3DDevice_CopyRects - CopyRects can only copy all of a swizzled surface.");
          if ( SWidth != DWidth || SHeight != DHeight )
            D3DK::DXGRIP(
              &v17->x,
              "D3DDevice_CopyRects - The source and destination surfaces must be the same size when copying a swizzled surface.");
        }
        else
        {
          if ( *(v21 - 1) >= v21[1] || *(v21 - 2) >= *v21 )
            D3DK::DXGRIP(
              &v17->x,
              "D3DDevice_CopyRects - Malformed source rectangle, one dimension is either zero size or is inverted.");
          if ( *(v21 - 1) < 0 || v21[1] > (signed int)SHeight || *(v21 - 2) < 0 || *v21 > (signed int)SWidth )
            D3DK::DXGRIP(
              &v17->x,
              "D3DDevice_CopyRects - The source rectangle extends beyond the bounds of the source surface.");
          v22 = v17[v20].x;
          if ( v22 < 0
            || *v21 + v22 - *(v21 - 2) > (signed int)DWidth
            || (v23 = v17[v20].y, v23 < 0)
            || v23 + v21[1] - *(v21 - 1) > (signed int)DHeight )
          {
            D3DK::DXGRIP(
              &v17->x,
              "D3DDevice_CopyRects - The destination rectangle extends beyond the bounds of the destination surface.");
          }
        }
        ++v20;
        v21 += 4;
      }
      while ( v20 < RectangleCount );
    }
    if ( IsSwizzledFormat )
    {
      v24 = RectangleCount;
      if ( RectangleCount > 0 )
      {
        v25 = SwizzledColumns;
        v26 = SwizzledRows;
        v27 = &pRectangles->right;
        do
        {
          *(v27 - 2) = 0;
          *(v27 - 1) = 0;
          *v27 = v25;
          v27[1] = v26;
          v27 += 4;
          --v24;
        }
        while ( v24 );
      }
    }
    D3DK::GPUCopyVideoRectangle(
      BytesPerPixel,
      pSourceSurface->Data,
      SourcePitch,
      pDestinationSurface->Data - destinationBase,
      DestPitch,
      RectangleCount,
      pRectangles,
      v17);
  }
  while ( cRects );
  v28 = &pSourceSurface->Common;
  if ( (pSourceSurface->Common & 0x70000) != 327680 )
    D3DK::DXGRIP(&v17->x, "Assertion failure: %s", "PixelJar::IsSurface(pResource)");
  if ( pSourceSurface->Parent )
    v28 = &pSourceSurface->Parent->Common;
  v29 = pDevice;
  v28[2] = pDevice->m_CpuTime;
  if ( (pDestinationSurface->Common & 0x70000) != 327680 )
    D3DK::DXGRIP((int *)v29, "Assertion failure: %s", "PixelJar::IsSurface(pResource)");
  v30 = pDestinationSurface->Parent;
  if ( v30 )
    v30->Lock = v29->m_CpuTime;
  else
    pDestinationSurface->Lock = v29->m_CpuTime;
}
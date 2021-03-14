void __stdcall D3DK::PixelJar::FindSurfaceWithinTexture(D3DPixelContainer *pPixels, _D3DCUBEMAP_FACES FaceType, unsigned int Level, char **ppbData, unsigned int *pRowPitch, unsigned int *pSlicePitch, unsigned int *pFormat, unsigned int *pSize)
{
  char *v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // esi
  unsigned int v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // edi
  unsigned int v14; // edx
  char v15; // cl
  unsigned int v16; // ecx
  int v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // ebx
  char v20; // cl
  char v21; // bl
  bool v22; // zf
  int v23; // ebx
  signed int v24; // eax
  int v25; // edx
  unsigned int v26; // eax
  int v27; // esi
  int v28; // [esp+10h] [ebp-20h]
  char v29; // [esp+14h] [ebp-1Ch]
  unsigned int FaceSize; // [esp+18h] [ebp-18h]
  unsigned int LogDepth; // [esp+1Ch] [ebp-14h]
  unsigned int LogHeight; // [esp+20h] [ebp-10h]
  int TexelSize; // [esp+24h] [ebp-Ch]
  unsigned int LogMin; // [esp+28h] [ebp-8h]
  char *pbData; // [esp+2Ch] [ebp-4h]
  unsigned int FaceTypea; // [esp+3Ch] [ebp+Ch]

  v8 = D3DK::GetDataFromResource((int *)pPixels, (D3DResource *)&pPixels->Common);
  v9 = BYTE1(pPixels->Format);
  v10 = pPixels->Size;
  pbData = v8;
  TexelSize = D3DK::g_TextureFormat[v9] & 0x3C;
  v11 = pPixels->Format;
  if ( v10 )
  {
    v25 = ((v10 >> 24) + 1) << 6;
    *pFormat = v11;
    v27 = v25 * (((v10 >> 12) & 0xFFF) + 1);
    v26 = pPixels->Size;
  }
  else
  {
    v12 = (v11 >> 20) & 0xF;
    v13 = (v11 >> 24) & 0xF;
    v14 = v11 >> 28;
    v15 = 0;
    if ( v9 == 12 || v9 > 0xD && v9 <= 0xF )
      v15 = 1;
    v16 = v15 != 0 ? 2 : 0;
    LogMin = v16;
    if ( FaceType )
    {
      v17 = (v11 >> 16) & 0xF;
      v18 = (v11 >> 20) & 0xF;
      LogHeight = v13;
      LogDepth = v14;
      FaceSize = 0;
      if ( v17 )
      {
        v28 = v17;
        v19 = v13;
        do
        {
          v20 = LogMin;
          v29 = v18;
          if ( v18 <= LogMin )
            v29 = LogMin;
          if ( v19 > LogMin )
            v20 = v19;
          FaceSize += (unsigned int)(TexelSize * (1 << (v29 + v20))) >> 3;
          if ( v18 )
            --v18;
          v19 = LogHeight;
          if ( LogHeight )
            v19 = LogHeight-- - 1;
          if ( LogDepth )
            --LogDepth;
          --v28;
        }
        while ( v28 );
      }
      v16 = LogMin;
      pbData += FaceType * ((FaceSize + 127) & 0xFFFFFF80);
      v11 = pPixels->Format;
    }
    if ( Level )
    {
      FaceTypea = Level;
      do
      {
        v21 = v12;
        if ( v12 <= v16 )
          v21 = v16;
        if ( v13 > v16 )
          LOBYTE(v16) = v13;
        pbData += (unsigned int)(TexelSize * (1 << (v14 + v21 + v16))) >> 3;
        if ( v12 )
          --v12;
        if ( v13 )
          --v13;
        if ( v14 )
          --v14;
        v22 = FaceTypea-- == 1;
        v16 = LogMin;
      }
      while ( !v22 );
    }
    v23 = v11 & 0xFFFFF | ((v12 | 16 * (v13 | 16 * v14)) << 20);
    if ( v12 <= v16 )
      LOBYTE(v12) = v16;
    if ( v13 <= v16 )
      LOBYTE(v13) = v16;
    v24 = BYTE1(pPixels->Format);
    if ( v24 == 12 )
    {
      v25 = 2 * (1 << v12);
    }
    else if ( v24 <= 13 || v24 > 15 )
    {
      v25 = (unsigned int)(TexelSize * (1 << v12)) >> 3;
    }
    else
    {
      v25 = 4 * (1 << v12);
    }
    *pFormat = v23;
    v26 = pPixels->Size;
    v27 = (unsigned int)(TexelSize * (1 << (v13 + v12))) >> 3;
  }
  *pSize = v26;
  *ppbData = pbData;
  *pRowPitch = v25;
  *pSlicePitch = v27;
}
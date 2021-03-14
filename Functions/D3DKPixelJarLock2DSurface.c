void __stdcall D3DK::PixelJar::Lock2DSurface(D3DPixelContainer *pPixels, _D3DCUBEMAP_FACES FaceType, unsigned int Level, _D3DLOCKED_RECT *pLockedRect, tagRECT *pRect, unsigned int Flags)
{
  tagRECT *v6; // ebx
  D3DPixelContainer *v7; // esi
  int *v8; // edi
  char *v9; // ecx
  _D3DLOCKED_RECT *v10; // edx
  _D3DLOCKED_RECT *v11; // eax
  D3DPixelContainer *v12; // edx
  unsigned int Depth; // [esp+Ch] [ebp-Ch]
  unsigned int Pitch; // [esp+10h] [ebp-8h]
  unsigned int Slice; // [esp+14h] [ebp-4h]

  v6 = pRect;
  v7 = pPixels;
  v8 = (int *)Level;
  if ( pRect )
  {
    D3DK::PixelJar::GetSize(pPixels, Level, (unsigned int *)&pPixels, &Level, &Depth, &Pitch, &Slice);
    if ( v6->bottom > (signed int)Level || v6->right > (signed int)pPixels )
      D3DK::DXGRIP(v8, "PixelJar::Lock2DSurface - Lock rectangle is beyond the bounds of the texture level.");
    if ( v6->top < 0 || v6->left < 0 )
      D3DK::DXGRIP(v8, "PixelJar::Lock2DSurface - Lock rectangle is negative.");
  }
  D3DK::PixelJar::LockSurface(
    (unsigned int)v7,
    (unsigned int)&Level,
    Flags,
    v8,
    FaceType,
    (char **)&pPixels,
    &Level,
    (unsigned int *)&FaceType);
  if ( pRect )
  {
    v9 = (char *)pPixels + Level * pRect->top + (pRect->left * (D3DK::g_TextureFormat[BYTE1(v7->Format)] & 0x3Cu) >> 3);
    v10 = pLockedRect;
    pLockedRect->Pitch = Level;
    v10->pBits = v9;
  }
  else
  {
    v11 = pLockedRect;
    v12 = pPixels;
    pLockedRect->Pitch = Level;
    v11->pBits = v12;
  }
}
D3DCubeTexture *__stdcall CreateNormalizationCubeMap(unsigned int dwSize)
{
  unsigned int v1; // edi
  int v2; // edx
  int v3; // ecx
  unsigned int v4; // ebx
  double v5; // st7
  int v6; // eax
  unsigned int *v7; // ecx
  int v8; // edx
  int v9; // ecx
  _D3DVECTOR n; // [esp+Ch] [ebp-34h]
  _D3DLOCKED_RECT lock; // [esp+18h] [ebp-28h]
  unsigned int v13; // [esp+20h] [ebp-20h]
  D3DCubeTexture *pCubeMap; // [esp+24h] [ebp-1Ch]
  D3DSurface *pCubeMapFace; // [esp+28h] [ebp-18h]
  float v16; // [esp+2Ch] [ebp-14h]
  unsigned int *pSourceBits; // [esp+30h] [ebp-10h]
  unsigned int *pPixel; // [esp+34h] [ebp-Ch]
  unsigned int y; // [esp+38h] [ebp-8h]
  unsigned int i; // [esp+3Ch] [ebp-4h]
  float h; // [esp+48h] [ebp+8h]

  v1 = dwSize;
  D3DDevice_CreateCubeTexture((int *)dwSize, 0, dwSize, 1u, 0, D3DFMT_X8R8G8B8, 0, &pCubeMap);
  pSourceBits = (unsigned int *)MemAllocContiguous(v2, v3, 0, 4 * v1 * v1, 0x80u);
  i = 0;
  do
  {
    D3DCubeTexture_GetCubeMapSurface(pCubeMap, (_D3DCUBEMAP_FACES)i, 0, &pCubeMapFace);
    pPixel = pSourceBits;
    y = 0;
    if ( v1 <= 0 )
      goto LABEL_21;
    v16 = (double)(v1 - 1);
    do
    {
      v4 = 0;
      h = (double)y / v16 + (double)y / v16 - 1.0;
      do
      {
        v13 = v4;
        v5 = (double)v4 / v16 + (double)v4 / v16 - 1.0;
        switch ( i )
        {
          case 0u:
            n.x = 1.0;
            n.y = -h;
LABEL_17:
            v5 = -v5;
LABEL_18:
            n.z = v5;
            break;
          case 1u:
            n.x = -1.0;
            n.y = -h;
            goto LABEL_18;
          case 2u:
            n.x = v5;
            n.z = h;
            n.y = 1.0;
            break;
          case 3u:
            n.x = v5;
            n.y = -1.0;
            v5 = h;
            goto LABEL_17;
          case 4u:
            n.x = v5;
            n.y = -h;
            v5 = 1.0;
            goto LABEL_18;
          case 5u:
            n.z = -1.0;
            n.x = -v5;
            n.y = -h;
            break;
        }
        Normalize(&n);
        v6 = VectorToRGBA(&n);
        v7 = pPixel;
        ++pPixel;
        ++v4;
        *v7 = v6;
      }
      while ( v4 < v1 );
      ++y;
    }
    while ( y < v1 );
LABEL_21:
    D3DSurface_LockRect((int *)v1, pCubeMapFace, &lock, 0, 0);
    XGSwizzleRect(pSourceBits, 0, 0, lock.pBits, v1, v1, 0, 4u);
    D3DResource_Release((int *)v1, (D3DResource *)&pCubeMapFace->Common);
    ++i;
  }
  while ( i < 6 );
  MemFreeContiguous(v8, v9, (int *)v1, pSourceBits);
  return pCubeMap;
}
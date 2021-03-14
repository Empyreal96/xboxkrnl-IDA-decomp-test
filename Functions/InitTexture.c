int __userpurge InitTexture@<eax>(int *a1@<edi>, int a2@<esi>, D3DDevice *pDev)
{
  char *v4; // edx
  unsigned int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  int v9; // eax
  unsigned int v10; // ecx
  int *v11; // edi
  unsigned int v12; // eax
  int v13; // eax
  int *v14; // edi
  int *v15; // [esp-8h] [ebp-28h]
  _D3DLOCKED_RECT lock; // [esp+4h] [ebp-1Ch]
  D3DTexture *pTex; // [esp+Ch] [ebp-14h]
  unsigned int v18; // [esp+10h] [ebp-10h]
  unsigned int dwLine; // [esp+14h] [ebp-Ch]
  unsigned int x; // [esp+18h] [ebp-8h]
  unsigned int dwAddr; // [esp+1Ch] [ebp-4h]

  x = 0;
  if ( D3DDevice_CreateTexture(a1, a2, 0x140u, 0xF0u, 1u, 0, D3DFMT_LIN_X8R8G8B8, 0, &pTex) < 0 )
    return 0;
  D3DTexture_LockRect(pTex, 0, &lock, 0, 0);
  v4 = (char *)lock.pBits;
  dwLine = (unsigned int)lock.pBits;
  dwAddr = (unsigned int)lock.pBits;
  v5 = 0;
  v15 = a1;
  do
  {
    v6 = *(_DWORD *)&g_Image[v5];
    v7 = *(_DWORD *)&g_Image[v5];
    if ( v6 & 1 )
    {
      v8 = (v7 >> 1) & 7;
      v9 = (unsigned __int8)v6 >> 4;
      ++v5;
    }
    else
    {
      v10 = v7 >> 2;
      if ( v6 & 2 )
      {
        v8 = v10 & 0x3FF;
        v9 = (unsigned __int16)v6 >> 12;
        v5 += 2;
      }
      else
      {
        v8 = v10 & 0x3FFFF;
        v9 = (v6 >> 20) & 0xF;
        v5 += 3;
      }
    }
    v11 = (int *)v9;
    if ( v8 > 0 )
    {
      v18 = v8;
      do
      {
        if ( v11 )
        {
          v12 = ColorFromIntensity((unsigned int)v11);
          v4 = (char *)dwLine;
          *(_DWORD *)dwAddr = v12;
        }
        else
        {
          *(_DWORD *)dwAddr = -16777216;
        }
        if ( ++x < 0x140 )
        {
          dwAddr += 4;
        }
        else
        {
          v4 += lock.Pitch;
          x = 0;
          dwLine = (unsigned int)v4;
          dwAddr = (unsigned int)v4;
        }
        --v18;
      }
      while ( v18 );
    }
  }
  while ( v5 < 0x1E9B );
  D3DDevice_SetTexture(0, (D3DBaseTexture *)&pTex->Common);
  v13 = D3DDevice_SetTextureState_ParameterCheck(v11, 0, D3DTSS_ADDRESSU, 3u);
  v14 = v15;
  if ( !v13 )
    D3DDevice_SetTextureState_Deferred(0, 0, 10, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(v14, 0, D3DTSS_ADDRESSV, 3u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 11, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(v14, 0, D3DTSS_MINFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 14, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(v14, 0, D3DTSS_MAGFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 13, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(v14, 0, 0, 2u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 0, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(v14, 0, D3DTSS_ALPHAOP, 1u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 4, 1u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(v14, 0, D3DTSS_COLORARG1, 2u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 2, 2u);
  return 1;
}
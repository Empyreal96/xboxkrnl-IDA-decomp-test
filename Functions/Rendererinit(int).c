// write access to const memory has been detected, the output may be wrong!
char __userpurge Renderer::init@<al>(Renderer *this@<ecx>, int *a2@<edi>, int width, int height)
{
  Renderer *v4; // esi
  Direct3D *v5; // eax
  signed int v7; // ebx
  signed int v8; // esi
  unsigned int AvInfo; // [esp+14h] [ebp-4h]

  v4 = this;
  v5 = Direct3DCreate8(a2, 0);
  v4->pD3D8 = v5;
  if ( !v5 )
    return 0;
  Direct3D_SetPushBufferSize(a2, 0x100000u, 0x10000u);
  memset(&v4->d3dPresentParams, 0, sizeof(v4->d3dPresentParams));
  v4->d3dPresentParams.BackBufferWidth = width;
  v4->d3dPresentParams.BackBufferHeight = height;
  v4->d3dPresentParams.BackBufferFormat = 6;
  v4->d3dPresentParams.BackBufferCount = 1;
  v4->d3dPresentParams.EnableAutoDepthStencil = 1;
  v4->d3dPresentParams.AutoDepthStencilFormat = 42;
  v4->d3dPresentParams.SwapEffect = 1;
  v4->d3dPresentParams.MultiSampleType = 8225;
  if ( byte_8010CEDE[0] )
    v4->d3dPresentParams.Flags |= 0x10u;
  AvSendTVEncoderOption(0, 6u, 0, &AvInfo);
  if ( (_BYTE)AvInfo == 4 )
    v4->d3dPresentParams.Flags |= 0x20u;
  if ( Direct3D_CreateDevice((int *)1, 0, D3DDEVTYPE_HAL, 0, 0x40u, &v4->d3dPresentParams, &v4->pD3DDev8) )
    return 0;
  v7 = 0;
  do
  {
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, v7, D3DTSS_MINFILTER, 2u) )
      D3DDevice_SetTextureState_Deferred(0, (_D3DTEXTURESTAGESTATETYPE)v7, 14, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, v7, D3DTSS_MAGFILTER, 2u) )
      D3DDevice_SetTextureState_Deferred(0, (_D3DTEXTURESTAGESTATETYPE)v7, 13, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, v7, D3DTSS_MIPFILTER, 0) )
      D3DDevice_SetTextureState_Deferred(0, (_D3DTEXTURESTAGESTATETYPE)v7, 15, 0);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, v7, D3DTSS_ADDRESSU, 3u) )
      D3DDevice_SetTextureState_Deferred(0, (_D3DTEXTURESTAGESTATETYPE)v7, 10, 3u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, v7, D3DTSS_ADDRESSV, 3u) )
      D3DDevice_SetTextureState_Deferred(0, (_D3DTEXTURESTAGESTATETYPE)v7, 11, 3u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, v7, D3DTSS_ADDRESSW, 3u) )
      D3DDevice_SetTextureState_Deferred(0, (_D3DTEXTURESTAGESTATETYPE)v7, 12, 3u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, v7, D3DTSS_MAXANISOTROPY, 4u) )
      D3DDevice_SetTextureState_Deferred(0, (_D3DTEXTURESTAGESTATETYPE)v7, 18, 4u);
    ++v7;
  }
  while ( v7 < 4 );
  gpd3dDev = v4->pD3DDev8;
  D3DDevice_Clear(0, 0, 0xF3u, 0, 1.0, 0);
  D3DDevice_Present(0, 0, 0, 0);
  v8 = 4;
  do
  {
    D3DDevice_BlockUntilVerticalBlank();
    --v8;
  }
  while ( v8 );
  return 1;
}
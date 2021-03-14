D3DCubeTexture *__stdcall CreateStaticReflectionCubeMap(unsigned int dwSize)
{
  D3DCubeTexture *result; // eax
  Camera old_camera; // [esp+1Ch] [ebp-1DCh]
  _D3DMATRIX viewMat; // [esp+198h] [ebp-60h]
  _D3DVECTOR pos; // [esp+1D8h] [ebp-20h]
  D3DSurface *pOldZ; // [esp+1E4h] [ebp-14h]
  D3DSurface *pNewRT; // [esp+1E8h] [ebp-10h]
  D3DSurface *pOldRT; // [esp+1ECh] [ebp-Ch]
  D3DCubeTexture *pCubeMap; // [esp+1F0h] [ebp-8h]
  D3DSurface *pNewZ; // [esp+1F4h] [ebp-4h]
  _D3DCUBEMAP_FACES dwFace; // [esp+200h] [ebp+8h]

  qmemcpy(&old_camera, &dword_8010BDA8, sizeof(old_camera));
  D3DDevice_CreateCubeTexture(
    (int *)&viewMat,
    (int)(&dword_8010BDA8 + 1),
    dwSize,
    1u,
    1u,
    D3DFMT_A8R8G8B8,
    0,
    &pCubeMap);
  D3DDevice_GetRenderTarget((int *)&viewMat, &pOldRT);
  D3DDevice_GetDepthStencilSurface((int *)&viewMat, &pOldZ);
  D3DDevice_CreateDepthStencilSurface((int *)&viewMat, dwSize, dwSize, D3DFMT_LIN_D24S8, 0x1021u, &pNewZ);
  Camera::setProjection(&dword_8010BDA8, 1.5707964, 1.0, 0.1, 400.0);
  pos.x = 0.0;
  dwFace = 0;
  pos.y = 0.0;
  pos.z = 0.0;
  do
  {
    D3DCubeTexture_GetCubeMapSurface(pCubeMap, dwFace, 0, &pNewRT);
    D3DDevice_SetRenderTarget(pNewRT, pNewZ);
    D3DDevice_Clear(0, 0, 0xF3u, 0xFF000000, 1.0, 0);
    SetCubeMapView(dwFace, &pos, &viewMat);
    Camera::setWTC(&dword_8010BDA8, &viewMat);
    SceneRenderer::advanceTime(&dword_8010C028, 5.3499999, 0.0);
    SceneRenderer::render(&dword_8010C028, 0, 0);
    D3DResource_Release((int *)&dword_8010C028, (D3DResource *)&pNewRT->Common);
    ++dwFace;
  }
  while ( (unsigned int)dwFace < 6 );
  D3DDevice_SetRenderTarget(pOldRT, pOldZ);
  D3DResource_Release((int *)&dword_8010C028, (D3DResource *)&pOldRT->Common);
  D3DResource_Release((int *)&dword_8010C028, (D3DResource *)&pOldZ->Common);
  D3DResource_Release((int *)&dword_8010C028, (D3DResource *)&pNewZ->Common);
  result = pCubeMap;
  qmemcpy(&dword_8010BDA8, &old_camera, sizeof(dword_8010BDA8));
  return result;
}
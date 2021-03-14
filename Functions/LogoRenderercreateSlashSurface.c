void __thiscall LogoRenderer::createSlashSurface(LogoRenderer *this)
{
  LogoRenderer *v1; // edi
  D3DTexture **v2; // ebx
  D3DSurface *v3; // ST18_4
  D3DSurface *pOldZ; // [esp+14h] [ebp-18h]
  D3DSurface *pOldRT; // [esp+18h] [ebp-14h]
  D3DSurface *pSlashDepthBuf; // [esp+1Ch] [ebp-10h]
  D3DSurface *p_tex_surf; // [esp+20h] [ebp-Ch]
  D3DSurface *pSlashSurface; // [esp+24h] [ebp-8h]
  bool b_old_render_text; // [esp+2Ah] [ebp-2h]
  bool b_want_wordmark; // [esp+2Bh] [ebp-1h]

  v1 = this;
  b_want_wordmark = 1;
  if ( 0.0 < 6.25 )
    b_want_wordmark = 0;
  v2 = &this->pSlashTexture;
  if ( !this->pSlashTexture || b_want_wordmark != this->bHasWordmark )
  {
    D3DDevice_CreateRenderTarget((int *)this, 0x400u, 0x400u, D3DFMT_A8R8G8B8, 0x1021u, 1, &pSlashSurface);
    D3DDevice_CreateDepthStencilSurface((int *)v1, 0x400u, 0x400u, D3DFMT_LIN_D24S8, 0x1021u, &pSlashDepthBuf);
    if ( !*v2 )
      D3DDevice_CreateTexture((int *)v1, 1024, 0x400u, 0x400u, 1u, 0, D3DFMT_A8R8G8B8, 0, &v1->pSlashTexture);
    D3DDevice_GetRenderTarget((int *)v1, &pOldRT);
    D3DDevice_GetDepthStencilSurface((int *)v1, &pOldZ);
    D3DDevice_SetRenderTarget(pSlashSurface, pSlashDepthBuf);
    D3DDevice_Clear(0, 0, 0xF3u, 0xFF000000, 1.0, 0);
    b_old_render_text = v1->bRenderText;
    v1->bRenderText = b_want_wordmark;
    LogoRenderer::render(v1, (int *)v1, &mat_otw, 1);
    v1->bRenderText = b_old_render_text;
    D3DTexture_GetSurfaceLevel(*v2, 0, &p_tex_surf);
    D3DDevice_CopyRects(pSlashSurface, 0, 0, p_tex_surf, 0);
    D3DResource_Release((int *)v1, (D3DResource *)&p_tex_surf->Common);
    v3 = pSlashSurface;
    v1->bHasWordmark = b_want_wordmark;
    D3DResource_Release((int *)v1, (D3DResource *)&v3->Common);
    D3DResource_Release((int *)v1, (D3DResource *)&pSlashDepthBuf->Common);
    D3DDevice_SetRenderTarget(pOldRT, pOldZ);
    D3DResource_Release((int *)v1, (D3DResource *)&pOldRT->Common);
    D3DResource_Release((int *)v1, (D3DResource *)&pOldZ->Common);
  }
}
void __thiscall LogoRenderer::createTMs(LogoRenderer *this)
{
  LogoRenderer *v1; // ebx
  unsigned __int16 *v2; // eax
  D3DVertexBuffer **v3; // esi
  unsigned __int16 *v4; // eax
  _D3DLOCKED_RECT rc; // [esp+Ch] [ebp-Ch]
  xbl_vertex *pv; // [esp+14h] [ebp-4h]

  v1 = this;
  v2 = this->indices_tm_slash_0;
  v3 = &this->pSlashTM_VB;
  this->nSlashTM_Verts = 4;
  this->nSlashTM_Indices = 6;
  this->pSlashTM_Indices = v2;
  D3DDevice_CreateVertexBuffer(0, (int)this, (int)&this->pSlashTM_VB, 0x50u, 0, 0x102u, 0, &this->pSlashTM_VB);
  D3DVertexBuffer_Lock(0, *v3, 0, 0, (char **)&pv, 0);
  qmemcpy(pv, v1->verts_tm_slash_0, 20 * v1->nSlashTM_Verts);
  v4 = v1->indices_tm_wordmark_0;
  v1->nTextTM_Verts = 4;
  v1->nTextTM_Indices = 6;
  v1->pTextTM_Indices = v4;
  D3DDevice_CreateVertexBuffer(0, 0, (int)&v1->pTextTM_VB, 0x50u, 0, 0x102u, 0, &v1->pTextTM_VB);
  D3DVertexBuffer_Lock(0, v1->pTextTM_VB, 0, 0, (char **)&pv, 0);
  qmemcpy(pv, v1->verts_tm_wordmark_0, 20 * v1->nTextTM_Verts);
  D3DDevice_CreateTexture(0, (int)&v1->pTMTex, 0x10u, 0x10u, 1u, 0, D3DFMT_A8R8G8B8, 0, &v1->pTMTex);
  D3DTexture_LockRect(v1->pTMTex, 0, &rc, 0, 0);
  XGSwizzleRect(tm_pixels, 0, 0, rc.pBits, 0x10u, 0x10u, 0, 4u);
  v1->fTMAlpha = 0.0;
}
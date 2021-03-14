void __thiscall LogoRenderer::createText(LogoRenderer *this)
{
  LogoRenderer *v1; // ebx
  unsigned __int16 *v2; // eax
  D3DVertexBuffer **v3; // esi
  xbt_vertex *pv; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = this->indices_text_0;
  v3 = &this->pText_VB;
  this->nText_Verts = 156;
  this->nText_Indices = 462;
  this->pText_Indices = v2;
  D3DDevice_CreateVertexBuffer(0, (int)this, (int)&this->pText_VB, 0x750u, 0, 2u, 0, &this->pText_VB);
  D3DVertexBuffer_Lock(0, *v3, 0, 0, (char **)&pv, 0);
  qmemcpy(pv, v1->verts_text_0, 12 * v1->nText_Verts);
  SetIdentity(&v1->matText_Anim);
  v1->bRenderText = 0;
}
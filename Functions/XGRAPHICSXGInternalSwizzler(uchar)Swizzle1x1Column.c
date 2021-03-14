void __stdcall XGRAPHICS::XGInternalSwizzler<unsigned char>::Swizzle1x1Column(XGRAPHICS::XGINTERNALSWIZZLE *ps)
{
  XGRAPHICS::XGINTERNALSWIZZLE *v1; // esi
  int v2; // ebx
  Swizzler *v3; // edi
  unsigned int v4; // eax
  char *v5; // ecx
  int v6; // edx
  int v7; // ecx
  _BYTE *v8; // eax
  unsigned int SwizUa; // [esp+14h] [ebp+8h]
  unsigned int SwizU; // [esp+14h] [ebp+8h]

  v1 = ps;
  v2 = ps->xOff;
  v3 = &ps->swiz;
  SwizUa = Swizzler::SwizzleU(&ps->swiz, v2 + ps->DLeft);
  v4 = Swizzler::SwizzleV(v3, v1->yOff + v1->DTop);
  v5 = (char *)v1->pDest;
  v6 = v1->uHeight;
  v1->swiz.m_u = 0;
  v7 = (int)&v5[SwizUa];
  v1->swiz.m_v = v4;
  v8 = (char *)v1->pSource + v2 + v1->SLeft + v1->Pitch * (v1->yOff + v1->STop);
  if ( v6 )
  {
    SwizU = v6;
    do
    {
      *(_BYTE *)(v7 + v1->swiz.m_v) = *v8;
      v3->m_v = v3->m_MaskV & (v3->m_v - v3->m_MaskV);
      v8 += v1->Pitch;
      --SwizU;
    }
    while ( SwizU );
  }
}
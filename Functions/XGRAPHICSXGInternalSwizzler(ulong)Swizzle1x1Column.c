void __stdcall XGRAPHICS::XGInternalSwizzler<unsigned long>::Swizzle1x1Column(XGRAPHICS::XGINTERNALSWIZZLE *ps)
{
  XGRAPHICS::XGINTERNALSWIZZLE *v1; // esi
  int v2; // ebx
  Swizzler *v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // ecx
  _DWORD *v6; // eax
  int v7; // ecx
  unsigned int SwizUa; // [esp+14h] [ebp+8h]
  unsigned int SwizU; // [esp+14h] [ebp+8h]

  v1 = ps;
  v2 = ps->xOff;
  v3 = &ps->swiz;
  SwizUa = Swizzler::SwizzleU(&ps->swiz, v2 + ps->DLeft);
  v4 = Swizzler::SwizzleV(v3, v1->yOff + v1->DTop);
  v5 = v1->SLeft;
  v1->swiz.m_u = 0;
  v1->swiz.m_v = v4;
  v6 = (char *)v1->pSource + 4 * (v2 + v5) + v1->Pitch * (v1->yOff + v1->STop);
  v7 = (int)v1->pDest + 4 * SwizUa;
  if ( v1->uHeight )
  {
    SwizU = v1->uHeight;
    do
    {
      *(_DWORD *)(v7 + 4 * v1->swiz.m_v) = *v6;
      v3->m_v = v3->m_MaskV & (v3->m_v - v3->m_MaskV);
      v6 = (_DWORD *)((char *)v6 + v1->Pitch);
      --SwizU;
    }
    while ( SwizU );
  }
}
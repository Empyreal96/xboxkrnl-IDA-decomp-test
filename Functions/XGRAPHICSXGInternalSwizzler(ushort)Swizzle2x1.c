void __stdcall XGRAPHICS::XGInternalSwizzler<unsigned short>::Swizzle2x1(XGRAPHICS::XGINTERNALSWIZZLE *ps)
{
  XGRAPHICS::XGINTERNALSWIZZLE *v1; // esi
  unsigned int v2; // ebx
  unsigned int v3; // edi
  unsigned int v4; // ST00_4
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // edx
  _WORD *v8; // ecx
  _WORD *v9; // edi
  int v10; // eax
  bool v11; // zf
  int v12; // [esp+Ch] [ebp-8h]
  int v13; // [esp+10h] [ebp-4h]
  unsigned int SwizUa; // [esp+1Ch] [ebp+8h]
  unsigned int SwizU; // [esp+1Ch] [ebp+8h]

  v1 = ps;
  v2 = ps->swiz.m_MaskV;
  v3 = ps->swiz.m_MaskU;
  v4 = ps->xOff + ps->DLeft;
  ps->mask[0] = v3;
  ps->mask[1] = v2;
  SwizUa = Swizzler::SwizzleU(&ps->swiz, v4);
  v5 = Swizzler::SwizzleV(&v1->swiz, v1->yOff + v1->DTop);
  v6 = v1->yOff + v1->STop;
  SwizU = SwizUa >> 1;
  v1->swiz.m_MaskU = v3 >> 1;
  v7 = v1->Pitch - v1->uWidth;
  v8 = (char *)v1->pSource + v1->xOff + v1->SLeft + v1->Pitch * v6;
  v9 = v1->pDest;
  v1->swiz.m_v = v5 >> 1;
  v10 = v1->uHeight;
  v1->swiz.m_MaskV = v2 >> 1;
  if ( v10 )
  {
    v12 = v10;
    do
    {
      v1->swiz.m_u = SwizU;
      if ( v1->uWidth >> 1 )
      {
        v13 = v1->uWidth >> 1;
        do
        {
          v9[v1->swiz.m_u | v1->swiz.m_v] = *v8;
          ++v8;
          v11 = v13-- == 1;
          v1->swiz.m_u = v1->swiz.m_MaskU & (v1->swiz.m_u - v1->swiz.m_MaskU);
        }
        while ( !v11 );
      }
      v8 = (_WORD *)((char *)v8 + v7);
      v11 = v12-- == 1;
      v1->swiz.m_v = v1->swiz.m_MaskV & (v1->swiz.m_v - v1->swiz.m_MaskV);
    }
    while ( !v11 );
  }
  v1->swiz.m_MaskU = v1->mask[0];
  v1->swiz.m_MaskV = v1->mask[1];
}
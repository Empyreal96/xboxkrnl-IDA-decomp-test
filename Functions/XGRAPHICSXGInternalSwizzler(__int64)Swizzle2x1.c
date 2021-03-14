void __stdcall XGRAPHICS::XGInternalSwizzler<__int64>::Swizzle2x1(XGRAPHICS::XGINTERNALSWIZZLE *ps)
{
  XGRAPHICS::XGINTERNALSWIZZLE *v1; // esi
  unsigned int v2; // ebx
  unsigned int v3; // edi
  unsigned int v4; // ST00_4
  unsigned int v5; // eax
  int v6; // edx
  unsigned int v7; // ecx
  int v8; // edx
  int v9; // edi
  int v10; // ecx
  int v11; // eax
  _DWORD *v12; // ecx
  _DWORD *v13; // edi
  int v14; // eax
  bool v15; // zf
  int v16; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h]
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
  v6 = v1->uWidth;
  v7 = v1->Pitch;
  SwizU = SwizUa >> 1;
  v1->swiz.m_MaskU = v3 >> 1;
  v8 = v7 - 4 * v6;
  v9 = v7 * (v1->yOff + v1->STop);
  v10 = v1->xOff + v1->SLeft;
  v1->swiz.m_v = v5 >> 1;
  v11 = v1->uHeight;
  v12 = (char *)v1->pSource + 4 * v10 + v9;
  v13 = v1->pDest;
  v1->swiz.m_MaskV = v2 >> 1;
  if ( v11 )
  {
    v16 = v11;
    do
    {
      v1->swiz.m_u = SwizU;
      if ( v1->uWidth >> 1 )
      {
        v17 = v1->uWidth >> 1;
        do
        {
          v14 = v1->swiz.m_u | v1->swiz.m_v;
          v13[2 * v14] = *v12;
          v13[2 * v14 + 1] = v12[1];
          v12 += 2;
          v15 = v17-- == 1;
          v1->swiz.m_u = v1->swiz.m_MaskU & (v1->swiz.m_u - v1->swiz.m_MaskU);
        }
        while ( !v15 );
      }
      v12 = (_DWORD *)((char *)v12 + v8);
      v15 = v16-- == 1;
      v1->swiz.m_v = v1->swiz.m_MaskV & (v1->swiz.m_v - v1->swiz.m_MaskV);
    }
    while ( !v15 );
  }
  v1->swiz.m_MaskU = v1->mask[0];
  v1->swiz.m_MaskV = v1->mask[1];
}
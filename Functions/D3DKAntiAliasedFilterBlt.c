unsigned int *__stdcall D3DK::AntiAliasedFilterBlt(unsigned int *pPush, unsigned int xScale, unsigned int yScale, tagRECT *DstRect)
{
  D3DSurface *v4; // edx
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // esi
  unsigned int v8; // ebx
  int v9; // ebx
  double v10; // st6
  double v11; // st5
  double v12; // st4
  double v13; // st4
  unsigned int top; // [esp+10h] [ebp-Ch]
  unsigned int left; // [esp+14h] [ebp-8h]
  int right; // [esp+18h] [ebp-4h]
  float DstRecta; // [esp+30h] [ebp+14h]

  v4 = D3DK::g_pDevice->m_pRenderTarget;
  v5 = v4->Size;
  left = 0;
  top = 0;
  if ( v5 )
  {
    right = (v4->Size & 0xFFF) + 1;
    v7 = (v4->Size & 0xFFF) + 1;
  }
  else
  {
    v6 = (v4->Format >> 20) & 0xF;
    v7 = 1 << v6;
    right = 1 << v6;
  }
  v8 = v4->Size;
  if ( v8 )
    v9 = ((v8 >> 12) & 0xFFF) + 1;
  else
    v9 = 1 << (HIBYTE(v4->Format) & 0xF);
  if ( DstRect )
  {
    if ( DstRect->left >= 0 )
      left = DstRect->left;
    if ( v7 >= DstRect->right )
    {
      right = DstRect->right;
      v7 = DstRect->right;
    }
    if ( DstRect->top >= 0 )
      top = DstRect->top;
    if ( v9 >= DstRect->bottom )
      v9 = DstRect->bottom;
  }
  if ( left >= v7 || top >= v9 )
    return pPush;
  XMETAL_PushCount(0, pPush, 0x1760u, 0x10u);
  memset32(pPush + 1, 2, 0x10u);
  XMETAL_Push1f((int *)pPush + 17, pPush + 17, 0x1760u, COERCE_FLOAT(34));
  XMETAL_Push1f((int *)pPush + 17, pPush + 19, 0x1784u, COERCE_FLOAT(34));
  XMETAL_Push1f((int *)pPush + 17, pPush + 21, 0x17FCu, COERCE_FLOAT(5));
  XMETAL_PushCount((int *)pPush + 17, pPush + 23, 0x40001818u, 0xCu);
  v10 = (double)left;
  *((float *)pPush + 24) = v10 - 0.53125;
  v11 = (double)top;
  *((float *)pPush + 25) = v11 - 0.53125;
  v12 = (double)(xScale * left);
  DstRecta = v12;
  *((float *)pPush + 26) = v12 + 0.0;
  v13 = (double)(yScale * top);
  *((float *)pPush + 27) = v13 + 0.0;
  *((float *)pPush + 28) = (double)(unsigned int)right * 4.0 - 0.53125;
  *((float *)pPush + 29) = v11 * 4.0 - 0.53125;
  *((float *)pPush + 30) = (double)(xScale * right) * 4.0 + 0.0;
  *((float *)pPush + 31) = v13 * 4.0 + 0.0;
  *((float *)pPush + 32) = v10 * 4.0 - 0.53125;
  *((float *)pPush + 33) = (double)(unsigned int)v9 * 4.0 - 0.53125;
  *((float *)pPush + 34) = DstRecta * 4.0 + 0.0;
  *((float *)pPush + 35) = (double)(yScale * v9) * 4.0 + 0.0;
  XMETAL_Push1f((int *)xScale, pPush + 36, 0x17FCu, 0.0);
  D3DK::g_pDevice->m_DirtyFlags |= 0x7FFu;
  return pPush + 38;
}
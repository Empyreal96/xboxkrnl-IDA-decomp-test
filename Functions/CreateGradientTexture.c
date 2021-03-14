D3DTexture *__stdcall CreateGradientTexture(unsigned int dwWidth, unsigned int dwHeight, unsigned int dwClrStart, unsigned int dwClrEnd)
{
  unsigned int v4; // esi
  unsigned int v5; // edi
  int v6; // edx
  int v7; // ecx
  double v8; // st6
  int v9; // edx
  int v10; // ecx
  float cv_end; // [esp+Ch] [ebp-44h]
  float cv_end_4; // [esp+10h] [ebp-40h]
  float cv_end_8; // [esp+14h] [ebp-3Ch]
  float cv_end_12; // [esp+18h] [ebp-38h]
  float cv_start; // [esp+1Ch] [ebp-34h]
  float cv_start_4; // [esp+20h] [ebp-30h]
  float cv_start_8; // [esp+24h] [ebp-2Ch]
  float cv_start_12; // [esp+28h] [ebp-28h]
  _D3DLOCKED_RECT rc; // [esp+2Ch] [ebp-24h]
  unsigned int color; // [esp+34h] [ebp-1Ch]
  float _a; // [esp+38h] [ebp-18h]
  float _r; // [esp+3Ch] [ebp-14h]
  float _g; // [esp+40h] [ebp-10h]
  float _b; // [esp+44h] [ebp-Ch]
  unsigned int *pSourceBits; // [esp+48h] [ebp-8h]
  D3DTexture *pTex; // [esp+4Ch] [ebp-4h]
  unsigned int r; // [esp+5Ch] [ebp+Ch]
  unsigned int *dwClrStarta; // [esp+60h] [ebp+10h]
  float del; // [esp+64h] [ebp+14h]

  v4 = dwHeight;
  v5 = dwWidth;
  pTex = 0;
  D3DDevice_CreateTexture((int *)dwWidth, dwHeight, dwWidth, dwHeight, 1u, 0, D3DFMT_A8R8G8B8, 0, &pTex);
  pSourceBits = (unsigned int *)MemAllocContiguous(v6, v7, v4, 4 * v4 * dwWidth, 0x80u);
  cv_start_12 = (double)(dwClrStart >> 24) * 0.0039215689;
  cv_start = (double)((dwClrStart >> 16) & 0xFF) * 0.0039215689;
  cv_start_4 = (double)((unsigned __int16)dwClrStart >> 8) * 0.0039215689;
  cv_start_8 = (double)(unsigned __int8)dwClrStart * 0.0039215689;
  cv_end_12 = (double)(dwClrEnd >> 24) * 0.0039215689;
  cv_end = (double)((dwClrEnd >> 16) & 0xFF) * 0.0039215689;
  cv_end_4 = (double)((unsigned __int16)dwClrEnd >> 8) * 0.0039215689;
  cv_end_8 = (double)(unsigned __int8)dwClrEnd * 0.0039215689;
  r = 0;
  if ( v4 > 0 )
  {
    dwClrStarta = pSourceBits;
    do
    {
      del = 1.0 / (double)(v4 - 1);
      v8 = (double)r * del;
      _r = (cv_start * (1.0 - v8) + v8 * cv_end) * 255.0;
      _g = (cv_start_4 * (1.0 - v8) + v8 * cv_end_4) * 255.0;
      _b = (cv_start_8 * (1.0 - v8) + v8 * cv_end_8) * 255.0;
      _a = ((1.0 - v8) * cv_start_12 + v8 * cv_end_12) * 255.0;
      color = ((signed int)_a << 24) | ((signed int)_r << 16) | ((signed int)_g << 8) | (signed int)_b;
      if ( v5 )
      {
        memset32(dwClrStarta, color, v5);
        v5 = dwWidth;
      }
      ++r;
      dwClrStarta += v5;
    }
    while ( r < v4 );
  }
  D3DTexture_LockRect(pTex, 0, &rc, 0, 0);
  XGSwizzleRect(pSourceBits, 0, 0, rc.pBits, v5, v4, 0, 4u);
  MemFreeContiguous(v9, v10, (int *)v5, pSourceBits);
  return pTex;
}
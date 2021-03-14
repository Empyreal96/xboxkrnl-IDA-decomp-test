// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetScissors(unsigned int Count, int Exclusive, _D3DRECT *pRects)
{
  D3DK::CDevice *v3; // ebx
  unsigned int v4; // edi
  bool v5; // zf
  int *v6; // esi
  int v7; // ecx
  int *v8; // edi
  signed int v9; // eax
  signed int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  unsigned int *v14; // esi
  float v15; // ecx
  unsigned int *v16; // esi
  int *v17; // edi
  unsigned int v18; // ebx
  float f; // ST08_4
  float v20; // ST08_4
  int v21; // eax
  float v22; // ST08_4
  float v23; // ST08_4
  int v24; // eax
  _D3DRECT rect; // [esp+10h] [ebp-28h]
  D3DK::CDevice *pDevice; // [esp+20h] [ebp-18h]
  float v27; // [esp+24h] [ebp-14h]
  float v28; // [esp+28h] [ebp-10h]
  unsigned int v29; // [esp+2Ch] [ebp-Ch]
  float yScale; // [esp+30h] [ebp-8h]
  float xScale; // [esp+34h] [ebp-4h]

  v3 = D3DK::g_pDevice;
  v4 = Count;
  ++D3DK::g_PerfCounters.m_APICounters[159];
  pDevice = D3DK::g_pDevice;
  if ( Count >= 8 )
    D3DK::DXGRIP((int *)Count, "Count can't be more than D3DSCISSORS_MAX (8)");
  if ( Exclusive > 1 )
    D3DK::DXGRIP((int *)Count, "Invalid Exclusive value");
  if ( !pRects )
  {
    v5 = Count == 0;
    if ( *(float *)&Count == 0.0 )
      goto LABEL_19;
    D3DK::DXGRIP((int *)Count, "pRects can be NULL only if Count is zero");
  }
  v5 = Count == 0;
  if ( *(float *)&Count != 0.0 )
  {
    v6 = &pRects->x2;
    xScale = *(float *)&Count;
    do
    {
      v7 = *(v6 - 2);
      v8 = (int *)*v6;
      if ( v7 >= *v6
        || (v9 = *(v6 - 1), v10 = v6[1], v9 >= v10)
        || v7 < 0
        || v9 < 0
        || (signed int)v8 > 4095
        || v10 > 4095 )
      {
        D3DK::DXGRIP(v8, "Rectangle dimension invalid or out of range");
      }
      v6 += 4;
      --LODWORD(xScale);
    }
    while ( xScale != 0.0 );
    v4 = Count;
    v5 = Count == 0;
  }
LABEL_19:
  if ( v5 )
  {
    v11 = D3DK::g_pDevice->m_Viewport.Y;
    v12 = D3DK::g_pDevice->m_Viewport.X + D3DK::g_pDevice->m_Viewport.Width;
    rect.x1 = D3DK::g_pDevice->m_Viewport.X;
    v13 = v11 + D3DK::g_pDevice->m_Viewport.Height;
    rect.y1 = v11;
    Count = 1;
    v4 = 1;
    rect.x2 = v12;
    rect.y2 = v13;
    Exclusive = 0;
    pRects = &rect;
  }
  v14 = XMETAL_StartPush((int *)v4, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f((int *)v4, v14, 0x2B4u, *(float *)&Exclusive);
  v15 = D3DK::g_pDevice->m_SuperSampleScaleY;
  v16 = v14 + 2;
  xScale = D3DK::g_pDevice->m_SuperSampleScaleX;
  yScale = v15;
  if ( v4 )
  {
    v17 = &pRects->y1;
    v18 = 736;
    v29 = Count;
    do
    {
      v28 = (double)*(v17 - 1) * xScale;
      f = (double)v17[1] * xScale + 0.5;
      v27 = COERCE_FLOAT(D3DK::FloatToLong(f));
      v20 = v28 + 0.5;
      v21 = D3DK::FloatToLong(v20);
      XMETAL_Push1f(v17, v16, v18 - 32, COERCE_FLOAT(((LODWORD(v27) - 1) << 16) | v21));
      v27 = (double)*v17 * yScale;
      v22 = (double)v17[2] * yScale + 0.5;
      v28 = COERCE_FLOAT(D3DK::FloatToLong(v22));
      v23 = v27 + 0.5;
      v24 = D3DK::FloatToLong(v23);
      XMETAL_Push1f(v17, v16 + 2, v18, COERCE_FLOAT(((LODWORD(v28) - 1) << 16) | v24));
      v16 += 4;
      v18 += 4;
      v17 += 4;
      --v29;
    }
    while ( v29 );
    v3 = pDevice;
    v4 = Count;
  }
  XMETAL_EndPush((int *)v4, &v3->m_Pusher, v16);
  qmemcpy(v3->m_ScissorsRects, pRects, 16 * v4);
  v3->m_ScissorsCount = Count;
  v3->m_ScissorsExclusive = Exclusive;
}
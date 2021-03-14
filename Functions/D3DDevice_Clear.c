// local variable allocation has failed, the output may be wrong!
// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_Clear(unsigned int Count, _D3DRECT *pRects, unsigned int Flags, unsigned int Color, float Z, unsigned int Stencil)
{
  D3DSurface *v6; // eax
  D3DSurface *v7; // esi
  bool v8; // zf
  D3DSurface *v9; // ebx
  unsigned int v10; // eax
  signed int v11; // ebx
  char v12; // cl
  int v13; // edx
  unsigned int *v14; // ebx
  char v15; // cl
  unsigned int v16; // eax
  float f; // ST08_4
  int v18; // eax
  float v19; // ST08_4
  int v20; // eax
  int v21; // ebx
  int v22; // eax
  int v23; // ecx
  signed int v24; // edx
  _D3DRECT *v25; // esi
  int v26; // ebx
  int v27; // eax
  float v28; // ST08_4
  int v29; // ebx
  float v30; // ST08_4
  float v31; // ST08_4
  float v32; // ST08_4
  unsigned int *v33; // esi
  int v34; // edx
  float v35; // ebx
  unsigned int *v36; // esi
  _D3DRECT rect; // [esp+10h] [ebp-38h]
  double v38; // [esp+20h] [ebp-28h] OVERLAPPED
  int y2Clip; // [esp+28h] [ebp-20h]
  int v40; // [esp+2Ch] [ebp-1Ch]
  unsigned int v41; // [esp+30h] [ebp-18h]
  unsigned int SavedFormat; // [esp+34h] [ebp-14h]
  int x1; // [esp+38h] [ebp-10h]
  int y2; // [esp+3Ch] [ebp-Ch]
  int x2; // [esp+40h] [ebp-8h]
  unsigned int FillDepth; // [esp+44h] [ebp-4h]
  signed int y1; // [esp+60h] [ebp+18h]
  int y1a; // [esp+60h] [ebp+18h]

  ++D3DK::g_PerfCounters.m_APICounters[20];
  if ( !Flags || Flags & 0xFFFFFF0C )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid flags passed to Clear");
  if ( Flags & 2 && Stencil > 0xFF )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid stencil fill value");
  if ( Flags & 1 && (Z < 0.0 || Z > 1.0) )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid Z fill value");
  if ( Flags & 1 )
  {
    if ( !(Flags & 2) )
    {
      v6 = D3DK::g_pDevice->m_pZBuffer;
      if ( v6 )
      {
        if ( (D3DK::g_TextureFormat[BYTE1(v6->Format)] & 0x3C) == 32
          && !D3DK::g_StencilEverEnabled
          && !D3DK::g_WarnedAboutStencil )
        {
          D3DK::WARNING(
            (int *)D3DK::g_pDevice,
            "D3DCLEAR_ZBUFFER for 32-bit depth buffers is faster when D3DCLEAR_STENCIL set too,\n"
            "even when not using stencil");
          D3DK::g_WarnedAboutStencil = 1;
        }
      }
    }
  }
  v7 = D3DK::g_pDevice->m_pRenderTarget;
  v8 = (D3DK::g_TextureFormat[BYTE1(v7->Format)] & 1) == 0;
  v9 = D3DK::g_pDevice->m_pZBuffer;
  x1 = (int)D3DK::g_pDevice->m_pZBuffer;
  FillDepth = 0;
  SavedFormat = 0;
  if ( !v8 )
  {
    v10 = v7->Size;
    if ( v10 )
      v11 = (v7->Size & 0xFFF) + 1;
    else
      v11 = 1 << ((v7->Format >> 20) & 0xF);
    if ( v10 )
    {
      y2 = ((v10 >> 12) & 0xFFF) + 1;
      v13 = ((v10 >> 12) & 0xFFF) + 1;
    }
    else
    {
      v12 = HIBYTE(v7->Format) & 0xF;
      v13 = 1 << v12;
      y2 = 1 << v12;
    }
    if ( Count && (Count != 1 || pRects->x1 || pRects->y1 || pRects->x2 != v11 || pRects->y2 != v13) )
    {
      D3DK::DXGRIP((int *)D3DK::g_pDevice, "Swizzled render targets can only be cleared in their entirety.");
      v13 = y2;
    }
    if ( D3DK::g_pDevice->m_Viewport.X
      || D3DK::g_pDevice->m_Viewport.Y
      || D3DK::g_pDevice->m_Viewport.Width != v11
      || D3DK::g_pDevice->m_Viewport.Height != v13 )
    {
      D3DK::DXGRIP(
        (int *)D3DK::g_pDevice,
        "Swizzled render targets can only be cleared in their entirety and cannot be restricted by a viewport.");
    }
    SavedFormat = D3DK::PixelJar::GetSurfaceFormat(
                    (int *)D3DK::g_pDevice,
                    (D3DPixelContainer *)&v7->Common,
                    (D3DPixelContainer *)x1);
    v14 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v14, 0x208u, COERCE_FLOAT(SavedFormat & 0xFFFFFDFF | 0x100));
    XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v14 + 2);
    v9 = (D3DSurface *)x1;
  }
  if ( Flags & 0xF0 )
  {
    switch ( BYTE1(v7->Format) )
    {
      case 3u:
      case 0x1Cu:
        v15 = Color;
        v16 = (Color & 0xF800 | (Color >> 3) & 0x1F0000) >> 3;
        goto LABEL_42;
      case 5u:
      case 0x11u:
        v15 = Color;
        v16 = (Color & 0xFC00 | (Color >> 3) & 0x1F0000) >> 2;
LABEL_42:
        Color = (v15 & 0xF8 | v16) >> 3;
        break;
      default:
        break;
    }
  }
  if ( v9 || (Flags &= 0xFFFFFFFC) != 0 )
  {
    if ( Flags & 1 )
    {
      switch ( BYTE1(v9->Format) )
      {
        case 0x2Au:
        case 0x2Eu:
          v19 = Z * 16777215.0;
          v20 = D3DK::FloatToLong(v19);
          if ( v20 > 0xFFFFFF )
            v20 = 0xFFFFFF;
          FillDepth = (v20 < 0 ? 0 : v20) << 8;
          break;
        case 0x2Bu:
        case 0x2Fu:
          if ( Z == 0.0 )
          {
            FillDepth = 0;
          }
          else
          {
            v38 = Z * 1.0e30;
            FillDepth = 16 * ((HIDWORD(v38) - 0x8000000) & 0xFFFFFFF0);
          }
          break;
        case 0x2Cu:
        case 0x30u:
          f = Z * 65535.0;
          v18 = D3DK::FloatToLong(f);
          if ( v18 > 0xFFFF )
            v18 = 0xFFFF;
          FillDepth = v18 < 0 ? 0 : v18;
          break;
        case 0x2Du:
        case 0x31u:
          if ( Z == 0.0 )
          {
            FillDepth = 0;
          }
          else
          {
            v38 = Z * 511.9375;
            FillDepth = (unsigned __int16)((HIDWORD(v38) >> 8) + -32768);
          }
          break;
        default:
          D3DK::DXGRIP((int *)D3DK::g_pDevice, "D3DDevice_Clear - Unknown depth buffer format.");
          break;
      }
    }
    v21 = D3DK::g_pDevice->m_Viewport.X;
    v22 = D3DK::g_pDevice->m_Viewport.Y;
    v23 = v21 + D3DK::g_pDevice->m_Viewport.Width;
    v24 = v22 + D3DK::g_pDevice->m_Viewport.Height;
    v41 = D3DK::g_pDevice->m_Viewport.X;
    v40 = v22;
    HIDWORD(v38) = v23;
    y2Clip = v24;
    if ( !Count )
    {
      rect.y1 = v22;
      rect.x1 = v21;
      rect.x2 = v23;
      rect.y2 = v24;
      pRects = &rect;
      Count = 1;
    }
    do
    {
      v25 = pRects;
      x1 = pRects->x1;
      if ( x1 <= v21 )
        x1 = v21;
      y1 = pRects->y1;
      if ( pRects->y1 <= v40 )
        y1 = v40;
      v26 = pRects->x2;
      if ( pRects->x2 >= v23 )
        v26 = v23;
      v27 = pRects->y2;
      x2 = v26;
      if ( v27 >= v24 )
        v27 = v24;
      y2 = v27;
      if ( x1 < v26 && y1 < v27 )
      {
        v28 = (double)x1 * D3DK::g_pDevice->m_SuperSampleScaleX + 0.5;
        v29 = D3DK::FloatToLong(v28);
        v30 = (double)x2 * D3DK::g_pDevice->m_SuperSampleScaleX + 0.5;
        x2 = D3DK::FloatToLong(v30);
        v31 = (double)y1 * D3DK::g_pDevice->m_SuperSampleScaleY + 0.5;
        y1a = D3DK::FloatToLong(v31);
        v32 = (double)y2 * D3DK::g_pDevice->m_SuperSampleScaleY + 0.5;
        y2 = D3DK::FloatToLong(v32);
        v33 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
        XMETAL_PushCount((int *)D3DK::g_pDevice, v33, 0x1D98u, 2u);
        v34 = y1a | ((y2 - 1) << 16);
        v33[1] = v29 | ((x2 - 1) << 16);
        v33[2] = v34;
        XMETAL_PushCount((int *)D3DK::g_pDevice, v33 + 3, 0x1D8Cu, 3u);
        v33[4] = Stencil | FillDepth;
        v33[5] = Color;
        v33[6] = Flags;
        XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v33 + 7);
        v24 = y2Clip;
        v23 = HIDWORD(v38);
        v25 = pRects;
      }
      v21 = v41;
      v8 = Count == 1;
      pRects = v25 + 1;
      --Count;
    }
    while ( !v8 );
    v35 = *(float *)&SavedFormat;
    if ( SavedFormat )
    {
      v36 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
      XMETAL_Push1f((int *)D3DK::g_pDevice, v36, 0x208u, v35);
      XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v36 + 2);
    }
  }
}
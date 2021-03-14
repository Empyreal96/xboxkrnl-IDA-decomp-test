void *__thiscall D3DK::CMiniport::SetDmaRange(D3DK::CMiniport *this, unsigned int DmaContext, D3DSurface *pSurface)
{
  D3DK::CDevice *v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // edi
  unsigned int v8; // eax
  signed int v9; // eax
  unsigned int v10; // eax
  signed int v11; // eax
  unsigned int v12; // eax
  float v14; // ebx
  unsigned int *v15; // esi
  int *v16; // edi
  int *v17; // edi
  unsigned int *v18; // esi
  D3DK::CMiniport *PteInfo; // [esp+Ch] [ebp-1Ch]
  unsigned int PteInfoa; // [esp+Ch] [ebp-1Ch]
  void *Address; // [esp+10h] [ebp-18h]
  D3DK::CDevice *pDevice; // [esp+14h] [ebp-14h]
  unsigned int Limit; // [esp+18h] [ebp-10h]
  void *Base; // [esp+1Ch] [ebp-Ch]
  unsigned int Instance; // [esp+20h] [ebp-8h]
  unsigned int AddressSpace; // [esp+24h] [ebp-4h]
  int RegValue; // [esp+34h] [ebp+Ch]

  v3 = D3DK::g_pDevice;
  PteInfo = this;
  Address = 0;
  AddressSpace = 0;
  pDevice = D3DK::g_pDevice;
  switch ( DmaContext )
  {
    case 9u:
      v4 = D3DK::g_pDevice->m_ColorContextDmaInstance;
      break;
    case 0xAu:
      v4 = D3DK::g_pDevice->m_ZetaContextDmaInstance;
      break;
    case 0xBu:
      v4 = D3DK::g_pDevice->m_CopyContextDmaInstance;
      break;
    default:
      D3DK::DXGRIP((int *)D3DK::g_pDevice, "Unexpected DMA context");
      goto LABEL_9;
  }
  Instance = v4;
LABEL_9:
  if ( pSurface )
  {
    v5 = D3DK::PixelJar::GetPitch((D3DPixelContainer *)&pSurface->Common);
    v6 = pSurface->Data;
    v7 = v5;
    v8 = pSurface->Size;
    Base = (void *)pSurface->Data;
    if ( v8 )
      v9 = ((v8 >> 12) & 0xFFF) + 1;
    else
      v9 = 1 << (HIBYTE(pSurface->Format) & 0xF);
    Limit = v7 * v9 - 1;
    if ( v6 + Limit > 0x4000000 )
      D3DK::DXGRIP((int *)v7, "Assertion failure: %s", "(DWORD) Base + Limit <= AGP_APERTURE_BYTES");
    v10 = pSurface->Size;
    if ( v10 )
      v11 = (pSurface->Size & 0xFFF) + 1;
    else
      v11 = 1 << ((pSurface->Format >> 20) & 0xF);
    if ( v7 < v11 * (D3DK::g_TextureFormat[BYTE1(pSurface->Format)] & 0x3Cu) >> 3 )
      D3DK::DXGRIP(
        (int *)v7,
        "Assertion failure: %s",
        "Pitch >= PixelJar::GetWidth(pSurface) * PixelJar::GetBitsPerPixel(pSurface) / 8");
    v3 = pDevice;
  }
  else
  {
    Base = 0;
    Limit = 0;
  }
  v12 = v3->m_StateFlags;
  if ( v12 & 4 )
    return 0;
  if ( v12 & 0x400 )
  {
    Base = 0;
    Limit = 0x3FFFFFF;
  }
  D3DK::CMiniport::GetAddressInfo(PteInfo, (int *)v3, Base, &Address, &AddressSpace, 0);
  LODWORD(v14) = (unsigned int)Address | 3;
  PteInfoa = (unsigned int)Address | 3;
  RegValue = ((_DWORD)Address << 20) | 0x303D;
  if ( AddressSpace != 2 )
  {
    if ( AddressSpace == 3 )
    {
      BYTE2(RegValue) = ((((_DWORD)Address << 20) | 0x303Du) >> 16) | 3;
    }
    else if ( AddressSpace == 1 )
    {
      BYTE2(RegValue) = ((((_DWORD)Address << 20) | 0x303Du) >> 16) | 2;
    }
  }
  v15 = XMETAL_StartPush((int *)v3, &v3->m_Pusher);
  XMETAL_Push1f((int *)v3, v15, 0x110u, 0.0);
  v16 = (int *)(16 * Instance);
  v15 += 2;
  XMETAL_Push2f((int *)(16 * Instance), v15, 0x1D8Cu, COERCE_FLOAT(16 * Instance + 7340040), v14);
  XMETAL_Push1f(v16, v15 + 3, 0x100u, COERCE_FLOAT(800));
  v15 += 5;
  XMETAL_Push2f(v16, v15, 0x1D8Cu, COERCE_FLOAT(v16 + 1835011), *(float *)&PteInfoa);
  XMETAL_Push1f(v16, v15 + 3, 0x100u, COERCE_FLOAT(800));
  v15 += 5;
  XMETAL_Push2f(v16, v15, 0x1D8Cu, COERCE_FLOAT(16 * (Instance + 458752)), COERCE_FLOAT(RegValue | 0x8000));
  XMETAL_Push1f(v16, v15 + 3, 0x100u, COERCE_FLOAT(800));
  v17 = v16 + 1835009;
  v15 += 5;
  XMETAL_Push2f(v17, v15, 0x1D8Cu, *(float *)&v17, *(float *)&Limit);
  XMETAL_Push1f(v17, v15 + 3, 0x100u, COERCE_FLOAT(800));
  v18 = v15 + 5;
  switch ( DmaContext )
  {
    case 9u:
      XMETAL_Push1f(v17, v18, 0x194u, COERCE_FLOAT(9));
      break;
    case 0xAu:
      XMETAL_Push1f(v17, v18, 0x198u, COERCE_FLOAT(10));
      break;
    case 0xBu:
      D3DK::Push1(v17, v18, SUBCH_RECTCOPYSURFACES, 0x188u, COERCE_FLOAT(11));
      break;
    default:
      D3DK::DXGRIP(v17, "Unexpected DMA context");
      break;
  }
  XMETAL_EndPush(v17, &pDevice->m_Pusher, v18 + 2);
  return Base;
}
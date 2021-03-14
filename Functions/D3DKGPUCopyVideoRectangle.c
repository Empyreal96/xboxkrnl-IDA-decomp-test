void __stdcall D3DK::GPUCopyVideoRectangle(unsigned int BytesPerPixel, unsigned int SourceOffset, unsigned int SourcePitch, unsigned int DestOffset, unsigned int DestPitch, unsigned int Count, tagRECT *pRect, tagPOINT *pPoint)
{
  int *v8; // edi
  unsigned int *v9; // esi
  signed int v10; // ecx
  tagRECT *v11; // esi
  int *v12; // edi
  unsigned int *v13; // ST18_4
  bool v14; // zf
  unsigned int DestOffseta; // [esp+24h] [ebp+14h]

  v8 = (int *)D3DK::g_pDevice;
  if ( D3DK::g_pDevice->m_StateFlags & 4 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "!(pDevice->m_StateFlags & STATE_RECORDPUSHBUFFER)");
  if ( Count > 0x10 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "Count <= 16");
  if ( SourceOffset & 0x1F )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "SourceOffset % 32 == 0");
  if ( DestOffset & 0x1F )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "DestOffset % 32 == 0");
  if ( SourcePitch & 0x3F || !SourcePitch || SourcePitch > 0x1FC0 )
    D3DK::DXGRIP(
      (int *)D3DK::g_pDevice,
      "Assertion failure: %s",
      "SourcePitch % 64 == 0 && SourcePitch != 0 && SourcePitch <= 8128");
  if ( DestPitch & 0x3F || !DestPitch )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "DestPitch % 64 == 0 && DestPitch != 0");
  v9 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  if ( BytesPerPixel == 1 )
  {
    v10 = 1;
  }
  else if ( BytesPerPixel == 2 )
  {
    v10 = 4;
  }
  else
  {
    if ( BytesPerPixel != 4 )
      RtlRip(0, 0, "GPUCopyVideoRectangle - Bad pixel size.");
    v10 = 10;
  }
  D3DK::Push4(
    (int *)D3DK::g_pDevice,
    v9,
    SUBCH_RECTCOPYSURFACES,
    0x300u,
    *(float *)&v10,
    COERCE_FLOAT((DestPitch << 16) | (unsigned __int16)SourcePitch),
    *(float *)&SourceOffset,
    *(float *)&DestOffset);
  XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v9 + 5);
  if ( Count )
  {
    v11 = pRect;
    DestOffseta = Count;
    do
    {
      v12 = (int *)XMETAL_StartPush(v8, (_XMETAL_PushBuffer *)v8);
      D3DK::Push3(
        v12,
        (unsigned int *)v12,
        SUBCH_RECTCOPY,
        0x300u,
        COERCE_FLOAT((v11->top << 16) | v11->left & 0xFFFF),
        COERCE_FLOAT(pPoint->x & 0xFFFF | (pPoint->y << 16)),
        COERCE_FLOAT((unsigned __int16)(v11->right - v11->left) ^ ((v11->bottom - v11->top) << 16)));
      v13 = (unsigned int *)(v12 + 4);
      v8 = (int *)D3DK::g_pDevice;
      XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v13);
      ++v11;
      v14 = DestOffseta == 1;
      ++pPoint;
      --DestOffseta;
    }
    while ( !v14 );
  }
}
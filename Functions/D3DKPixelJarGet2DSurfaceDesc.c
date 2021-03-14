void __stdcall D3DK::PixelJar::Get2DSurfaceDesc(D3DPixelContainer *pPixels, unsigned int Level, _D3DSURFACE_DESC *pDesc)
{
  unsigned int v3; // ebx
  D3DPixelContainer *v4; // edi
  _D3DSURFACE_DESC *v5; // esi
  char v6; // al
  unsigned int v7; // edx
  _D3DSURFACE_DESC *v8; // eax
  unsigned int Depth; // [esp+Ch] [ebp-8h]
  unsigned int Pitch; // [esp+10h] [ebp-4h]

  v3 = Level;
  v4 = pPixels;
  if ( Level >= (BYTE2(pPixels->Format) & 0xFu) )
    D3DK::DXGRIP((int *)pPixels, "PixelJar::Get2DSurfaceDesc - invalid mipmap level.");
  v5 = pDesc;
  pDesc->Format = BYTE1(v4->Format);
  v5->Type = D3DResource_GetType((int *)v4, (D3DResource *)&v4->Common);
  v5->Usage = 0;
  if ( !v3 )
  {
    v6 = D3DK::g_TextureFormat[BYTE1(v4->Format)];
    if ( v6 >= 0 )
    {
      if ( v6 & 0x40 )
        v5->Usage = 2;
    }
    else
    {
      v5->Usage = 1;
    }
  }
  v4->Data;
  D3DK::g_pDevice->m_FrameBufferSurfaces[0].Data;
  v5->MultiSampleType = 17;
  D3DK::PixelJar::GetSize(v4, v3, (unsigned int *)&pPixels, &Level, &Depth, &Pitch, (unsigned int *)&pDesc);
  v7 = Level;
  v8 = pDesc;
  v5->Width = (unsigned int)pPixels;
  v5->Height = v7;
  v5->Size = (unsigned int)v8;
}
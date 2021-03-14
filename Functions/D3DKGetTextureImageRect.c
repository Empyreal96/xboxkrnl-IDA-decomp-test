int __stdcall D3DK::GetTextureImageRect(unsigned int Stage)
{
  D3DBaseTexture *v1; // esi
  int result; // eax
  unsigned int v3; // edx
  signed int v4; // eax

  v1 = D3DK::g_pDevice->m_Textures[Stage];
  if ( !v1 )
    return 0;
  v3 = v1->Size;
  if ( v3 )
    v4 = (v1->Size & 0xFFF) + 1;
  else
    v4 = 1 << ((v1->Format >> 20) & 0xF);
  if ( v3 )
    result = (((v3 >> 12) & 0xFFF) + 1) | (v4 << 16);
  else
    result = (1 << (HIBYTE(v1->Format) & 0xF)) | (v4 << 16);
  return result;
}
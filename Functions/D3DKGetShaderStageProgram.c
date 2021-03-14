unsigned int __stdcall D3DK::GetShaderStageProgram()
{
  D3DK::PixelShader *v0; // ecx
  unsigned int result; // eax
  int *v2; // edi
  D3DBaseTexture **v3; // ebx
  signed int v4; // ecx
  unsigned int v5; // edx
  signed int v6; // ecx
  D3DBaseTexture **v7; // edi
  D3DBaseTexture *v8; // esi
  unsigned int v9; // edx
  unsigned int v10; // edx
  unsigned int v11; // esi

  v0 = D3DK::g_pDevice->m_pPixelShader;
  result = 0;
  D3DK::g_pDevice->m_DirtyFlags &= 0xFFFFFBFF;
  if ( v0 )
  {
    if ( D3DK::g_pDevice->m_ShaderAdjustsTexMode )
    {
      v6 = 15;
      v7 = &D3DK::g_pDevice->m_Textures[3];
      do
      {
        v8 = *v7;
        v9 = (D3DK::g_pDevice->m_PSShaderStageProgram >> v6) & 0x1F;
        if ( *v7 )
        {
          if ( v9 < 1 || v9 > 3 )
          {
            if ( v9 == 13 || v9 == 14 )
              v9 = ((v8->Format & 4) != 0) + 13;
          }
          else
          {
            v10 = v8->Format;
            v11 = v8->Format & 0xFF00;
            if ( v10 & 4 )
            {
              v9 = 3;
            }
            else if ( (v10 & 0xF0) == 48 || v11 >= 0x2A00 && v11 <= 0x3100 )
            {
              v9 = 2;
            }
            else
            {
              v9 = 1;
            }
          }
        }
        else
        {
          v9 = 0;
        }
        result = v9 | 32 * result;
        --v7;
        v6 -= 5;
      }
      while ( v6 >= 0 );
    }
    else
    {
      result = D3DK::g_pDevice->m_PSShaderStageProgram;
    }
  }
  else
  {
    v2 = dword_800C2348;
    v3 = &D3DK::g_pDevice->m_Textures[3];
    do
    {
      v4 = 1;
      if ( *v3 )
      {
        if ( *v2 == 25 )
        {
          v4 = 6;
        }
        else if ( *v2 == 26 )
        {
          v4 = 7;
        }
        else
        {
          v5 = (*v3)->Format;
          if ( v5 & 4 )
          {
            v4 = 3;
          }
          else if ( (v5 & 0xF0) == 48 )
          {
            v4 = 2;
          }
        }
      }
      else
      {
        v4 = 0;
      }
      v2 -= 32;
      result = v4 | 32 * result;
      --v3;
    }
    while ( (signed int)v2 >= (signed int)D3D__TextureState );
  }
  return result;
}
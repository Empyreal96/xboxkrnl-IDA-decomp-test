void __stdcall D3DK::LazySetShaderStageProgram(D3DK::CDevice *pDevice)
{
  D3DK::PixelShader *v1; // eax
  unsigned int v2; // ebx
  unsigned int v3; // edi
  unsigned int (*v4)[32]; // esi
  signed int v5; // eax
  unsigned int v6; // edx
  int v7; // ecx
  signed int v8; // ecx
  D3DBaseTexture **v9; // esi
  D3DBaseTexture *v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // esi

  v1 = pDevice->m_pPixelShader;
  v2 = 0;
  pDevice->m_DirtyFlags &= 0xFFFFFBFF;
  if ( !v1 )
  {
    v3 = (unsigned int)&pDevice->m_Textures[3];
    v4 = (unsigned int (*)[32])dword_800C2348;
    while ( 1 )
    {
      v5 = 1;
      if ( *(_DWORD *)v3 )
      {
        if ( v4 == D3D__TextureState )
          goto LABEL_10;
        v6 = (*v4)[-32];
        if ( v6 == 25 )
        {
          v5 = 6;
        }
        else
        {
          if ( v6 != 26 )
          {
LABEL_10:
            v7 = *(_DWORD *)(*(_DWORD *)v3 + 12);
            if ( v7 & 4 )
            {
              v5 = 3;
            }
            else if ( (v7 & 0xF0) == 48 )
            {
              v5 = 2;
            }
            goto LABEL_14;
          }
          v5 = 7;
        }
      }
      else
      {
        v5 = 0;
      }
LABEL_14:
      --v4;
      v2 = v5 | 32 * v2;
      v3 -= 4;
      if ( (signed int)v4 < (signed int)D3D__TextureState )
        goto LABEL_38;
    }
  }
  v3 = pDevice->m_PSShaderStageProgram;
  if ( pDevice->m_ShaderAdjustsTexMode )
  {
    v8 = 15;
    v9 = &pDevice->m_Textures[3];
    do
    {
      v10 = *v9;
      v11 = (v3 >> v8) & 0x1F;
      if ( *v9 || v11 == 4 || v11 == 5 || v11 == 10 || v11 == 17 )
      {
        if ( v11 < 1 || v11 > 3 )
        {
          if ( v11 == 13 || v11 == 14 )
            v11 = ((v10->Format & 4) != 0) + 13;
        }
        else
        {
          v12 = v10->Format;
          v13 = v10->Format & 0xFF00;
          if ( v12 & 4 )
          {
            v11 = 3;
          }
          else if ( (v12 & 0xF0) == 48 || v13 >= 0x2A00 && v13 <= 0x3100 )
          {
            v11 = 2;
          }
          else
          {
            v11 = 1;
          }
        }
      }
      else
      {
        v11 = 0;
      }
      v2 = v11 | 32 * v2;
      --v9;
      v8 -= 5;
    }
    while ( v8 >= 0 );
  }
  else
  {
    v2 = pDevice->m_PSShaderStageProgram;
  }
LABEL_38:
  D3DK::ValidTextureModes((int *)v3, v2, "LazySetShaderStageProgram");
  v14 = XMETAL_StartPush((int *)pDevice, &pDevice->m_Pusher);
  XMETAL_Push1f((int *)pDevice, v14, 0x1E70u, *(float *)&v2);
  XMETAL_EndPush((int *)pDevice, &pDevice->m_Pusher, v14 + 2);
}
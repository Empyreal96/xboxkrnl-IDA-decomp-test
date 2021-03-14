void __usercall RenderMicrosoftLogo(int *a1@<edi>, int a2@<ecx>)
{
  int *v2; // ebx
  int *v3; // edi
  D3DK *v4; // ecx
  int *v5; // edi
  unsigned int v6; // ebx
  int *v7; // edi
  const unsigned int RenderStates[28]; // [esp+4h] [ebp-D0h]
  const unsigned int TextureStates[22]; // [esp+74h] [ebp-60h]
  D3DSurface *pSurface; // [esp+CCh] [ebp-8h]
  int i; // [esp+D0h] [ebp-4h]

  if ( g_ImageLogo )
  {
    if ( InitVB(a1, a2, gpd3dDev) && InitTexture(a1, gpd3dDev) )
    {
      D3DDevice_GetBackBuffer(-1, 0, &pSurface);
      D3DDevice_SetRenderTarget(pSurface, 0);
      RenderStates[21] = -1;
      RenderStates[1] = 6914;
      RenderStates[3] = 6914;
      RenderStates[7] = 1;
      TextureStates[5] = 1;
      RenderStates[0] = 119;
      RenderStates[2] = 120;
      RenderStates[4] = 127;
      RenderStates[5] = 0;
      RenderStates[6] = 65;
      RenderStates[8] = 60;
      RenderStates[9] = 0;
      RenderStates[10] = 59;
      RenderStates[11] = 0;
      RenderStates[12] = 82;
      RenderStates[13] = 0;
      RenderStates[14] = 131;
      RenderStates[15] = 0;
      RenderStates[16] = 124;
      RenderStates[17] = 0;
      RenderStates[18] = 92;
      RenderStates[19] = 0;
      RenderStates[20] = 133;
      RenderStates[22] = 130;
      RenderStates[23] = 0;
      RenderStates[24] = 67;
      RenderStates[25] = 16843009;
      RenderStates[26] = 138;
      RenderStates[27] = 0;
      TextureStates[0] = 0;
      TextureStates[1] = 2;
      TextureStates[2] = 2;
      TextureStates[3] = 2;
      TextureStates[4] = 4;
      TextureStates[6] = 28;
      TextureStates[7] = 0;
      TextureStates[8] = 10;
      TextureStates[9] = 3;
      TextureStates[10] = 11;
      TextureStates[11] = 3;
      TextureStates[12] = 19;
      TextureStates[13] = 0;
      TextureStates[14] = 20;
      TextureStates[15] = 0;
      TextureStates[16] = 21;
      TextureStates[17] = 0;
      TextureStates[18] = 14;
      TextureStates[19] = 2;
      TextureStates[20] = 13;
      TextureStates[21] = 2;
      i = 0;
      do
      {
        v2 = (int *)RenderStates[2 * i + 1];
        v3 = (int *)RenderStates[2 * i];
        if ( !D3DDevice_SetRenderState_ParameterCheck(v3, (_D3DRENDERSTATETYPE)v3, RenderStates[2 * i + 1]) )
        {
          if ( (signed int)v3 >= 82 )
          {
            if ( (signed int)v3 >= 116 )
            {
              if ( v3 == (int *)116 )
              {
                D3DDevice_SetRenderState_PSTextureModes((unsigned int)v2);
              }
              else if ( v3 == (int *)117 )
              {
                D3DDevice_SetRenderState_VertexBlend((unsigned int)v2);
              }
              else if ( v3 == (int *)118 )
              {
                D3DDevice_SetRenderState_FogColor((int *)0x76, (unsigned int)v2);
              }
              else if ( v3 == (int *)119 )
              {
                D3DDevice_SetRenderState_FillMode((int *)0x77, (unsigned int)v2);
              }
              else if ( v3 == (int *)120 )
              {
                D3DDevice_SetRenderState_BackFillMode((int *)0x78, (unsigned int)v2);
              }
              else if ( v3 == (int *)121 )
              {
                D3DDevice_SetRenderState_TwoSidedLighting((int *)0x79, (unsigned int)v2);
              }
              else if ( v3 == (int *)122 )
              {
                D3DDevice_SetRenderState_NormalizeNormals((int *)0x7A, (unsigned int)v2);
              }
              else if ( v3 == (int *)123 )
              {
                D3DDevice_SetRenderState_ZEnable((int *)0x7B, (unsigned int)v2);
              }
              else if ( v3 == (int *)124 )
              {
                D3DDevice_SetRenderState_StencilEnable((unsigned int)v2);
              }
              else if ( v3 == (int *)125 )
              {
                D3DDevice_SetRenderState_StencilFail((unsigned int)v2);
              }
              else if ( v3 == (int *)127 )
              {
                D3DDevice_SetRenderState_CullMode((unsigned int)v2);
              }
              else if ( v3 == (int *)126 )
              {
                D3DDevice_SetRenderState_FrontFace((int *)0x7E, (unsigned int)v2);
              }
              else if ( v3 == (int *)128 )
              {
                D3DDevice_SetRenderState_TextureFactor((int *)0x80, (unsigned int)v2);
              }
              else if ( v3 == (int *)129 )
              {
                D3DDevice_SetRenderState_ZBias((unsigned int)v2);
              }
              else if ( v3 == (int *)130 )
              {
                D3DDevice_SetRenderState_LogicOp((unsigned int)v2);
              }
              else if ( v3 == (int *)131 )
              {
                D3DDevice_SetRenderState_EdgeAntiAlias((int *)0x83, (unsigned int)v2);
              }
              else if ( v3 == (int *)132 )
              {
                D3DDevice_SetRenderState_MultiSampleAntiAlias((int *)0x84, (unsigned int)v2);
              }
              else if ( v3 == (int *)133 )
              {
                D3DDevice_SetRenderState_MultiSampleMask((int *)0x85, (unsigned int)v2);
              }
              else if ( v3 == (int *)134 )
              {
                D3DDevice_SetRenderState_MultiSampleType((unsigned int)v2);
              }
              else if ( v3 == (int *)135 )
              {
                D3DDevice_SetRenderState_ShadowFunc((int *)0x87, (unsigned int)v2);
              }
              else if ( v3 == (int *)136 )
              {
                D3DDevice_SetRenderState_LineWidth((unsigned int)v2);
              }
              else if ( v3 == (int *)137 )
              {
                D3DDevice_SetRenderState_Dxt1NoiseEnable((unsigned int)v2);
              }
              else if ( v3 == (int *)138 )
              {
                D3DDevice_SetRenderState_YuvEnable((int *)0x8A, (unsigned int)v2);
              }
              else if ( v3 == (int *)139 )
              {
                D3DDevice_SetRenderState_OcclusionCullEnable((int *)0x8B, (unsigned int)v2);
              }
              else if ( v3 == (int *)140 )
              {
                D3DDevice_SetRenderState_StencilCullEnable((int *)0x8C, (unsigned int)v2);
              }
              else if ( v3 == (int *)141 )
              {
                D3DDevice_SetRenderState_RopZCmpAlwaysRead(v4, (int *)0x8D, (unsigned int)v2);
              }
              else if ( v3 == (int *)142 )
              {
                D3DDevice_SetRenderState_RopZRead(v4, (int *)0x8E, (unsigned int)v2);
              }
              else if ( v3 == (int *)143 )
              {
                D3DDevice_SetRenderState_DoNotCullUncompressed(v4, (int *)0x8F, (unsigned int)v2);
              }
            }
            else
            {
              D3DDevice_SetRenderState_Deferred(0, (unsigned int)v3, v2);
            }
          }
          else
          {
            v5 = (int *)(4 * (_DWORD)v3);
            D3DDevice_SetRenderState_Simple(0, *(const unsigned int *)((char *)DSI + (_DWORD)v5), (unsigned int)v2, v5);
            *(unsigned int *)((char *)D3D__RenderState + (_DWORD)v5) = (unsigned int)v2;
          }
        }
        ++i;
      }
      while ( (unsigned int)i < 0xE );
      i = 0;
      do
      {
        v6 = TextureStates[2 * i + 1];
        v7 = (int *)TextureStates[2 * i];
        if ( !D3DDevice_SetTextureState_ParameterCheck(v7, 0, (_D3DTEXTURESTAGESTATETYPE)v7, TextureStates[2 * i + 1]) )
        {
          if ( (signed int)v7 >= 22 )
          {
            if ( v7 == (int *)28 )
            {
              D3DDevice_SetTextureState_TexCoordIndex(0, v6);
            }
            else if ( v7 == (int *)29 )
            {
              D3DDevice_SetTextureState_BorderColor(0, v6);
            }
            else if ( v7 == (int *)30 )
            {
              D3DDevice_SetTextureState_ColorKeyColor(0, v6);
            }
            else if ( (signed int)v7 <= 27 )
            {
              D3DDevice_SetTextureState_BumpEnv(v7, 0, (_D3DTEXTURESTAGESTATETYPE)v7, v6);
            }
          }
          else
          {
            D3DDevice_SetTextureState_Deferred(0, 0, (int)v7, v6);
          }
        }
        ++i;
      }
      while ( (unsigned int)i < 0xB );
      D3DDevice_SetStreamSource(v7, 0, g_pVBMicrosoftLogo, 0x18u);
      D3DDevice_SetVertexShader(v7, 0x104u);
      D3DDevice_SetTexture(0, (D3DBaseTexture *)&g_pTexMicrosoftLogo->Common);
      D3DDevice_DrawVertices(D3DPT_TRIANGLELIST, 0, 6u);
      D3DResource_Release(v7, (D3DResource *)&pSurface->Common);
      UnInitMicrosoftLogo(v7);
      D3DDevice_PersistDisplay(v7);
    }
    else
    {
      UnInitMicrosoftLogo(a1);
    }
  }
}
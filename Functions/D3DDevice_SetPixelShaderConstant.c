// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetPixelShaderConstant(int *a1@<edi>, unsigned int Register, const void *pConstantData, unsigned int ConstantCount)
{
  D3DK::CDevice *v4; // esi
  unsigned int v5; // edi
  float *v6; // ebx
  double v7; // st7
  float f; // ST08_4
  char v9; // al
  double v10; // st7
  float v11; // ST08_4
  unsigned __int8 v12; // al
  double v13; // st7
  float v14; // ST08_4
  unsigned __int8 v15; // bl
  float v16; // ST08_4
  unsigned __int16 v17; // dx
  int v18; // ecx
  int v19; // ebx
  int v20; // eax
  unsigned int v21; // esi
  int v22; // ebx
  unsigned int v23; // esi
  int v24; // ebx
  unsigned int v25; // esi
  unsigned int *v26; // esi
  _DWORD *v27; // ebx
  _DWORD *v28; // edx
  bool v29; // zf
  unsigned int v30; // [esp+10h] [ebp-10h]
  _D3DPixelShaderDef *pPsd; // [esp+18h] [ebp-8h]
  _DWORD *v32; // [esp+1Ch] [ebp-4h]
  float Registera; // [esp+28h] [ebp+8h]
  int dVal; // [esp+2Ch] [ebp+Ch]
  char dVal_3; // [esp+2Fh] [ebp+Fh]
  unsigned __int8 ConstantCount_3; // [esp+33h] [ebp+13h]

  v4 = D3DK::g_pDevice;
  ++D3DK::g_PerfCounters.m_APICounters[124];
  if ( !pConstantData )
    D3DK::DXGRIP(a1, "Invalid constant data pointer in SetPixelShaderConstant");
  v5 = Register;
  if ( Register + ConstantCount > 0x10 )
    D3DK::DXGRIP((int *)Register, "Too many constants specified in SetPixelShaderConstant");
  if ( !D3DK::g_pDevice->m_pPixelShader )
    D3DK::DXGRIP((int *)Register, "Attempt to set pixel shader constant with no active pixel shader.");
  pPsd = D3DK::g_pDevice->m_pPixelShader->pPSDef;
  if ( ConstantCount )
  {
    v6 = (float *)((char *)pConstantData + 4);
    v32 = (char *)pConstantData + 4;
    v30 = ConstantCount;
    while ( 1 )
    {
      Registera = v6[2];
      if ( Registera <= 1.0 )
      {
        if ( Registera < 0.0 )
          Registera = 0.0;
      }
      else
      {
        Registera = 1.0;
      }
      v7 = *(v6 - 1);
      if ( v7 <= 1.0 )
      {
        if ( v7 < 0.0 )
          v7 = 0.0;
      }
      else
      {
        v7 = 1.0;
      }
      f = v7 * 255.0 + 0.5;
      v9 = D3DK::FloatToLong(f);
      v10 = *v6;
      dVal_3 = v9;
      if ( v10 <= 1.0 )
      {
        if ( v10 < 0.0 )
          v10 = 0.0;
      }
      else
      {
        v10 = 1.0;
      }
      v11 = v10 * 255.0 + 0.5;
      v12 = D3DK::FloatToLong(v11);
      v13 = v6[1];
      ConstantCount_3 = v12;
      if ( v13 <= 1.0 )
      {
        if ( v13 < 0.0 )
          v13 = 0.0;
      }
      else
      {
        v13 = 1.0;
      }
      v14 = v13 * 255.0 + 0.5;
      v15 = D3DK::FloatToLong(v14);
      v16 = Registera * 255.0 + 0.5;
      HIBYTE(v17) = D3DK::FloatToLong(v16);
      v18 = v15;
      LOBYTE(v17) = dVal_3;
      v19 = 0;
      v20 = v18 | ((ConstantCount_3 | (v17 << 8)) << 8);
      v4->m_pPixelShaderConstants[v5] = v20;
      dVal = v18 | ((ConstantCount_3 | (v17 << 8)) << 8);
      v21 = 0;
      do
      {
        if ( ((pPsd->PSC0Mapping >> v21) & 0xF) == v5 )
        {
          D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v19 + 10), v20);
          v20 = dVal;
        }
        v21 += 4;
        ++v19;
      }
      while ( v21 < 0x20 );
      v22 = 0;
      v23 = 0;
      do
      {
        if ( ((pPsd->PSC1Mapping >> v23) & 0xF) == v5 )
        {
          D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v22 + 18), v20);
          v20 = dVal;
        }
        v23 += 4;
        ++v22;
      }
      while ( v23 < 0x20 );
      v24 = 0;
      v25 = 0;
      do
      {
        if ( ((pPsd->PSFinalCombinerConstants >> v25) & 0xF) == v5 )
        {
          D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)(v24 + 43), v20);
          v20 = dVal;
        }
        v25 += 4;
        ++v24;
      }
      while ( v25 < 8 );
      if ( v5++ )
      {
        v27 = v32;
      }
      else
      {
        v26 = XMETAL_StartPush(0, &D3DK::g_pDevice->m_Pusher);
        XMETAL_PushCount(0, v26, 0x181Cu, 3u);
        v27 = v32;
        v28 = v26 + 1;
        *v28 = *(v32 - 1);
        v28[1] = *v32;
        v28[2] = v32[1];
        XMETAL_EndPush(0, &D3DK::g_pDevice->m_Pusher, v26 + 4);
      }
      v29 = v30 == 1;
      v32 = v27 + 4;
      --v30;
      if ( v29 )
        break;
      v4 = D3DK::g_pDevice;
      v6 = (float *)(v27 + 4);
    }
  }
}
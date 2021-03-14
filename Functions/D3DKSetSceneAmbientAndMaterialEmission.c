unsigned int *__stdcall D3DK::SetSceneAmbientAndMaterialEmission(unsigned int *pPush, unsigned int colorMaterial)
{
  unsigned int *v2; // esi
  _D3DMATERIAL8 *v3; // ebx
  double v4; // st7
  double v5; // st7
  double v6; // st6
  double v7; // st5
  bool v8; // zf
  unsigned int i; // [esp+10h] [ebp-14h]
  float emissiveB; // [esp+14h] [ebp-10h]
  float emissiveG; // [esp+18h] [ebp-Ch]
  float emissiveR; // [esp+1Ch] [ebp-8h]
  float ambientG; // [esp+20h] [ebp-4h]
  float ambientB; // [esp+2Ch] [ebp+8h]
  float ambientBa; // [esp+2Ch] [ebp+8h]

  v2 = pPush;
  i = 0;
  v3 = &D3DK::g_pDevice->m_Material;
  XMETAL_PushCount(0, pPush, 0xA10u, 3u);
  XMETAL_PushCount(0, pPush + 4, 0x3A8u, 3u);
  XMETAL_PushCount(0, pPush + 8, 0x3B4u, 1u);
  while ( 1 )
  {
    v4 = (double)0 * 0.0039215689;
    ambientG = v4;
    ambientB = v4;
    if ( colorMaterial & 0xC )
    {
      emissiveR = v4;
      v5 = v3->Emissive.r;
      v6 = v3->Emissive.g;
      emissiveG = (double)0 * 0.0039215689;
      emissiveB = (double)0 * 0.0039215689;
      ambientBa = v3->Emissive.b;
    }
    else
    {
      v5 = v4 * v3->Ambient.r;
      if ( colorMaterial & 3 )
      {
        emissiveR = 1.0;
        v6 = ambientG * v3->Ambient.g;
        emissiveG = 1.0;
        emissiveB = 1.0;
        v7 = ambientB * v3->Ambient.b;
      }
      else
      {
        v5 = v5 + v3->Emissive.r;
        emissiveR = 0.0;
        emissiveG = 0.0;
        emissiveB = 0.0;
        v6 = ambientG * v3->Ambient.g + v3->Emissive.g;
        v7 = ambientB * v3->Ambient.b + v3->Emissive.b;
      }
      ambientBa = v7;
    }
    *((float *)v2 + 1) = v5;
    *((float *)v2 + 3) = ambientBa;
    *((float *)v2 + 2) = v6;
    *((float *)v2 + 5) = emissiveR;
    *((float *)v2 + 6) = emissiveG;
    *((float *)v2 + 7) = emissiveB;
    v2[9] = LODWORD(v3->Diffuse.a);
    v2 += 10;
    v8 = i-- == 0;
    if ( v8 )
      break;
    colorMaterial >>= 8;
    v3 = &D3DK::g_pDevice->m_BackMaterial;
    XMETAL_PushCount(0, v2, 0x17A0u, 3u);
    XMETAL_PushCount(0, v2 + 4, 0x17B0u, 3u);
    XMETAL_PushCount(0, v2 + 8, 0x17ACu, 1u);
  }
  return v2;
}
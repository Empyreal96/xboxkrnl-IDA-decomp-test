unsigned int *__userpurge D3DK::SetLightColors@<eax>(int *a1@<edi>, unsigned int *pPush, D3DK::Light *pLight, unsigned int lightNum, unsigned int colorMaterial)
{
  unsigned int *v5; // esi
  float *v6; // ebx
  bool v7; // zf
  unsigned int i; // [esp+4h] [ebp-4h]

  v5 = pPush;
  i = 0;
  v6 = &D3DK::g_pDevice->m_Material.Diffuse.r;
  XMETAL_PushCount(a1, pPush, (lightNum + 32) << 7, 9u);
  while ( 1 )
  {
    if ( colorMaterial & 0xC )
    {
      v5[1] = LODWORD(pLight->Light8.Ambient.r);
      v5[2] = LODWORD(pLight->Light8.Ambient.g);
      v5[3] = LODWORD(pLight->Light8.Ambient.b);
    }
    else
    {
      *((float *)v5 + 1) = v6[4] * pLight->Light8.Ambient.r;
      *((float *)v5 + 2) = v6[5] * pLight->Light8.Ambient.g;
      *((float *)v5 + 3) = v6[6] * pLight->Light8.Ambient.b;
    }
    if ( colorMaterial & 0x30 )
    {
      v5[4] = LODWORD(pLight->Light8.Diffuse.r);
      v5[5] = LODWORD(pLight->Light8.Diffuse.g);
      v5[6] = LODWORD(pLight->Light8.Diffuse.b);
    }
    else
    {
      *((float *)v5 + 4) = pLight->Light8.Diffuse.r * *v6;
      *((float *)v5 + 5) = v6[1] * pLight->Light8.Diffuse.g;
      *((float *)v5 + 6) = v6[2] * pLight->Light8.Diffuse.b;
    }
    if ( colorMaterial & 0xC0 )
    {
      v5[7] = LODWORD(pLight->Light8.Specular.r);
      v5[8] = LODWORD(pLight->Light8.Specular.g);
      v5[9] = LODWORD(pLight->Light8.Specular.b);
    }
    else
    {
      *((float *)v5 + 7) = v6[8] * pLight->Light8.Specular.r;
      *((float *)v5 + 8) = v6[9] * pLight->Light8.Specular.g;
      *((float *)v5 + 9) = v6[10] * pLight->Light8.Specular.b;
    }
    v5 += 10;
    v7 = i-- == 0;
    if ( v7 )
      break;
    XMETAL_PushCount((int *)pLight, v5, (lightNum + 48) << 6, 9u);
    colorMaterial >>= 8;
    v6 = &D3DK::g_pDevice->m_BackMaterial.Diffuse.r;
  }
  return v5;
}
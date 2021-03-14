void __usercall GreenFog::destroy(GreenFog *this@<ecx>, int *a2@<edi>)
{
  GreenFog *v2; // esi
  D3DResource *v3; // eax
  int *v4; // edi
  int *v5; // edi
  D3DResource *v6; // eax
  D3DResource *v7; // eax
  unsigned int v8; // eax
  int *v9; // [esp-4h] [ebp-10h]
  signed int v10; // [esp+8h] [ebp-4h]

  v2 = this;
  if ( this->pQuadVB )
    D3DResource_Release(a2, (D3DResource *)&this->pQuadVB->Common);
  v3 = (D3DResource *)&v2->pIntensityQuadVB->Common;
  v2->pQuadVB = 0;
  if ( v3 )
    D3DResource_Release(a2, v3);
  v9 = a2;
  v2->pIntensityQuadVB = 0;
  v4 = (int *)v2->pPlasmaTexture;
  v10 = 3;
  do
  {
    if ( *v4 )
      D3DResource_Release(v4, (D3DResource *)*v4);
    *v4 = 0;
    ++v4;
    --v10;
  }
  while ( v10 );
  v5 = v9;
  if ( v2->pIntensityTextureU )
    D3DResource_Release(v9, (D3DResource *)&v2->pIntensityTextureU->Common);
  v6 = (D3DResource *)&v2->pIntensityTextureR->Common;
  v2->pIntensityTextureU = 0;
  if ( v6 )
    D3DResource_Release(v5, v6);
  v7 = (D3DResource *)&v2->pIntensityZ->Common;
  v2->pIntensityTextureR = 0;
  if ( v7 )
    D3DResource_Release(v5, v7);
  v8 = v2->dwFogPShader;
  v2->pIntensityZ = 0;
  if ( v8 )
    D3DDevice_DeletePixelShader(v8);
  if ( v2->dwFogVShader )
    D3DDevice_DeleteVertexShader(v2->dwFogVShader);
  v2->dwFogVShader = 0;
  v2->dwFogPShader = 0;
}
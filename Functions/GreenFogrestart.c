void __thiscall GreenFog::restart(GreenFog *this)
{
  D3DTexture **v1; // esi
  int *v2; // edi
  signed int v3; // ebx
  int v4; // eax
  int v5; // edx
  int v6; // ecx

  v1 = this->pPlasmaTexture;
  v2 = (int *)this->pPlasmaTexture;
  v3 = 3;
  do
  {
    if ( *v2 )
      D3DResource_Release(v2, (D3DResource *)*v2);
    ++v2;
    --v3;
  }
  while ( v3 );
  v4 = QRand::Rand(&stru_8010BD4C);
  CreateIntensityTexture_8Bit(v6, v5, v1, 3, 256, 425, v4, 16128, 85);
}
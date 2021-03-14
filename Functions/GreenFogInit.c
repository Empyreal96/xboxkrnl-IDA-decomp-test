void __thiscall GreenFog::Init(GreenFog *this)
{
  this->pQuadVB = 0;
  this->pIntensityQuadVB = 0;
  this->pPlasmaTexture[0] = 0;
  this->pPlasmaTexture[1] = 0;
  this->pPlasmaTexture[2] = 0;
  this->pIntensityTextureR = 0;
  this->pIntensityTextureU = 0;
  this->pIntensityZ = 0;
  this->dwFogVShader = 0;
  this->dwFogPShader = 0;
}
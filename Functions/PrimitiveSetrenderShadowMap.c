void __thiscall PrimitiveSet::renderShadowMap(PrimitiveSet *this, bool b_hi_z)
{
  PrimitiveSet *v2; // esi
  int *v3; // edi

  v2 = this;
  v3 = (int *)this->shaderType;
  this->shaderType = 3;
  this->bHiZ = b_hi_z;
  PrimitiveSet::render(this, v3, &light, 0);
  v2->shaderType = (ShaderTypes)v3;
}
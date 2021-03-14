void __thiscall PrimitiveSet::renderZ(PrimitiveSet *this)
{
  PrimitiveSet *v1; // esi
  int *v2; // edi

  v1 = this;
  v2 = (int *)this->shaderType;
  this->shaderType = 2;
  PrimitiveSet::render(this, v2, &light, 0);
  v1->shaderType = (ShaderTypes)v2;
}
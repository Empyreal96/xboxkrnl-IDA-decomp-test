void __thiscall D3DK::CMiniport::HalGrControlInit(D3DK::CMiniport *this)
{
  _DWORD *v1; // edx
  unsigned int v2; // ecx
  _DWORD *v3; // eax
  signed int v4; // ecx

  v1 = this->m_RegisterBase;
  v2 = this->m_HalInfo.GrCtxTableBase;
  v1[1049056] = (unsigned __int16)v2;
  v3 = &v1[4 * (v2 + 458752)];
  v4 = 2;
  do
  {
    *v3 = 0;
    ++v3;
    --v4;
  }
  while ( v4 );
}
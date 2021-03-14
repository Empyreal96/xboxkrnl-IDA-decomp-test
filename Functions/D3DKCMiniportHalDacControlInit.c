void __thiscall D3DK::CMiniport::HalDacControlInit(D3DK::CMiniport *this)
{
  char *v1; // eax
  char v2; // bl
  char v3; // cl
  unsigned int *v4; // ecx

  v1 = (char *)this->m_RegisterBase;
  v1[6296532] = 31;
  v2 = v1[6296533];
  v1[6296532] = 31;
  v1[6296533] = 87;
  v1[6296532] = 82;
  v3 = v1[6296533];
  v1[6296532] = 82;
  v1[6296533] = v3 + 4;
  *((_DWORD *)v1 + 8226) = *((_DWORD *)v1 + 8226) & 0xFFFFF43F | 0x400;
  *((_DWORD *)v1 + 8226) = *((_DWORD *)v1 + 8226) & 0xF43FFFFF | 0x4000000;
  v4 = (unsigned int *)(v1 + 32908);
  *v4 = *((_DWORD *)v1 + 8227) & 0xFFFFF40F | 0x400;
  *v4 = *((_DWORD *)v1 + 8227) & 0xF40FFFFF | 0x4000000;
  v1[6296532] = 32;
  v1[6296533] = 41;
  v1[6296532] = 27;
  v1[6296533] = 5;
  *((_DWORD *)v1 + 1573377) = *((_DWORD *)v1 + 1573377) & 0xFFFFFFFA | 2;
  if ( !v2 )
  {
    v1[6296532] = 31;
    v1[6296533] = -103;
  }
}
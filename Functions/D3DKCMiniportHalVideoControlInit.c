void __thiscall D3DK::CMiniport::HalVideoControlInit(D3DK::CMiniport *this)
{
  _DWORD *v1; // eax
  signed int v2; // esi

  v1 = (char *)this->m_RegisterBase + 35096;
  v2 = 2;
  do
  {
    *(v1 - 2) = 4096;
    *v1 = 4096;
    v1[8] = 0x100000;
    v1[10] = 0x100000;
    v1[6] = 0;
    v1[4] = -1;
    ++v1;
    --v2;
  }
  while ( v2 );
}
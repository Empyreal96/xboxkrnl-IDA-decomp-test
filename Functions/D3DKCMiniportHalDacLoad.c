void __thiscall D3DK::CMiniport::HalDacLoad(D3DK::CMiniport *this)
{
  _DWORD *v1; // eax

  v1 = this->m_RegisterBase;
  v1[1572928] = 1;
  v1[1572944] = 1;
}
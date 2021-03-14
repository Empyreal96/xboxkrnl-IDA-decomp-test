void __thiscall D3DK::CMiniport::HalGrInitObjectContext(D3DK::CMiniport *this, unsigned int Instance, unsigned int ClassNum)
{
  int v3; // esi
  signed int v4; // ebx
  int *v5; // edi
  int *v6; // eax

  v3 = (unsigned __int8)ClassNum;
  v4 = 0;
  v5 = (int *)this->m_RegisterBase;
  if ( ClassNum == 57 )
  {
    v3 = (unsigned __int8)ClassNum | 0x1000000;
  }
  else if ( ClassNum != 98 )
  {
    if ( ClassNum == 151 )
    {
      v4 = 2560;
    }
    else if ( ClassNum != 159 )
    {
      D3DK::DXGRIP(v5, "Unexpected class");
    }
  }
  v5[4 * (Instance + 458752)] = v3;
  v6 = &v5[4 * Instance];
  v6[1835009] = v4;
  v6[1835010] = 0;
  v6[1835011] = 0;
}
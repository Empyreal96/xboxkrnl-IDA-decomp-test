void __fastcall D3DK::CMiniport::HalGrIdle(D3DK::CMiniport *this, int a2)
{
  D3DK::CMiniport *v2; // edi
  _DWORD *v3; // esi
  int v4; // ebx

  v2 = this;
  v3 = this->m_RegisterBase;
  while ( v3[1049024] )
  {
    v4 = v3[64];
    if ( v4 & 0x1000 )
      D3DK::CMiniport::ServiceGrInterrupt(v2, (int *)v2);
    if ( v4 & 0x1000000 )
      D3DK::CMiniport::VBlank(v2, a2);
  }
}
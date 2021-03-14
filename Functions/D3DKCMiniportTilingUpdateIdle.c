void __fastcall D3DK::CMiniport::TilingUpdateIdle(D3DK::CMiniport *this, int a2, unsigned int *dmapush)
{
  D3DK::CMiniport *v3; // edi
  _DWORD *v4; // esi

  v3 = this;
  v4 = this->m_RegisterBase;
  while ( !(v4[3205] & 0x10) || !(v4[2304] & 0x10) || v4[3208] & 0x10 )
  {
    D3DK::CMiniport::ServiceFifoInterrupt(v3, a2);
    if ( v4[1048640] )
      D3DK::CMiniport::ServiceGrInterrupt(v3, (int *)v3);
    if ( v4[64] & 0x1000000 )
      D3DK::CMiniport::VBlank(v3, a2);
  }
  *dmapush = v4[3208];
  v4[3208] = 0;
  while ( v4[3208] & 0x10 )
    ;
}
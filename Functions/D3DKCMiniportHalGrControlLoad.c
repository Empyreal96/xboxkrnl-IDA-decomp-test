void __thiscall D3DK::CMiniport::HalGrControlLoad(D3DK::CMiniport *this)
{
  D3DK::CMiniport *v1; // edi
  _DWORD *v2; // esi
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  _DWORD *v8; // eax
  int v9; // edx
  int v10; // ecx
  int v11; // ebx
  bool v12; // zf
  int v13; // eax
  int v14; // eax
  int v15; // eax
  signed int v16; // [esp+Ch] [ebp-4h]
  signed int v17; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = this->m_RegisterBase;
  v3 = (char *)this->m_RegisterBase + 512;
  *v3 &= 0xFFFFEFFF;
  *v3 |= 0x1000u;
  this->m_DebugRegister[6] = 1173016846;
  this->m_DebugRegister[1] = 1148672;
  this->m_DebugRegister[2] = 577535;
  this->m_DebugRegister[3] = -203553671;
  this->m_DebugRegister[4] = 0;
  this->m_DebugRegister[5] = 4;
  this->m_DebugRegister[0] = 0;
  this->m_DebugRegister[6] = 1173016847 - ((v2[1158] & 0x100) != 256);
  this->m_DebugRegister[7] = 0;
  this->m_DebugRegister[8] = 120;
  this->m_DebugRegister[9] = 64;
  this->m_DebugRegister[10] = 0;
  v2[1048608] = 0;
  v2[1048609] = this->m_DebugRegister[1];
  v2[1049120] = this->m_DebugRegister[2];
  v2[1048611] = this->m_DebugRegister[3];
  v2[1048612] = this->m_DebugRegister[4];
  v2[1048613] = this->m_DebugRegister[5];
  v2[1049312] = this->m_DebugRegister[6];
  v2[1049313] = this->m_DebugRegister[7];
  v2[1048614] = this->m_DebugRegister[8];
  v2[1048615] = this->m_DebugRegister[9];
  v2[1049314] = this->m_DebugRegister[10];
  v2[1049056] = this->m_HalInfo.GrCtxTableBase & 0xFFFF;
  D3DK::CMiniport::HalGrIdle(this, 0);
  v16 = 80;
  v4 = v2 + 1049152;
  do
  {
    v5 = *(v4 - 786863);
    v4[1] = v5;
    v2[1049044] = ((_WORD)v16 - 32) & 0x1FFC | 0xEA0000;
    v2[1049045] = v5;
    v6 = *(v4 - 786862);
    v4[2] = v6;
    v2[1049044] = v16 & 0x1FFC | 0xEA0000;
    v2[1049045] = v6;
    v7 = *(v4 - 786864);
    *v4 = v7;
    v2[1049044] = ((_WORD)v16 - 64) & 0x1FFC | 0xEA0000;
    v2[1049045] = v7;
    if ( *(v4 - 786864) != *v4 )
      D3DK::DXGRIP(
        (int *)v1,
        "Assertion failure: %s",
        "REG_RD32(RegisterBase, NV_PFB_TILE(i)) == REG_RD32(RegisterBase, NV_PGRAPH_TILE(i))");
    if ( *(v4 - 786863) != v4[1] )
      D3DK::DXGRIP(
        (int *)v1,
        "Assertion failure: %s",
        "REG_RD32(RegisterBase, NV_PFB_TLIMIT(i)) == REG_RD32(RegisterBase, NV_PGRAPH_TLIMIT(i))");
    if ( *(v4 - 786862) != v4[2] )
      D3DK::DXGRIP(
        (int *)v1,
        "Assertion failure: %s",
        "REG_RD32(RegisterBase, NV_PFB_TSIZE(i)) == REG_RD32(RegisterBase, NV_PGRAPH_TSIZE(i))");
    v16 += 4;
    v4 += 4;
  }
  while ( v16 < 112 );
  v8 = v2 + 1049184;
  v9 = -4196592 - (_DWORD)v2;
  v17 = 8;
  do
  {
    v10 = *(v8 - 786848);
    *v8 = v10;
    v11 = ((_WORD)v9 + (_WORD)v8) & 0x1FFC | 0xEA0000;
    ++v8;
    v12 = v17-- == 1;
    v2[1049044] = v11;
    v2[1049045] = v10;
  }
  while ( !v12 );
  v13 = v2[262345];
  v2[1049192] = v13;
  v2[1049044] = 15335436;
  v2[1049045] = v13;
  v14 = v2[262272];
  v2[1049193] = v14;
  v2[1049044] = 15335424;
  v2[1049045] = v14;
  v15 = v2[262273];
  v2[1049194] = v15;
  v2[1049044] = 15335428;
  v2[1049045] = v15;
  v2[1048659] = 0;
  v2[1048660] = 0;
  v2[1048661] = 0;
  v2[1048662] = 0;
  v2[1048657] = 0x10000000;
  v2[1049049] = 0x8000000;
  D3DK::CMiniport::HalGrLoadChannelContext(v1, v9, (int *)v1, v1->m_HalInfo.GrChID);
}
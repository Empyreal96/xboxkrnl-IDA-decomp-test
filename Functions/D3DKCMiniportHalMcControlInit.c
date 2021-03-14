void __thiscall D3DK::CMiniport::HalMcControlInit(D3DK::CMiniport *this)
{
  D3DK::CMiniport *v1; // esi
  _DWORD *v2; // edi
  unsigned int *v3; // ecx
  unsigned int v4; // eax
  bool v5; // zf
  unsigned int v6; // ecx
  unsigned int v7; // eax
  int v8; // ST10_4
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  _DWORD *v12; // eax
  int v13; // ecx
  unsigned int v14; // edi
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned int v17; // eax
  int P; // [esp+10h] [ebp-8h]
  unsigned int M; // [esp+14h] [ebp-4h]
  unsigned int Ma; // [esp+14h] [ebp-4h]

  v1 = this;
  v2 = this->m_RegisterBase;
  v3 = (unsigned int *)((char *)this->m_RegisterBase + 512);
  v4 = *v3;
  v5 = *v3 == 0;
  v1->m_HalInfo.McSave = *v3;
  if ( v5 )
    *v3 = v4;
  v1->m_HalInfo.McSaveIntrEn0 = v2[80];
  *v3 = -1;
  v6 = *((unsigned __int8 *)v2 + 6817029);
  v7 = v2[1704257];
  M = v2[1704257] & 0xFF;
  v1->m_DacInfo.MPllM = M;
  v8 = (v7 >> 16) & 7;
  v1->m_DacInfo.MPllN = v6;
  v1->m_DacInfo.MPllO = 1;
  v1->m_DacInfo.MPllP = v8;
  if ( M )
    v9 = v6 * v1->m_GenInfo.CrystalFreq / (1 << (BYTE2(v7) & 7)) / M;
  else
    v9 = 0;
  v1->m_DacInfo.MClk = v9;
  Ma = v2[1704258] & 0xFF;
  v10 = *((unsigned __int8 *)v2 + 6817033);
  P = (v2[1704258] >> 16) & 7;
  v1->m_DacInfo.VPllM = Ma;
  v1->m_DacInfo.VPllN = v10;
  v1->m_DacInfo.VPllO = 1;
  v1->m_DacInfo.VPllP = P;
  if ( Ma )
    v11 = v10 * v1->m_GenInfo.CrystalFreq / (1 << P) / Ma;
  else
    v11 = 0;
  v1->m_DacInfo.VClk = v11;
  v12 = v2 + 1704256;
  v13 = v2[1704256];
  v14 = *((unsigned __int8 *)v2 + 6817025);
  v15 = (unsigned __int8)v13;
  v16 = (*v12 >> 16) & 7;
  v1->m_DacInfo.NVPllM = v15;
  v1->m_DacInfo.NVPllN = v14;
  v1->m_DacInfo.NVPllO = 1;
  v1->m_DacInfo.NVPllP = v16;
  if ( v15 )
    v17 = v14 * v1->m_GenInfo.CrystalFreq / (1 << v16) / v15;
  else
    v17 = 0;
  v1->m_DacInfo.NVClk = v17;
}
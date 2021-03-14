void __thiscall D3DK::CMiniport::HalFifoContextSwitch(D3DK::CMiniport *this, unsigned int ChID)
{
  D3DK::CMiniport *v2; // esi
  _DWORD *v3; // eax
  unsigned int v4; // ebx
  int v5; // ecx
  _DWORD *v6; // edx
  int v7; // ecx
  _DWORD *v8; // edx
  unsigned int FifoReassign; // [esp+Ch] [ebp-14h]
  unsigned int FifoPush; // [esp+10h] [ebp-10h]
  unsigned int FifoPull; // [esp+14h] [ebp-Ch]
  signed int v12; // [esp+1Ch] [ebp-4h]

  v2 = this;
  v3 = this->m_RegisterBase;
  v4 = this->m_HalInfo.FifoContextAddr1;
  FifoReassign = *((_DWORD *)this->m_RegisterBase + 2368);
  FifoPush = *((_DWORD *)this->m_RegisterBase + 3200);
  FifoPull = *((_DWORD *)this->m_RegisterBase + 3220);
  v3[2368] = 0;
  v3[3200] = 0;
  v3[3220] = 0;
  v5 = v3[3201] & 0x1F;
  v6 = (_DWORD *)((char *)&v3[16 * v5] + v4);
  *v6 = v3[3216];
  v6[1] = v3[3217];
  v6[2] = v3[3218];
  v6[3] = v3[3211];
  v6[4] = v3[3210];
  v6[5] = v3[3209];
  v6[6] = v3[3232];
  v6[7] = v3[3221];
  v6[8] = v3[3226];
  v6[9] = v3[3225];
  v6[10] = v3[3224];
  v6[11] = v3[3227];
  v6[12] = v3[3219];
  if ( v3[3201] & 0x100 )
  {
    v12 = 1 << v5;
    v7 = v3[2370] & ~(1 << v5);
    if ( v3[3216] != v3[3217] )
      v7 |= v12;
    v3[2370] = v7;
  }
  v3[3201] = ChID & 0x1F;
  if ( (1 << ChID) & v2->m_HalInfo.FifoMode && ChID != 1 )
    v3[3201] |= 0x100u;
  v8 = (_DWORD *)((char *)&v3[16 * ChID] + v4);
  v3[3216] = *v8;
  v3[3217] = v8[1];
  v3[3218] = v8[2];
  v3[3211] = v8[3];
  v3[3210] = v8[4];
  v3[3209] = v8[5];
  v3[3232] = v8[6];
  v3[3221] = v8[7];
  v3[3226] = v8[8];
  v3[3225] = v8[9];
  v3[3224] = v8[10];
  v3[3227] = v8[11];
  v3[3219] = v8[12];
  if ( (1 << ChID) & v2->m_HalInfo.FifoMode && ChID != 1 )
    v3[3208] = 1;
  v3[2067] = 0x1FFFFF;
  v3[3220] = FifoPull;
  v3[3200] = FifoPush;
  v3[2368] = FifoReassign;
}
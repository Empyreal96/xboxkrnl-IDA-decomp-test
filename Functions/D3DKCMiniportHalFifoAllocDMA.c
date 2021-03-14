void __thiscall D3DK::CMiniport::HalFifoAllocDMA(D3DK::CMiniport *this, unsigned int fetchTrigger, unsigned int fetchSize, unsigned int fetchRequests, D3DK::CMiniport::OBJECTINFO *DataContext)
{
  int *v5; // edi
  _DWORD *v6; // esi
  int v7; // et1
  int v8; // ebx
  unsigned int v9; // eax
  int v10; // ecx
  int v11; // eax
  _DWORD *v12; // ecx
  signed int v13; // edx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  int v16; // edx
  char v17; // al
  int v18; // ecx
  int v19; // edx
  signed int v20; // eax
  _DWORD *v21; // [esp+Ch] [ebp-4h]
  int v22; // [esp+Ch] [ebp-4h]

  v5 = (int *)this;
  v6 = this->m_RegisterBase;
  v7 = *((_DWORD *)this->m_RegisterBase + 2368);
  v8 = this->m_HalInfo.FifoChID;
  *((_DWORD *)this->m_RegisterBase + 2368) = 0;
  v9 = 0;
  do
  {
    v10 = v9++ + 4 * v5[67] + 1835008;
    v6[v10] = 0;
  }
  while ( v9 < 0xDFC );
  v21 = &v6[v8 + 4 * v5[80] + 1835008];
  if ( *v21 )
    D3DK::DXGRIP(v5, "Assertion failure: %s", "INST_RD32(RegisterBase, grCtxTable, ChID * 4) == 0");
  if ( v5[v8 + 78] )
    D3DK::DXGRIP(v5, "Assertion failure: %s", "m_HalInfo.GrCtxTable[ChID] == 0");
  *v21 = v5[67];
  v5[v8 + 78] = v5[67];
  v11 = (int)&v6[16 * v8] + v5[74];
  v22 = (int)&v6[16 * v8] + v5[74];
  v12 = (_DWORD *)((char *)&v6[16 * v8] + v5[74]);
  v13 = 16;
  do
  {
    *v12 = 0;
    ++v12;
    --v13;
  }
  while ( v13 );
  v14 = fetchTrigger;
  *(_DWORD *)(v11 + 12) = DataContext->Instance;
  if ( fetchTrigger < 8 )
    v14 = 8;
  if ( v14 > 0x100 )
    v14 = 256;
  v15 = fetchSize;
  v16 = (v14 >> 3) - 1;
  if ( fetchSize < 0x20 )
    v15 = 32;
  if ( v15 > 0x100 )
    v15 = 256;
  v17 = fetchRequests;
  v18 = (v15 >> 5) - 1;
  if ( fetchRequests > 0xF )
    v17 = 15;
  v19 = 8 * (v16 & 0x1F | ((v18 & 7 | 8 * (v17 & 0x1F)) << 10));
  *(_DWORD *)(v22 + 20) = v19;
  v20 = 1 << v8;
  v5[65] |= 1 << v8;
  v6[2369] = v5[65];
  v6[3200] = 0;
  v6[3220] = 0;
  v6[3201] = v8 & 0x1F;
  if ( (1 << v8) & v5[65] )
    v6[3201] |= 0x100u;
  v6[3216] = 0;
  v6[3217] = 0;
  v6[3211] = DataContext->Instance;
  v6[3212] = 0;
  v6[3210] = 0;
  v6[3232] = 0;
  v6[3209] = v19;
  if ( v20 & v5[65] )
    v6[3208] = 1;
  v6[3220] = 1;
  v6[3200] = 1;
  v6[2368] = 1;
  v5[66] |= v20;
}
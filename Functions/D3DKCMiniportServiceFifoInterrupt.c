// write access to const memory has been detected, the output may be wrong!
int __fastcall D3DK::CMiniport::ServiceFifoInterrupt(D3DK::CMiniport *this, int a2)
{
  int *v2; // edi
  _DWORD *v3; // esi
  int v4; // ebx
  unsigned int v5; // ebx
  int *v6; // edi
  signed int v7; // eax
  int v8; // eax
  unsigned int intr; // [esp+Ch] [ebp-Ch]
  D3DK::CMiniport *v11; // [esp+10h] [ebp-8h]
  unsigned int GetPtr; // [esp+14h] [ebp-4h]

  v2 = (int *)this;
  v3 = this->m_RegisterBase;
  v4 = *((_DWORD *)this->m_RegisterBase + 2112);
  v11 = this;
  if ( v4 & 0x10 )
    D3DK::DXGRIP((int *)this, "MP: RUNOUT NOT HANDLED\n");
  if ( v4 & 0x100000 )
  {
    D3DK::DXGRIP(v2, "MP: DMA semaphore pending");
    v3[2112] = 0x100000;
  }
  if ( v4 & 0x1000000 )
  {
    D3DK::DXGRIP(v2, "MP: DMA acquire timeout pending");
    v3[2112] = 0x1000000;
  }
  v5 = v3[2112];
  intr = v3[2112];
  if ( v5 & 1 )
  {
    v6 = (int *)v3[3220];
    GetPtr = v3[3228] >> 2;
    v3[2368] = 0;
    v3[3220] = 0;
    v3[2112] = 1;
    v7 = 0xFFFF;
    do
    {
      if ( !((unsigned __int16)v6 & 0x1000) )
        break;
      --v7;
      v6 = (int *)v3[3220];
    }
    while ( v7 );
    if ( (unsigned __int8)v6 & 0x10 )
    {
      D3DK::DXGRIP(v6, "MP: FIFO hash error");
      D3DK::g_DpcRIPFired = 1;
    }
    if ( (unsigned __int16)v6 & 0x100 || (unsigned __int8)v6 & 0x10 )
    {
      D3DK::DXGRIP(v6, "MP: Access to free channel");
      D3DK::g_DpcRIPFired = 1;
      v3[3228] = (4 * GetPtr + 4) & 0x3FC;
    }
    v2 = (int *)v11;
    v5 = intr;
    v3[3222] = 0;
    v3[3220] = 1;
    v3[2368] = 1;
  }
  if ( v5 & 0x100 )
  {
    D3DK::DXGRIP(v2, "MP: RUNOUT NOT HANDLED\n");
    D3DK::g_DpcRIPFired = 1;
  }
  if ( v5 & 0x1000 )
  {
    DbgPrint(v2, "SW PUT=%x\n", D3DK::g_pDevice->m_Pusher.m_pPut);
    DbgPrint(v2, "HW PUT=%x\n", MEMORY[0xFD003240]);
    DbgPrint(v2, "HW GET=%x\n", MEMORY[0xFD003244]);
    D3DK::DXGRIP(v2, "MP: DMA push encountered a parse error");
    D3DK::g_DpcRIPFired = 1;
    v3[2112] = 4096;
    v3[3210] = 0;
    if ( v3[3216] != v3[3217] )
      v3[3217] += 4;
  }
  if ( v5 & 0x10000 )
  {
    D3DK::DXGRIP(v2, "MP: Invalid DMA pusher PTE fetch");
    D3DK::g_DpcRIPFired = 1;
    v3[2112] = 0x10000;
  }
  v8 = v3[3208];
  if ( v8 & 0x1000 )
  {
    if ( v3[3205] & 0x10 )
      goto LABEL_40;
    do
    {
      if ( v3[2112] )
        break;
      if ( v3[1048640] )
        D3DK::CMiniport::ServiceGrInterrupt((D3DK::CMiniport *)v2, v2);
      if ( v3[64] & 0x1000000 )
        D3DK::CMiniport::VBlank((D3DK::CMiniport *)v2, a2);
    }
    while ( !(v3[3205] & 0x10) );
    if ( v3[3205] & 0x10 )
    {
LABEL_40:
      while ( v3[2368] & 0x10 )
        ;
      v3[3208] &= 0xFFFFEFFF;
    }
  }
  if ( !v3[2112] )
  {
    v3[3220] = 1;
    v3[2368] = 1;
  }
  return v3[2112] | v3[2080] & 1;
}
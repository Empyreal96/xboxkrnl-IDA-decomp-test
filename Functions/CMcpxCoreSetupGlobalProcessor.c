void __userpurge CMcpxCore::SetupGlobalProcessor(CMcpxCore *this@<ecx>, int *a2@<edi>, int a3@<esi>, int fInitial)
{
  unsigned int dwTotalSgeCount; // ST40_4
  void *v5; // edx
  CMcpxGPDspManager *v6; // eax
  CMcpxGPDspManager *v7; // [esp+0h] [ebp-48h]
  CMcpxCore *thisa; // [esp+4h] [ebp-44h]
  CMcpxGPDspManager *v9; // [esp+8h] [ebp-40h]
  R_GP_CONTROL rControl; // [esp+Ch] [ebp-3Ch]
  unsigned int z; // [esp+10h] [ebp-38h]
  unsigned int dwAddress; // [esp+14h] [ebp-34h]
  unsigned int dwSgeOffset; // [esp+1Ch] [ebp-2Ch]
  MCP1_PRD *pPrd; // [esp+24h] [ebp-24h]
  unsigned int i; // [esp+44h] [ebp-4h]

  thisa = this;
  MEMORY[0xFE802044] = this->m_ctxMemory[9].PhysicalAddress;
  MEMORY[0xFE83FF00] = 0;
  MEMORY[0xFE83FF04] = 0;
  dwTotalSgeCount = this->m_ctxMemory[0].Size >> 12;
  MEMORY[0xFE8020D8] = dwTotalSgeCount - 1;
  MEMORY[0xFE801148] = dwTotalSgeCount - 1;
  MEMORY[0xFE803024] = 0;
  MEMORY[0xFE803028] = CMcpxCore::m_adwGPOutputBufferSizes[0];
  v5 = this->m_ctxMemory[9].VirtualAddress;
  pPrd = (MCP1_PRD *)this->m_ctxMemory[9].VirtualAddress;
  i = 0;
  dwSgeOffset = 0;
  while ( i < 1 )
  {
    for ( z = 0; z < *(_DWORD *)(4 * i - 2146508028) >> 12; ++z )
    {
      dwAddress = thisa->m_ctxMemory[0].PhysicalAddress + ((z + dwSgeOffset) << 12);
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE821800] = z + dwSgeOffset;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE821808] = dwAddress;
      pPrd[z + dwSgeOffset].uAddr = dwAddress;
      pPrd[z + dwSgeOffset].Control.uValue = 0;
      pPrd[z + dwSgeOffset].Control.uValue &= 0xFEFFFFFF;
    }
    while ( MEMORY[0xFE820010] < 4u )
      ;
    *(_DWORD *)(8 * i - 25030656) = dwSgeOffset << 12;
    while ( MEMORY[0xFE820010] < 4u )
      ;
    this = (CMcpxCore *)i;
    v5 = *(void **)(4 * i - 2146508028);
    *(_DWORD *)(8 * i - 25030656 + 4) = v5;
    dwSgeOffset += z;
    ++i;
  }
  if ( fInitial )
  {
    v9 = (CMcpxGPDspManager *)CMcpxAPU::operator new((int)v5, (int)this, a3, 0x40u);
    if ( v9 )
    {
      CMcpxGPDspManager::CMcpxGPDspManager(v9, thisa);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    thisa->m_pGpDspManager = v7;
    CMcpxGPDspManager::Initialize(thisa->m_pGpDspManager, a2, (int)thisa, a3);
  }
  MEMORY[0xFE83FF10] = (rControl.uValue | 1) & 0xFFFFFFF7;
  MEMORY[0xFE83FF14] = 255;
  MEMORY[0xFE80302C] = MEMORY[0xFE803024];
  MEMORY[0xFE80303C] = MEMORY[0xFE803034];
  MEMORY[0xFE80304C] = MEMORY[0xFE803044];
  MEMORY[0xFE80305C] = MEMORY[0xFE803054];
  MEMORY[0xFE83FFFC] = 3;
}
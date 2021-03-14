// write access to const memory has been detected, the output may be wrong!
int __usercall D3DDevice_PersistDisplay@<eax>(int *a1@<edi>)
{
  D3DSurface *v1; // eax
  int v2; // edx
  int v3; // ecx
  int result; // eax
  _D3DFORMAT v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // eax
  void *v9; // edi
  unsigned int v10; // ebx
  unsigned int v11; // esi
  unsigned int v12; // ST14_4
  unsigned int v13; // ST10_4
  unsigned int v14; // eax
  int v15; // edx
  int v16; // ecx
  signed int v17; // eax
  int v18; // edx
  _D3DFORMAT Format; // [esp+4h] [ebp-8h]
  D3DSurface *pCopy; // [esp+8h] [ebp-4h]

  ++D3DK::g_PerfCounters.m_APICounters[106];
  v1 = (D3DSurface *)AvGetSavedDataAddress();
  pCopy = v1;
  if ( v1 )
  {
    MmFreeContiguousMemory(v2, v3, a1, v1);
    AvSetSavedDataAddress(0);
  }
  if ( !D3DK::g_pDevice->m_cRefs )
    return -2147467259;
  while ( D3DK::CMiniport::IsFlipPending(&D3DK::g_pDevice->m_Miniport) )
    ;
  v5 = BYTE1(D3DK::g_pDevice->m_FrameBufferSurfaces[1].Format);
  v6 = D3DK::g_pDevice->m_FrameBufferSurfaces[1].Size;
  Format = BYTE1(D3DK::g_pDevice->m_FrameBufferSurfaces[1].Format);
  if ( v6 )
    v7 = (D3DK::g_pDevice->m_FrameBufferSurfaces[1].Size & 0xFFF) + 1;
  else
    v7 = 1 << ((D3DK::g_pDevice->m_FrameBufferSurfaces[1].Format >> 20) & 0xF);
  if ( v6 )
    v8 = ((v6 >> 12) & 0xFFF) + 1;
  else
    v8 = 1 << (HIBYTE(D3DK::g_pDevice->m_FrameBufferSurfaces[1].Format) & 0xF);
  result = D3DK::CreateSurfaceWithContiguousHeader(
             (int *)v5,
             (int)&D3DK::g_pDevice->m_FrameBufferSurfaces[1],
             v7,
             v8,
             v5,
             &pCopy);
  if ( result >= 0 )
  {
    D3DDevice_CopyRects(&D3DK::g_pDevice->m_FrameBufferSurfaces[1], 0, 0, pCopy, 0);
    D3DK::KickOffAndWaitForIdle((int *)v5);
    v9 = D3DK::g_pDevice->m_Miniport.m_RegisterBase;
    v10 = D3DK::g_pDevice->m_Miniport.m_DisplayMode;
    v11 = 0;
    do
    {
      v12 = pCopy->Data;
      v13 = D3DK::PixelJar::GetPitch((D3DPixelContainer *)&pCopy->Common);
      v14 = D3DK::MapToLinearD3DFORMAT(Format);
      v11 = AvSetDisplayMode(v16, v15, v9, v11, v10, v14, v13, v12);
    }
    while ( v11 );
    v17 = MmQueryAllocationSize(pCopy);
    MmPersistContiguousMemory(v18, (int)pCopy, 0, pCopy, v17, 1);
    AvSetSavedDataAddress(pCopy);
    result = 0;
  }
  return result;
}
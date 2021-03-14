// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetTile(unsigned int Index, _D3DTILE *pTile)
{
  int *v2; // edi
  signed int v3; // esi
  unsigned int v4; // ecx
  __int16 v5; // bx
  unsigned int v6; // ebx
  unsigned int v7; // eax
  unsigned int *v8; // esi
  int *v9; // edi
  unsigned int v10; // ST18_4
  unsigned int v11; // edx
  unsigned int v12; // ST14_4
  void *v13; // eax
  int v14; // edi
  unsigned int v15; // ST10_4
  unsigned int v16; // ST08_4
  unsigned int v17; // eax
  int v18; // edx
  _D3DTILE tile; // [esp+Ch] [ebp-20h]
  D3DK::CDevice *v20; // [esp+24h] [ebp-8h]
  D3DK::CDevice *pDevice; // [esp+28h] [ebp-4h]
  _D3DTILE *pTilea; // [esp+38h] [ebp+Ch]

  ++D3DK::g_PerfCounters.m_APICounters[170];
  pDevice = D3DK::g_pDevice;
  if ( !D3DK::g_pDevice )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Device hasn't been initialized yet");
  if ( Index >= 8 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Can't set any tile index of D3DTILE_MAXTILES (8) or more");
  if ( pTile && pTile->pMemory )
  {
    qmemcpy(&tile, pTile, sizeof(tile));
    pTilea = (_D3DTILE *)(tile.Flags & 0x80000000);
    if ( (tile.Flags & 0x80000000) == 0 )
    {
      tile.ZOffset = 0;
      tile.ZStartTag = 0;
    }
    v2 = (int *)tile.pMemory;
    v3 = 0;
    if ( ((_DWORD)tile.pMemory & 0xF0000000) != 0x80000000 )
      D3DK::DXGRIP((int *)tile.pMemory, "AssertContiguous - the memory is not contiguous.");
    v4 = pDevice->m_Tile[Index].Size;
    v20 = (D3DK::CDevice *)((char *)pDevice + 24 * Index);
    if ( v4 )
      D3DK::DXGRIP(v2, "Tile already in use - set to NULL first if you want to reset");
    if ( tile.Flags & 0x7BFFFFFE )
      D3DK::DXGRIP(v2, "Invalid Flags");
    v5 = tile.Size;
    if ( !tile.Size )
      D3DK::DXGRIP(v2, "Size can't be zero if pMemory is non-zero");
    if ( (unsigned __int16)v2 & 0x3FFF )
      D3DK::DXGRIP(v2, "pMemory must be a multiple of D3DTILE_ALIGNMENT (16k)");
    if ( v5 & 0x3FFF )
      D3DK::DXGRIP(v2, "Size must be a multiple of D3DTILE_ALIGNMENT (16k)");
    v6 = tile.Pitch;
    v7 = 0;
    do
    {
      if ( D3DK::g_TilePitches[v7] == tile.Pitch )
        v3 = 1;
      if ( dword_8007A68C[v7] == tile.Pitch )
        v3 = 1;
      if ( dword_8007A690[v7] == tile.Pitch )
        v3 = 1;
      if ( dword_8007A694[v7] == tile.Pitch )
        v3 = 1;
      if ( dword_8007A698[v7] == tile.Pitch )
        v3 = 1;
      if ( dword_8007A69C[v7] == tile.Pitch )
        v3 = 1;
      if ( dword_8007A6A0[v7] == tile.Pitch )
        v3 = 1;
      if ( dword_8007A6A4[v7] == tile.Pitch )
        v3 = 1;
      v7 += 8;
    }
    while ( v7 < 16 );
    if ( !v3 )
      D3DK::DXGRIP(v2, "Pitch must be a valid D3DTILE_PITCH_* value");
    if ( pTilea )
    {
      if ( LOBYTE(tile.ZStartTag) )
        D3DK::DXGRIP(v2, "ZStartTag must be a multiple of 256");
      if ( tile.ZStartTag >= 0x12C00 )
        D3DK::DXGRIP(v2, "ZStart can't be D3DTILE_MAXTAGS (76800) or more");
      if ( tile.ZOffset & 0x3FFF )
        D3DK::DXGRIP(v2, "ZOffset must be a multiple of D3DTILE_ALIGNMENT (16k)");
      if ( tile.ZOffset && (((tile.Size >> 6) + tile.ZStartTag + 255) & 0xFFFFFF00) <= 0x12C00 )
        D3DK::DXGRIP(
          v2,
          "ZOffset can only be used for the last buffer - the one in which \n"
          "the tags run out (D3DTILE_ZENDTAG(pTile) > D3DTILE_MAXTAGS)");
      v8 = &pDevice->m_Tile[0].ZStartTag;
      v9 = (int *)8;
      do
      {
        if ( (*(v8 - 4) & 0x80000000) != 0
          && tile.ZStartTag < (((*(v8 - 2) >> 6) + *v8 + 255) & 0xFFFFFF00)
          && (((tile.Size >> 6) + tile.ZStartTag + 255) & 0xFFFFFF00) > *v8 )
        {
          D3DK::DXGRIP(v9, "Z tag range overlaps with a tag range already in use");
        }
        v8 += 6;
        v9 = (int *)((char *)v9 - 1);
      }
      while ( v9 );
    }
    v10 = tile.ZOffset;
    v11 = tile.Size;
    v12 = tile.ZStartTag;
    v13 = tile.pMemory;
    v14 = (int)v20->m_Tile;
    qmemcpy(v20->m_Tile, &tile, 0x18u);
    v15 = tile.Flags;
    v16 = v11;
    v17 = D3DK::GetGPUAddress((int *)(v14 + 24), v13);
    D3DK::CMiniport::CreateTile(&pDevice->m_Miniport, v18, Index, v17, v16, v6, v15, v12, v10);
  }
  else
  {
    D3DK::CMiniport::DestroyTile(&D3DK::g_pDevice->m_Miniport, 3 * Index, Index, D3DK::g_pDevice->m_Tile[Index].ZOffset);
    memset(&D3DK::g_pDevice->m_Tile[Index], 0, sizeof(D3DK::g_pDevice->m_Tile[Index]));
  }
}
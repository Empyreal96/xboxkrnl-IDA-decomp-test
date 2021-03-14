int __fastcall D3DK::CMiniport::CreateTile(D3DK::CMiniport *this, int a2, unsigned int TileRegion, unsigned int Offset, unsigned int Size, unsigned int Pitch, unsigned int MemType, unsigned int ZTag, unsigned int ZOffset)
{
  D3DK::CMiniport *v9; // edi
  _DWORD *v10; // esi
  unsigned int v11; // edi
  int v12; // edx
  unsigned int v13; // ecx
  bool v14; // zf
  _DWORD *v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // eax
  unsigned int *v18; // ebx
  unsigned int *v19; // ebx
  unsigned int *v20; // edi
  unsigned int dmapush; // [esp+Ch] [ebp-20h]
  unsigned int v23; // [esp+10h] [ebp-1Ch]
  unsigned int v24; // [esp+14h] [ebp-18h]
  unsigned int v25; // [esp+18h] [ebp-14h]
  unsigned int v26; // [esp+1Ch] [ebp-10h]
  unsigned int v27; // [esp+20h] [ebp-Ch]
  D3DK::CMiniport *v28; // [esp+24h] [ebp-8h]
  _DWORD *v29; // [esp+28h] [ebp-4h]
  unsigned int *TileRegiona; // [esp+34h] [ebp+8h]
  unsigned int zoffset; // [esp+38h] [ebp+Ch]
  unsigned int zoffseta; // [esp+38h] [ebp+Ch]
  unsigned int *Sizea; // [esp+3Ch] [ebp+10h]

  v9 = this;
  v10 = this->m_RegisterBase;
  v28 = this;
  if ( Offset & 0x3FFF || Size & 0x3FFF )
    D3DK::DXGRIP((int *)this, "Assertion failure: %s", "!(Offset & 0x3fff) && !(Size & 0x3fff)");
  D3DK::CMiniport::TilingUpdateIdle(v9, a2, &dmapush);
  v11 = TileRegion;
  v12 = Size;
  v25 = MemType & 1;
  v27 = (4 * TileRegion + 16) & 0x1FFC | 0xEA0000;
  v24 = (4 * TileRegion + 48) & 0x1FFC | 0xEA0000;
  v26 = Offset + Size - 1;
  v13 = (4 * TileRegion + 80) & 0x1FFC;
  Sizea = &v10[4 * (TileRegion + 65572)];
  TileRegiona = &v10[4 * (TileRegion + 262288)];
  v23 = v13 | 0xEA0000;
  v29 = &v10[4 * v11];
  do
  {
    D3DK::CMiniport::HalGrIdle(v28, v12);
    v14 = v25 == 0;
    v15 = v29;
    v16 = v26;
    v29[262289] = v26;
    v15[262290] = Pitch;
    v15[1049153] = v16;
    v15[1049154] = Pitch;
    if ( v14 )
      v17 = Offset | 1;
    else
      v17 = Offset | 3;
    *TileRegiona = v17;
    *Sizea = v17;
    v12 = v27;
    v10[1049044] = v27;
    v10[1049045] = v17;
    v10[1049044] = v24;
    v10[1049045] = v26;
    v10[1049044] = v23;
    v10[1049045] = Pitch;
  }
  while ( *Sizea != *TileRegiona || v29[262290] != v29[1049154] || (v29[262289] ^ v29[1049153]) & 0xFFFFC000 );
  if ( (MemType & 0x80000000) != 0 )
  {
    zoffset = (ZTag >> 2) | 0x80000000;
    if ( MemType & 0x4000000 )
      zoffset = (ZTag >> 2) | 0x84000000;
    v18 = &v10[v11 + 262336];
    do
    {
      D3DK::CMiniport::HalGrIdle(v28, v12);
      *v18 = zoffset;
      v10[v11 + 1049184] = zoffset;
      v10[1049044] = (4 * v11 + 144) & 0x1FFC | 0xEA0000;
      v10[1049045] = zoffset;
    }
    while ( *v18 != v10[v11 + 1049184] );
    if ( ZOffset )
    {
      v19 = v10 + 262345;
      zoffseta = ZOffset | v11 | 0x80000000;
      v20 = v10 + 1049192;
      do
      {
        D3DK::CMiniport::HalGrIdle(v28, v12);
        *v19 = zoffseta;
        *v20 = zoffseta;
      }
      while ( *v19 != *v20 );
    }
  }
  v10[3208] = dmapush;
  return 1;
}
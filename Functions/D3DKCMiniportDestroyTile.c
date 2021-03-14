int __fastcall D3DK::CMiniport::DestroyTile(D3DK::CMiniport *this, int a2, unsigned int TileRegion, unsigned int ZOffset)
{
  _DWORD *v4; // esi
  int v5; // edx
  unsigned int v6; // edi
  _DWORD *v7; // ecx
  unsigned int dmapush; // [esp+Ch] [ebp-Ch]
  _DWORD *v10; // [esp+10h] [ebp-8h]
  D3DK::CMiniport *v11; // [esp+14h] [ebp-4h]
  _DWORD *TileRegiona; // [esp+20h] [ebp+8h]

  v4 = this->m_RegisterBase;
  v11 = this;
  D3DK::CMiniport::TilingUpdateIdle(this, a2, &dmapush);
  v6 = TileRegion;
  TileRegiona = &v4[4 * (TileRegion + 65572)];
  v10 = &v4[4 * (v6 + 262288)];
  do
  {
    D3DK::CMiniport::HalGrIdle(v11, v5);
    v7 = v10;
    v5 = 0;
    *TileRegiona = 0;
    *v7 = 0;
    v4[1049044] = (4 * v6 + 16) & 0x1FFC | 0xEA0000;
    v4[1049045] = 0;
  }
  while ( *TileRegiona != *v7 );
  v4[v6 + 262336] = 0;
  v4[v6 + 1049184] = 0;
  v4[1049044] = (4 * v6 + 144) & 0x1FFC | 0xEA0000;
  v4[1049045] = 0;
  if ( ZOffset )
  {
    v4[262345] = 0;
    v4[1049192] = 0;
  }
  v4[3208] = dmapush;
  return 1;
}
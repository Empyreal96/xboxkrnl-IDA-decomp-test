void __stdcall deskey(_destable *k, char *key)
{
  int v2; // edx
  int v3; // ecx
  int v4; // eax
  unsigned int v5; // edx
  int v6; // ecx
  unsigned int v7; // eax
  int v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx
  unsigned int v12; // eax
  int v13; // ecx
  _destable *v14; // ebx
  int v15; // edx
  int v16; // ecx
  unsigned int v17; // esi
  unsigned int v18; // ecx
  int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // edx
  unsigned int v23; // esi
  unsigned int *v24; // ebx
  unsigned int v25; // eax
  _destable *ka; // [esp+14h] [ebp+4h]

  v2 = (*(_DWORD *)key ^ (*((_DWORD *)key + 1) >> 4)) & 0xF0F0F0F;
  v3 = v2 ^ *(_DWORD *)key;
  v4 = 16 * v2 ^ *((_DWORD *)key + 1);
  v5 = (v3 ^ ((v2 ^ *(_DWORD *)key) << 18)) & 0xCCCC0000;
  v6 = v5 ^ (v5 >> 18) ^ v3;
  v7 = (v4 ^ (v4 << 18)) & 0xCCCC0000 ^ (((v4 ^ (v4 << 18)) & 0xCCCC0000) >> 18) ^ v4;
  v8 = (v6 ^ (v7 >> 1)) & 0x55555555;
  v9 = v8 ^ v6;
  v10 = 2 * v8 ^ v7;
  v11 = (v10 ^ (v9 >> 8)) & 0xFF00FF;
  v12 = v11 ^ v10;
  v13 = (v11 << 8) ^ v9;
  v14 = k;
  v15 = (v13 ^ (v12 >> 1)) & 0x55555555;
  v16 = v15 ^ v13;
  v17 = (2 * v15 ^ v12) & 0xFF00 | ((unsigned __int8)(2 * v15 ^ v12) << 16) | ((v16 & 0xF000000F | ((2 * v15 ^ v12) >> 12) & 0xFF0) >> 4);
  v18 = v16 & 0xFFFFFFF;
  v19 = 0;
  ka = 0;
  do
  {
    if ( double_shift[v19] )
    {
      v20 = v18 << 26;
      v21 = v18 >> 2;
      v22 = v17 << 26;
      v23 = v17 >> 2;
    }
    else
    {
      v20 = v18 << 27;
      v21 = v18 >> 1;
      v22 = v17 << 27;
      v23 = v17 >> 1;
    }
    v18 = (v20 | v21) & 0xFFFFFFF;
    v17 = (v22 | v23) & 0xFFFFFFF;
    v24 = &v14->keytab[0][1];
    v25 = (*(_DWORD *)(4 * (v17 & 0x3F) - 2147190128) | *(_DWORD *)(4 * ((v17 >> 15) & 0x3F) - 2147189616) | *(_DWORD *)(4 * ((v17 & 0x1E00000 | (v17 >> 1) & 0x6000000) >> 21) - 2147189360) | *(_DWORD *)(4 * ((v17 & 0x180 | (v17 >> 1) & 0x1E00) >> 7) - 2147189872)) & 0xFFFF0000 | ((*(_DWORD *)(4 * (v18 & 0x3F) - 2147191152) | *(_DWORD *)(4 * ((v18 & 0xC0 | (v18 >> 1) & 0xF00) >> 6) - 2147190896) | (unsigned int)(*(_DWORD *)(4 * (((v18 >> 1) & 0x60000 | v18 & 0x1E000) >> 13) - 2147190640) | *(_DWORD *)(4 * ((v18 & 0x100000 | ((v18 & 0xC00000 | (v18 >> 1) & 0x7000000) >> 1)) >> 20) - 2147190384))) >> 16);
    *(v24 - 1) = __ROL4__(
                   ((*(_DWORD *)(4 * (v17 & 0x3F) - 2147190128) | *(_DWORD *)(4 * ((v17 >> 15) & 0x3F) - 2147189616) | *(_DWORD *)(4 * ((v17 & 0x1E00000 | (v17 >> 1) & 0x6000000) >> 21) - 2147189360) | *(_DWORD *)(4 * ((v17 & 0x180 | (v17 >> 1) & 0x1E00) >> 7) - 2147189872)) << 16) | (unsigned __int16)(*(_WORD *)(4 * (v18 & 0x3F) - 2147191152) | *(_WORD *)(4 * ((v18 & 0xC0 | (v18 >> 1) & 0xF00) >> 6) - 2147190896) | *(_WORD *)(4 * (((v18 >> 1) & 0x60000 | v18 & 0x1E000) >> 13) - 2147190640) | *(_WORD *)(4 * ((v18 & 0x100000 | ((v18 & 0xC00000 | (v18 >> 1) & 0x7000000) >> 1)) >> 20) - 2147190384)),
                   2);
    *v24 = __ROL4__(v25, 6);
    v14 = (_destable *)(v24 + 1);
    v19 = (int)&ka->keytab[0][0] + 1;
    ka = (_destable *)((char *)ka + 1);
  }
  while ( (unsigned int)ka < 0x10 );
}
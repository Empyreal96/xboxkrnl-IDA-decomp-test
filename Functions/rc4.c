_BYTE *__stdcall rc4(int a1, unsigned int a2, _BYTE *a3)
{
  _BYTE *v3; // edi
  int v4; // ecx
  unsigned int v5; // ebp
  int v6; // edx
  _BYTE *v7; // eax
  int *v8; // eax
  unsigned int v9; // ebp
  int v10; // edi
  int v11; // ecx
  char v12; // al
  int v13; // edx
  char v14; // bl
  int v15; // edi
  int v16; // ecx
  char v17; // al
  int v18; // edx
  char v19; // bl
  int v20; // edi
  int v21; // ecx
  char v22; // al
  int v23; // edx
  char v24; // bl
  int v25; // edi
  char v26; // al
  char v27; // bl
  int v28; // edi
  int v29; // eax
  char v30; // bl
  _BYTE *result; // eax
  _BYTE *v32; // [esp+1Ch] [ebp+Ch]

  v3 = a3;
  v4 = *(unsigned __int8 *)(a1 + 256);
  v5 = a2;
  v6 = *(unsigned __int8 *)(a1 + 257);
  if ( a2 )
  {
    if ( !(a2 >> 2) || (unsigned __int8)a3 & 3 )
      goto rc4_loop;
    v7 = a3;
    v32 = &a3[4 * (a2 >> 2)];
    v8 = (int *)(v7 - 4);
    v9 = a2 >> 2;
    do
    {
      v10 = v8[1];
      v11 = (unsigned __int8)(v4 + 1);
      v12 = *(_BYTE *)(a1 + v11);
      v13 = (unsigned __int8)(v12 + v6);
      v14 = *(_BYTE *)(a1 + v13);
      *(_BYTE *)(a1 + v11) = v14;
      *(_BYTE *)(a1 + v13) = v12;
      v15 = *(unsigned __int8 *)(a1 + (unsigned __int8)(v14 + v12)) ^ v10;
      v16 = (unsigned __int8)(v11 + 1);
      v17 = *(_BYTE *)(a1 + v16);
      v18 = (unsigned __int8)(v17 + v13);
      v19 = *(_BYTE *)(a1 + v18);
      *(_BYTE *)(a1 + v16) = v19;
      *(_BYTE *)(a1 + v18) = v17;
      v20 = (*(unsigned __int8 *)(a1 + (unsigned __int8)(v19 + v17)) << 8) ^ v15;
      v21 = (unsigned __int8)(v16 + 1);
      v22 = *(_BYTE *)(a1 + v21);
      v23 = (unsigned __int8)(v22 + v18);
      v24 = *(_BYTE *)(a1 + v23);
      *(_BYTE *)(a1 + v21) = v24;
      *(_BYTE *)(a1 + v23) = v22;
      v25 = (*(unsigned __int8 *)(a1 + (unsigned __int8)(v24 + v22)) << 16) ^ v20;
      v4 = (unsigned __int8)(v21 + 1);
      v26 = *(_BYTE *)(a1 + v4);
      v6 = (unsigned __int8)(v26 + v23);
      v27 = *(_BYTE *)(a1 + v6);
      *(_BYTE *)(a1 + v4) = v27;
      *(_BYTE *)(a1 + v6) = v26;
      v28 = (*(unsigned __int8 *)(a1 + (unsigned __int8)(v27 + v26)) << 24) ^ v25;
      v8 = (int *)&v32[-4 * v9];
      *v8 = v28;
      --v9;
    }
    while ( v9 );
    v5 = a2 & 3;
    if ( a2 & 3 )
    {
      v3 = v8 + 1;
      do
      {
rc4_loop:
        v4 = (v4 + 1) & 0xFF;
        v29 = *(unsigned __int8 *)(a1 + v4);
        v6 = (v29 + v6) & 0xFF;
        v30 = *(_BYTE *)(a1 + v6);
        *(_BYTE *)(a1 + v4) = v30;
        *(_BYTE *)(a1 + v6) = v29;
        *v3++ ^= *(_BYTE *)(a1 + (unsigned __int8)(v30 + v29));
        --v5;
      }
      while ( v5 );
      goto rc4_done;
    }
  }
rc4_done:
  result = (_BYTE *)(a1 + 256);
  *result = v4;
  result[1] = v6;
  return result;
}
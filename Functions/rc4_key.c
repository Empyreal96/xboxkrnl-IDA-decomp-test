char __stdcall rc4_key(int a1, unsigned __int8 a2, _BYTE *a3)
{
  int v3; // eax
  signed int v4; // ecx
  int v5; // edx
  int v6; // ebp
  int *v7; // edx
  int v8; // eax
  int v9; // ebp
  _BYTE *v10; // ebp
  _BYTE *v11; // edi
  int v12; // ebx
  int v13; // ecx
  char v14; // dl
  char v15; // dl
  char v16; // dl
  char v17; // dl
  char result; // al
  char v19; // dl

  v3 = 50462976;
  v4 = 16;
  v5 = a1;
  v6 = 117835012;
  do
  {
    *(_DWORD *)v5 = v3;
    v7 = (int *)(v5 + 8);
    v8 = v3 + 134744072;
    *(v7 - 1) = v6;
    v9 = v6 + 134744072;
    *v7 = v8;
    v5 = (int)(v7 + 2);
    v3 = v8 + 134744072;
    *(_DWORD *)(v5 - 4) = v9;
    v6 = v9 + 134744072;
    --v4;
  }
  while ( v4 );
  v10 = a3;
  *(_BYTE *)v5 = 0;
  v11 = &a3[a2];
  *(_BYTE *)(v5 + 1) = 0;
  v12 = 0;
  v13 = 0;
  if ( a2 & 3 )
  {
    do
    {
      v19 = *(_BYTE *)(v13 + a1);
      LOBYTE(v12) = *v10++ + v12;
      LOBYTE(v12) = v19 + v12;
      result = *(_BYTE *)(v12 + a1);
      *(_BYTE *)(v13 + a1) = result;
      *(_BYTE *)(v12 + a1) = v19;
      if ( v10 == v11 )
        v10 = a3;
      ++v13;
    }
    while ( v13 != 256 );
  }
  else
  {
    do
    {
      v14 = *(_BYTE *)(v13 + a1);
      LOBYTE(v12) = v14 + *v10 + v12;
      *(_BYTE *)(v13 + a1) = *(_BYTE *)(v12 + a1);
      *(_BYTE *)(v12 + a1) = v14;
      v15 = *(_BYTE *)(v13 + a1 + 1);
      LOBYTE(v12) = v15 + v10[1] + v12;
      *(_BYTE *)(v13 + a1 + 1) = *(_BYTE *)(v12 + a1);
      *(_BYTE *)(v12 + a1) = v15;
      v16 = *(_BYTE *)(v13 + a1 + 2);
      LOBYTE(v12) = v16 + v10[2] + v12;
      *(_BYTE *)(v13 + a1 + 2) = *(_BYTE *)(v12 + a1);
      *(_BYTE *)(v12 + a1) = v16;
      v17 = *(_BYTE *)(v13 + a1 + 3);
      LOBYTE(v12) = v17 + v10[3] + v12;
      result = *(_BYTE *)(v12 + a1);
      *(_BYTE *)(v13 + a1 + 3) = result;
      v10 += 4;
      *(_BYTE *)(v12 + a1) = v17;
      if ( v10 == v11 )
        v10 = a3;
      LOBYTE(v13) = v13 + 4;
    }
    while ( (_BYTE)v13 );
  }
  return result;
}
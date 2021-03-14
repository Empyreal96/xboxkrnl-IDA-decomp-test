void __stdcall D3DK::InitializeVertexShaderFromFvf(D3DK::VertexShader *pVertexShader, unsigned int Fvf)
{
  D3DK::VertexShader *v2; // edi
  unsigned int *v3; // edx
  unsigned int *v4; // eax
  signed int v5; // ecx
  unsigned int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // esi
  unsigned int v10; // edi
  unsigned int v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // edi
  unsigned int *v14; // edx
  _DWORD *v15; // ecx
  unsigned int v16; // eax
  int v17; // ebx
  unsigned int numTextures; // [esp+18h] [ebp+Ch]
  unsigned int numTexturesa; // [esp+18h] [ebp+Ch]

  memset(pVertexShader, 0, sizeof(D3DK::VertexShader));
  v2 = pVertexShader + 1;
  v3 = &pVertexShader->Slot[0].SizeAndType;
  v4 = &pVertexShader->Slot[0].SizeAndType;
  v5 = 16;
  do
  {
    *v4 = 2;
    v4 += 4;
    --v5;
  }
  while ( v5 );
  v6 = Fvf;
  v7 = Fvf & 0xE;
  v8 = 0;
  if ( v7 == 4 )
  {
    pVertexShader->Flags |= 2u;
    *v3 = 66;
    v8 = 16;
    goto LABEL_15;
  }
  if ( Fvf & 0xE )
  {
    *v3 = 50;
    v8 = 12;
    if ( v7 >= 6 )
    {
      v9 = ((v7 - 6) >> 1) + 1;
      if ( v7 == 6 )
      {
        if ( v9 == 1 )
        {
LABEL_14:
          pVertexShader->Slot[1].Offset = 12;
          pVertexShader->Slot[1].SizeAndType = 16 * v9 | 2;
          v8 = 4 * v9 + 12;
          goto LABEL_15;
        }
        D3DK::DXGRIP((int *)v2, "Assertion failure: %s", "weights == 1");
      }
      else
      {
        if ( v7 != 12 || v9 == 4 )
          goto LABEL_14;
        D3DK::DXGRIP((int *)v2, "Assertion failure: %s", "weights == 4");
      }
      v6 = Fvf;
      goto LABEL_14;
    }
  }
LABEL_15:
  if ( v6 & 0x10 )
  {
    pVertexShader->Slot[2].Offset = v8;
    pVertexShader->Slot[2].SizeAndType = 50;
    v8 += 12;
  }
  if ( v6 & 0x40 )
  {
    v10 = pVertexShader->Flags | 0x400;
    pVertexShader->Slot[3].Offset = v8;
    pVertexShader->Slot[3].SizeAndType = 64;
    pVertexShader->Flags = v10;
    v8 += 4;
  }
  if ( (v6 & 0x80u) != 0 )
  {
    v11 = pVertexShader->Flags | 0x800;
    pVertexShader->Slot[4].Offset = v8;
    pVertexShader->Slot[4].SizeAndType = 64;
    pVertexShader->Flags = v11;
    v8 += 4;
  }
  v12 = (v6 >> 8) & 0xF;
  numTextures = v12;
  v13 = v6 >> 16;
  pVertexShader->TextureCount = v12;
  if ( v12 > 4 )
  {
    D3DK::DXGRIP((int *)v13, "Assertion failure: %s", "numTextures <= D3DDP_MAXTEXCOORD");
    v12 = numTextures;
  }
  if ( v12 )
  {
    v14 = pVertexShader->Dimensionality;
    v15 = &pVertexShader->Slot[16].SizeAndType;
    numTexturesa = v12;
    do
    {
      v16 = *(_DWORD *)(4 * (v13 & 3) - 2146976680);
      v17 = 16 * *(_DWORD *)(4 * (v13 & 3) - 2146976680);
      *(v15 - 1) = v8;
      *v14 = v16;
      v8 += 4 * v16;
      *v15 = v17 | 2;
      ++v14;
      v15 += 4;
      v13 >>= 2;
      --numTexturesa;
    }
    while ( numTexturesa );
  }
}
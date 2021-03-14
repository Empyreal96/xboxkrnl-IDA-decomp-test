void __usercall D3DK::CDevice::SetStateUP(D3DK::CDevice *this@<ecx>, int *a2@<edi>)
{
  D3DK::CDevice *v2; // esi
  unsigned int v3; // eax
  D3DK::VertexShader *v4; // edx
  int *v5; // edi
  unsigned int v6; // ecx
  unsigned int v7; // eax
  D3DK::VertexShaderSlot *v8; // eax
  int *v9; // edi
  int *v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // edi
  unsigned int *v16; // ecx
  unsigned int *v17; // ebx
  unsigned int v18; // eax
  int v19; // esi
  unsigned int v20; // eax
  bool v21; // zf
  unsigned int v22; // ecx
  unsigned int *v23; // eax
  unsigned int *v24; // esi
  unsigned int *v25; // esi
  unsigned int *v26; // eax
  signed int v27; // ecx
  int *v28; // [esp-8h] [ebp-24h]
  D3DK::CDevice *pDevice; // [esp+8h] [ebp-14h]
  unsigned int textureCount; // [esp+Ch] [ebp-10h]
  unsigned int textureCounta; // [esp+Ch] [ebp-10h]
  int v32; // [esp+10h] [ebp-Ch]
  D3DK::VertexShader *pVertexShader; // [esp+14h] [ebp-8h]
  unsigned int totalDwords; // [esp+18h] [ebp-4h]
  unsigned int totalDwordsa; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h]

  v2 = this;
  pDevice = this;
  if ( D3DK::g_WhackState )
    this->m_DirtyFlags |= 0x7FFu;
  D3DK::SetState((int)&savedregs, a2);
  v3 = v2->m_DirtyFlags;
  if ( v3 & 0x100 )
  {
    v4 = v2->m_pVertexShader;
    v2->m_DirtyFlags = v3 & 0xFFFFFEFF | 0x80;
    v28 = a2;
    pVertexShader = v4;
    if ( !(v4->Flags & 4) )
    {
      v5 = (int *)&v4->Slot[9].SizeAndType;
      textureCount = v4->TextureCount;
      totalDwords = (unsigned int)&v4->Slot[9].SizeAndType;
      v6 = 0;
      do
      {
        v7 = dword_800C2238[v6] & 0xFFFF;
        if ( v7 >= textureCount )
        {
          *v5 = 2;
        }
        else
        {
          v8 = &v4->Slot[v7 + 16];
          v9 = v5 - 2;
          *v9 = v8->StreamIndex;
          v9[1] = v8->Offset;
          v9[2] = v8->SizeAndType;
          v9[3] = *(_DWORD *)&v8->Flags;
          v5 = (int *)totalDwords;
        }
        v6 += 32;
        v5 += 4;
        totalDwords = (unsigned int)v5;
      }
      while ( v6 < 128 );
      v10 = (int *)XMETAL_StartPush(v5, &v2->m_Pusher);
      v11 = pVertexShader->Flags;
      if ( !(v11 & 0x400) )
      {
        XMETAL_Push1f(v10, (unsigned int *)v10, 0x194Cu, -6.8056469e38/*NaN*/);
        v10 += 2;
      }
      v12 = pVertexShader->Flags;
      if ( !(v12 & 0x800) )
      {
        XMETAL_Push1f(v10, (unsigned int *)v10, 0x1950u, 0.0);
        v10 += 2;
      }
      v13 = pVertexShader->Flags;
      if ( !(v13 & 0x1000) )
      {
        XMETAL_Push1f(v10, (unsigned int *)v10, 0x195Cu, -6.8056469e38/*NaN*/);
        v10 += 2;
      }
      v14 = pVertexShader->Flags;
      if ( !(v14 & 0x2000) )
      {
        XMETAL_Push1f(v10, (unsigned int *)v10, 0x1960u, 0.0);
        v10 += 2;
      }
      XMETAL_EndPush(v10, &v2->m_Pusher, (unsigned int *)v10);
      v4 = pVertexShader;
    }
    v15 = 0;
    v16 = &v4->Slot[0].Offset;
    totalDwordsa = 0;
    v17 = &v2->m_InlineAttributeData[0].UP_Delta;
    v32 = (int)&v4->Slot[0].Offset;
    textureCounta = 16;
    do
    {
      v18 = v16[1];
      if ( v18 != 2 )
      {
        v19 = (unsigned __int8)D3DK::g_BytesPerUnit[v16[1] & 0xF]
            * (unsigned __int8)D3DK::g_UnitsOfElement[(unsigned __int8)v16[1] >> 4];
        if ( !v19 )
        {
          D3DK::DXGRIP((int *)v15, "Assertion failure: %s", "bytes != 0");
          v16 = (unsigned int *)v32;
        }
        v20 = (unsigned int)(v19 + 3) >> 2;
        *(v17 - 1) = v20;
        *v17 = *v16;
        totalDwordsa += v20;
        v2 = pDevice;
        ++v15;
        v17 += 2;
      }
      v16 += 4;
      v21 = textureCounta == 1;
      v32 = (int)v16;
      --textureCounta;
    }
    while ( !v21 );
    if ( !v15 )
      D3DK::DXGRIP(0, "Assertion failure: %s", "attributeCount > 0");
    if ( totalDwordsa <= 1 )
      D3DK::DXGRIP(
        (int *)v15,
        "Inline vertices of size 1 DWORD don't work on the NV2A.\n"
        "The workaround is to pad the vertex to fill 2 DWORDs (e.g.,\n"
        "append an unused attribute)\n");
    v22 = v2->m_InlineAttributeData[0].UP_Delta;
    v2->m_InlineVertexDwords = totalDwordsa;
    v23 = &v2->m_InlineAttributeData[0].UP_Delta;
    v2->m_InlineAttributeCount = v15;
    v2->m_InlineStartOffset = v22;
    v2->m_InlineDelta = v22 + -4 * *(&v2->m_InlineStartOffset + 2 * v15) - *(&v2->m_InlineDelta + 2 * v15);
    if ( v15 > 1 )
    {
      --v15;
      do
      {
        *v23 = v23[2] - 4 * *(v23 - 1) - *v23;
        v23 += 2;
        --v15;
      }
      while ( v15 );
    }
    v24 = XMETAL_StartPush((int *)v15, &v2->m_Pusher);
    XMETAL_PushCount((int *)v15, v24, 0x1760u, 0x10u);
    a2 = v28;
    v25 = v24 + 1;
    v26 = &pVertexShader->Slot[0].SizeAndType;
    v27 = 16;
    do
    {
      *v25 = *v26;
      ++v25;
      v26 += 4;
      --v27;
    }
    while ( v27 );
    XMETAL_EndPush(v28, &pDevice->m_Pusher, v25);
  }
  D3DK::PRIMITIVE_LAUNCH_STATE_TEST();
  D3DK::PRIMITIVE_LAUNCH_STATE_TEST2(a2);
  if ( D3DK::g_Dump )
  {
    D3DK::ShowDump(a2, 0);
    __debugbreak();
  }
}
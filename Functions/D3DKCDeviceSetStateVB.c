void __userpurge D3DK::CDevice::SetStateVB(D3DK::CDevice *this@<ecx>, int *a2@<edi>, unsigned int IndexBase)
{
  D3DK::CDevice *v3; // ebx
  unsigned int v4; // eax
  int *v5; // edi
  _DWORD *v6; // edx
  unsigned int v7; // ecx
  unsigned int v8; // eax
  int *v9; // eax
  int *v10; // esi
  unsigned int *v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  signed int v16; // eax
  _DWORD *v17; // ecx
  unsigned int *v18; // esi
  unsigned int *v19; // esi
  int v20; // eax
  signed int v21; // edx
  unsigned int v22; // eax
  D3DK::VertexShader *v23; // esi
  unsigned int v24; // eax
  D3DK::VertexShaderSlot *v25; // esi
  int v26; // ebx
  bool v27; // zf
  int v28; // ebx
  _DWORD *v29; // esi
  int *v30; // [esp-8h] [ebp-20h]
  unsigned int textureCount; // [esp+4h] [ebp-14h]
  unsigned int textureCounta; // [esp+4h] [ebp-14h]
  unsigned int textureCountb; // [esp+4h] [ebp-14h]
  signed int method; // [esp+8h] [ebp-10h]
  signed int methoda; // [esp+8h] [ebp-10h]
  D3DK::CDevice *pDevice; // [esp+Ch] [ebp-Ch]
  unsigned int *pPush; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h]

  v3 = this;
  pDevice = this;
  if ( D3DK::g_WhackState )
    this->m_DirtyFlags |= 0x7FFu;
  D3DK::SetState((int)&savedregs, a2);
  v4 = v3->m_DirtyFlags;
  if ( !(v4 & 0x40000000) )
  {
    v30 = a2;
    if ( (v4 & 0x80u) != 0 )
    {
      v5 = (int *)v3->m_pVertexShader;
      v3->m_DirtyFlags = v4 & 0xBFFFFF7F | 0x300;
      if ( !(v5[2] & 4) )
      {
        textureCount = v5[4];
        v6 = v5 + 49;
        v7 = 0;
        do
        {
          v8 = dword_800C2238[v7] & 0xFFFF;
          if ( v8 >= textureCount )
          {
            *v6 = 2;
          }
          else
          {
            v9 = &v5[4 * v8 + 75];
            v10 = v6 - 2;
            *v10 = *v9;
            v10[1] = v9[1];
            v10[2] = v9[2];
            v3 = pDevice;
            v10[3] = v9[3];
          }
          v7 += 32;
          v6 += 4;
        }
        while ( v7 < 128 );
        v11 = XMETAL_StartPush(v5, &v3->m_Pusher);
        v12 = v5[2];
        if ( !(v12 & 0x400) )
        {
          XMETAL_Push1f(v5, v11, 0x194Cu, -6.8056469e38/*NaN*/);
          v11 += 2;
        }
        v13 = v5[2];
        if ( !(v13 & 0x800) )
        {
          XMETAL_Push1f(v5, v11, 0x1950u, 0.0);
          v11 += 2;
        }
        v14 = v5[2];
        if ( !(v14 & 0x1000) )
        {
          XMETAL_Push1f(v5, v11, 0x195Cu, -6.8056469e38/*NaN*/);
          v11 += 2;
        }
        v15 = v5[2];
        if ( !(v15 & 0x2000) )
        {
          XMETAL_Push1f(v5, v11, 0x1960u, 0.0);
          v11 += 2;
        }
        XMETAL_EndPush(v5, &v3->m_Pusher, v11);
      }
      v16 = 15;
      v17 = v5 + 73;
      do
      {
        if ( *v17 != 2 )
          break;
        --v16;
        v17 -= 4;
      }
      while ( v16 );
      v5[3] = v16;
      v18 = XMETAL_StartPush(v5, &v3->m_Pusher);
      XMETAL_PushCount(v5, v18, 0x1760u, 0x10u);
      v19 = v18 + 1;
      v20 = (int)(v5 + 13);
      v21 = 2;
      do
      {
        *v19 = *(_DWORD *)v20 + (*(_DWORD *)(12 * *(_DWORD *)(v20 - 8) - 2146689320) << 8);
        v19[1] = *(_DWORD *)(v20 + 16) + (*(_DWORD *)(12 * *(_DWORD *)(v20 + 8) - 2146689320) << 8);
        v19[2] = *(_DWORD *)(v20 + 32) + (*(_DWORD *)(12 * *(_DWORD *)(v20 + 24) - 2146689320) << 8);
        v19[3] = *(_DWORD *)(v20 + 48) + (*(_DWORD *)(12 * *(_DWORD *)(v20 + 40) - 2146689320) << 8);
        v19[4] = *(_DWORD *)(v20 + 64) + (*(_DWORD *)(12 * *(_DWORD *)(v20 + 56) - 2146689320) << 8);
        v19[5] = *(_DWORD *)(v20 + 80) + (*(_DWORD *)(12 * *(_DWORD *)(v20 + 72) - 2146689320) << 8);
        v19[6] = *(_DWORD *)(v20 + 96) + (*(_DWORD *)(12 * *(_DWORD *)(v20 + 88) - 2146689320) << 8);
        a2 = *(int **)(v20 + 112);
        v19[7] = (unsigned int)&a2[64 * *(_DWORD *)(12 * *(_DWORD *)(v20 + 104) - 2146689320)];
        v20 += 128;
        v19 += 8;
        --v21;
      }
      while ( v21 );
      XMETAL_EndPush(a2, &v3->m_Pusher, v19);
    }
    v22 = v3->m_DirtyFlags;
    if ( v22 & 0x200 || v3->m_CachedIndexBase != IndexBase )
    {
      v23 = v3->m_pVertexShader;
      v3->m_DirtyFlags = v22 & 0xBFFFFDFF;
      v3->m_CachedIndexBase = IndexBase;
      pPush = XMETAL_StartPush(a2, &v3->m_Pusher);
      v24 = v23->MaxSlot;
      if ( IndexBase )
      {
        methoda = 5920;
        a2 = (int *)v23->Slot;
        textureCountb = v24 + 1;
        do
        {
          if ( a2[2] != 2 )
          {
            v28 = *(_DWORD *)(12 * *a2 - 2146689312);
            v29 = (_DWORD *)(12 * *a2 - 2146689320);
            if ( v28 )
            {
              if ( *(_DWORD *)(v28 + 4) > 0x4000000u )
              {
                DbgPrint(a2, "DebugVerifyPhysical - Not a valid physical memory offset.");
                DbgPrint(a2, "\n");
                __debugbreak();
              }
              XMETAL_Push1f(a2, pPush, methoda, COERCE_FLOAT(*(_DWORD *)(v28 + 4) + v29[1] + a2[1] + IndexBase * *v29));
              pPush += 2;
            }
            v3 = pDevice;
          }
          a2 += 4;
          v27 = textureCountb == 1;
          methoda += 4;
          --textureCountb;
        }
        while ( !v27 );
      }
      else
      {
        v25 = v23->Slot;
        method = 5920;
        textureCounta = v24 + 1;
        do
        {
          if ( v25->SizeAndType != 2 )
          {
            a2 = *(int **)(12 * v25->StreamIndex - 2146689312);
            v26 = 12 * v25->StreamIndex - 2146689320;
            if ( a2 )
            {
              if ( (unsigned int)a2[1] > 0x4000000 )
              {
                DbgPrint(a2, "DebugVerifyPhysical - Not a valid physical memory offset.");
                DbgPrint(a2, "\n");
                __debugbreak();
              }
              XMETAL_Push1f(a2, pPush, method, COERCE_FLOAT(a2[1] + *(_DWORD *)(v26 + 4) + v25->Offset));
              pPush += 2;
            }
            v3 = pDevice;
          }
          ++v25;
          v27 = textureCounta == 1;
          method += 4;
          --textureCounta;
        }
        while ( !v27 );
      }
      XMETAL_EndPush(a2, &v3->m_Pusher, pPush);
    }
    D3DK::PRIMITIVE_LAUNCH_STATE_TEST();
    D3DK::PRIMITIVE_LAUNCH_STATE_TEST2(a2);
    if ( D3DK::g_Dump )
    {
      D3DK::ShowDump(v30, 0);
      __debugbreak();
    }
  }
}
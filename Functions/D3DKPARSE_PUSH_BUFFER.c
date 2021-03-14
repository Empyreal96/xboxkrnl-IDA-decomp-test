// write access to const memory has been detected, the output may be wrong!
void D3DK::PARSE_PUSH_BUFFER()
{
  D3DK::CDevice *v0; // eax
  unsigned int *i; // esi
  unsigned int v2; // eax
  int v3; // edx
  int v4; // edi
  unsigned int v5; // ebx
  unsigned int v6; // ecx
  unsigned int v7; // esi
  unsigned int instruction; // [esp+0h] [ebp-8h]

  v0 = D3DK::g_pDevice;
  if ( D3D__Parser && !(D3DK::g_pDevice->m_StateFlags & 4) )
  {
    for ( i = D3DK::g_ParsePut; i != D3DK::g_pDevice->m_Pusher.m_pPut; v0 = D3DK::g_pDevice )
    {
      v2 = *i;
      instruction = *i >> 29;
      v3 = *i & 3;
      v4 = (*i >> 18) & 0x7FF;
      v5 = (unsigned __int16)*i;
      v6 = *i & 0x1FFFFFFC;
      ++i;
      if ( v3 == 1 || v3 == 2 )
      {
        if ( D3DK::g_IgnorePushBufferJump )
        {
          i += 4;
          D3DK::g_IgnorePushBufferJump = 0;
        }
        else
        {
          v7 = v2 & 0xFFFFFFFC;
          if ( (v2 & 0xFFFFFFFC) > 0x4000000 )
          {
            DbgPrint((int *)v4, "DebugVerifyPhysical - Not a valid physical memory offset.");
            DbgPrint((int *)v4, "\n");
            __debugbreak();
          }
          i = (unsigned int *)(v7 | 0x80000000);
        }
      }
      else if ( instruction )
      {
        if ( instruction == 1 )
        {
          i = &D3DK::g_pDevice->m_pPushBase[v6 >> 2];
        }
        else if ( instruction == 2 )
        {
          D3DK::ParseMethodWrite((int *)v4, (unsigned __int16)v2, i, (v2 >> 18) & 0x7FF);
          i += v4;
        }
        else
        {
          D3DK::DXGRIP((int *)v4, "Unexpected push-buffer instruction: 0x%lx  at: 0x%lx", v2, i - 1);
        }
      }
      else
      {
        for ( ; v4; --v4 )
        {
          D3DK::ParseMethodWrite((int *)v4, v5, i, 1u);
          ++i;
          v5 += 4;
        }
      }
    }
    D3DK::g_ParsePut = v0->m_Pusher.m_pPut;
  }
}
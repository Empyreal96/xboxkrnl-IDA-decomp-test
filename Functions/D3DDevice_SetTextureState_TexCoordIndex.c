// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(unsigned int Stage, unsigned int Value)
{
  unsigned int v2; // ecx
  signed int v3; // eax
  int *v4; // edi
  unsigned int v5; // edx
  unsigned int *v6; // ebx

  ++D3DK::g_PerfCounters.m_APICounters[169];
  if ( (unsigned __int16)Value >= 4u )
    D3DK::DXGRIP((int *)Value, "Index can't be D3DDP_MAXTEXCOORD (4) or more");
  dword_800C2238[32 * Stage] = Value;
  v2 = Value & 0xFFFF0000;
  v3 = 0;
  if ( (Value & 0xFFFF0000) > 0x20000 )
  {
    if ( v2 == 196608 )
    {
      v4 = (int *)34066;
      goto LABEL_17;
    }
    if ( v2 != 0x40000 )
    {
LABEL_12:
      if ( v2 != 327680 )
        D3DK::DXGRIP((int *)Value, "Assertion failure: %s", "(Value & 0xffff0000) == D3DTSS_TCI_SPHERE");
      v4 = (int *)9218;
      goto LABEL_17;
    }
    v4 = (int *)9217;
  }
  else if ( (Value & 0xFFFF0000) == 0x20000 )
  {
    v4 = (int *)9216;
  }
  else
  {
    if ( v2 )
    {
      if ( v2 == 0x10000 )
      {
        v4 = (int *)34065;
LABEL_17:
        v3 = 1;
        goto LABEL_18;
      }
      goto LABEL_12;
    }
    D3DK::g_pDevice->m_DirtyFlags |= 0x180u;
    v4 = 0;
  }
LABEL_18:
  v5 = D3DK::g_pDevice->m_TexGenInverseNeeded;
  if ( !v5 && v3 )
    D3DK::g_pDevice->m_DirtyFlags |= 2u;
  D3DK::g_pDevice->m_TexGenInverseNeeded = (v3 << Stage) | v5 & ~(1 << Stage);
  v6 = XMETAL_StartPush(v4, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push3f(v4, v6, 16 * (Stage + 60), *(float *)&v4, *(float *)&v4, *(float *)&v4);
  XMETAL_EndPush(v4, &D3DK::g_pDevice->m_Pusher, v6 + 4);
  D3DK::g_pDevice->m_DirtyFlags |= 0x194u;
}
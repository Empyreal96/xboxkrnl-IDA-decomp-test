// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetTextureState_BumpEnv(int *a1@<edi>, unsigned int Stage, _D3DTEXTURESTAGESTATETYPE Type, unsigned int Value)
{
  unsigned int v4; // ebx
  unsigned int *v5; // esi

  ++D3DK::g_PerfCounters.m_APICounters[165];
  if ( (signed int)Type < 22 || (signed int)Type > 27 )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "(Type >= D3DTSS_BUMPENVMAT00) && (Type <= D3DTSS_BUMPENVLOFFSET)");
  v4 = Stage;
  if ( !D3DK::g_pDevice->m_pPixelShader )
    v4 = Stage + 1;
  if ( v4 & 3 )
  {
    v5 = XMETAL_StartPush((int *)Stage, &D3DK::g_pDevice->m_Pusher);
    XMETAL_Push1f((int *)Stage, v5, 4 * (Type + 16 * v4) + 6864, *(float *)&Value);
    XMETAL_EndPush((int *)Stage, &D3DK::g_pDevice->m_Pusher, v5 + 2);
  }
  *(_DWORD *)(4 * (Type + 32 * Stage) - 2146688568) = Value;
}
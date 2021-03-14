// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetVertexShaderConstant(int Register, const void *pConstantData, unsigned int ConstantCount)
{
  unsigned int v3; // eax
  int *v4; // edi
  unsigned int v5; // eax
  char *v6; // esi
  signed int v7; // eax
  _DWORD *i; // edi
  unsigned int *pPush; // [esp+14h] [ebp+8h]
  int *pPusha; // [esp+14h] [ebp+8h]
  unsigned int totalCount; // [esp+1Ch] [ebp+10h]

  ++D3DK::g_PerfCounters.m_APICounters[180];
  if ( !pConstantData )
    D3DK::DXGRIP((int *)Register, "NULL pointer");
  if ( !ConstantCount || ConstantCount > 0x88 )
    D3DK::DXGRIP((int *)Register, "Invalid count");
  if ( Register < -96 || (signed int)(Register + ConstantCount) > 96 )
    D3DK::DXGRIP((int *)Register, "Invalid address range (not between -96 and 95)");
  if ( D3DK::g_pDevice->m_ConstantMode )
  {
    v3 = D3DK::g_pDevice->m_StateFlags;
    if ( !(v3 & 0x200) && Register <= -37 && (signed int)(Register + ConstantCount) > -38 )
      D3DK::DXGRIP(
        (int *)Register,
        "Address range can't include reserved addresses -38 or -37 (D3DVS_XBOX_RESERVEDCONSTANT1 \n"
        "and D3DVS_XBOX_RESERVEDCONSTANT2)");
  }
  else if ( Register < 0 )
  {
    D3DK::DXGRIP((int *)Register, "Negative addresses allowed only if not D3DSCM_96CONSTANTS");
  }
  v4 = (int *)(Register + 96);
  v5 = 4 * ConstantCount;
  totalCount = 4 * ConstantCount;
  if ( !(D3DK::g_pDevice->m_StateFlags & 0x10) )
    qmemcpy((char *)D3DK::g_pDevice + 16 * (Register + 300), pConstantData, 4 * v5);
  pPush = XMETAL_StartPushCount(v4, &D3DK::g_pDevice->m_Pusher, v5 + 26);
  XMETAL_Push1f(v4, pPush, 0x1EA4u, *(float *)&v4);
  v6 = (char *)pConstantData;
  v7 = totalCount;
  for ( i = pPush + 3; v7 > 32; v7 -= 32 )
  {
    *(i - 1) = 8391552;
    qmemcpy(i, v6, 0x80u);
    v6 += 128;
    i += 33;
  }
  *(i - 1) = (v7 << 18) | 0xB80;
  qmemcpy(i, v6, 4 * v7);
  pPusha = &i[v7];
  D3DK::PushedRaw(pPusha, (unsigned int *)pPusha);
  XMETAL_EndPush(pPusha, &D3DK::g_pDevice->m_Pusher, (unsigned int *)pPusha);
}
// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_Begin(_D3DPRIMITIVETYPE PrimitiveType)
{
  unsigned int *v1; // ebx
  int savedregs; // [esp+Ch] [ebp+0h]

  ++D3DK::g_PerfCounters.m_APICounters[12];
  if ( (signed int)PrimitiveType > 10 || PrimitiveType == 0 )
    D3DK::DXGRIP((int *)PrimitiveType, "Invalid primitive type");
  if ( D3DK::g_CurrentPrimitiveType )
    D3DK::DXGRIP((int *)PrimitiveType, "D3DDevice_Begin - Begin before a previous Begin has been Ended.");
  D3DK::g_CurrentPrimitiveType = PrimitiveType;
  D3DK::SetState((int)&savedregs, (int *)PrimitiveType);
  v1 = XMETAL_StartPush((int *)PrimitiveType, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f((int *)PrimitiveType, v1, 0x17FCu, *(float *)&PrimitiveType);
  XMETAL_EndPush((int *)PrimitiveType, &D3DK::g_pDevice->m_Pusher, v1 + 2);
  g_StartPut = D3DK::g_pDevice->m_Pusher.m_pPut;
  if ( D3DK::g_pDevice->m_StateFlags & 0x800 )
    D3DK::DXGRIP((int *)0x800, "Assertion failure: %s", "!(m_StateFlags & STATE_BEGINENDBRACKET)");
  D3DK::g_pDevice->m_StateFlags |= 0x800u;
}
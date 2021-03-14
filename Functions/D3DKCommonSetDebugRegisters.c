void __usercall D3DK::CommonSetDebugRegisters(D3DK *this@<ecx>, int *a2@<edi>)
{
  unsigned int *v2; // edi

  D3DK::g_pDevice->m_Miniport.m_DebugRegister[5] &= 0xFFFFFFF7;
  D3DK::g_pDevice->m_Miniport.m_DebugRegister[6] &= 0xE7EFFFFF;
  v2 = XMETAL_StartPush(a2, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f((int *)v2, v2, 0x110u, 0.0);
  XMETAL_Push2f(
    (int *)v2,
    v2 + 2,
    0x1D8Cu,
    COERCE_FLOAT(4194452),
    *(float *)&D3DK::g_pDevice->m_Miniport.m_DebugRegister[5]);
  XMETAL_Push1f((int *)v2, v2 + 5, 0x100u, COERCE_FLOAT(800));
  XMETAL_Push2f(
    (int *)v2,
    v2 + 7,
    0x1D8Cu,
    COERCE_FLOAT(4197248),
    *(float *)&D3DK::g_pDevice->m_Miniport.m_DebugRegister[6]);
  XMETAL_Push1f((int *)v2, v2 + 10, 0x100u, COERCE_FLOAT(800));
  XMETAL_EndPush((int *)v2 + 12, &D3DK::g_pDevice->m_Pusher, v2 + 12);
}
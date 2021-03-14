// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_LoadVertexShader(int *a1@<edi>, unsigned int Handle, unsigned int Address)
{
  D3DK::VertexShader *v3; // esi
  int *v4; // edi
  unsigned int *v5; // ebx
  int *v6; // ecx
  unsigned int *v7; // edi
  unsigned int *v8; // ebx
  int *v9; // edi
  unsigned int Handlea; // [esp+18h] [ebp+8h]

  ++D3DK::g_PerfCounters.m_APICounters[102];
  v3 = (D3DK::VertexShader *)(Handle - 1);
  if ( !(Handle & 1) )
    D3DK::DXGRIP(a1, "Must be a vertex shader program, not an FVF");
  if ( v3->Signature != 1450403940 )
    D3DK::DXGRIP(a1, "Invalid vertex shader object (already deleted?)");
  if ( Address >= 0x88 )
    D3DK::DXGRIP(a1, "Start address can't be larger than 135");
  if ( Address + v3->ProgramSize > 0x88 )
    D3DK::DXGRIP(a1, "End address larger than 136");
  memset(&D3DK::g_LoadedVertexShaderSlot[Address], 1u, v3->ProgramSize);
  if ( !(D3DK::g_pDevice->m_StateFlags & 0x10) )
    D3DK::ShadowVertexShaderState(v3, Address);
  v4 = (int *)v3->ProgramAndConstantsDwords;
  Handlea = (unsigned int)v4 + 2;
  v5 = XMETAL_StartPushCount(v4, &D3DK::g_pDevice->m_Pusher, (unsigned int)v4 + 2);
  XMETAL_Push1f(v4, v5, 0x1E9Cu, *(float *)&Address);
  v6 = v4;
  v7 = v5 + 2;
  v8 = &v5[Handlea];
  qmemcpy(v7, v3->ProgramAndConstants, 4 * (_DWORD)v6);
  v9 = (int *)&v7[(_DWORD)v6];
  D3DK::PushedRaw(v9, v8);
  XMETAL_EndPush(v9, &D3DK::g_pDevice->m_Pusher, v8);
}
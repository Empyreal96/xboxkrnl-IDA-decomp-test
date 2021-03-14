unsigned int __stdcall D3DK::SetFence(unsigned int Flags)
{
  unsigned int *v1; // eax
  unsigned int v2; // ebx
  unsigned int *v3; // esi
  unsigned int v4; // ecx
  int v5; // eax
  int v6; // edx
  char *v7; // eax
  int v8; // eax
  int v9; // edx
  char *v10; // eax

  if ( D3DK::g_pDevice->m_StateFlags & 4 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "D3DDevice_InsertFence - can't InsertFence while recording a push-buffer.");
  v1 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  v2 = D3DK::g_pDevice->m_CpuTime;
  v3 = v1;
  if ( !(v2 & 1) )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "time & PUSHER_TIME_VALID_FLAG");
  v3[3] = 0;
  v3[5] = 0;
  *v3 = 269680;
  v3[1] = v2;
  v3[2] = 269712;
  v3[4] = 269712;
  D3DK::PushedRaw((int *)D3DK::g_pDevice, v3 + 6);
  XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v3 + 6);
  v4 = D3DK::g_pDevice->m_PusherPutRunSize;
  v5 = (v2 >> 1) & 0x3F;
  v6 = 3 * v5 + 57;
  v7 = (char *)D3DK::g_pDevice + 12 * v5;
  *((_DWORD *)v7 + 58) = v3;
  *((_DWORD *)v7 + 59) = v4;
  *((_DWORD *)&D3DK::g_pDevice->m_Pusher.m_pPut + v6) = v2;
  if ( Flags & 1 )
  {
    v8 = ((unsigned __int8)D3DK::g_pDevice->m_PusherLastSegment + 1) & 0xF;
    D3DK::g_pDevice->m_PusherLastSegment = v8;
    v9 = 3 * v8 + 9;
    v10 = (char *)D3DK::g_pDevice + 12 * v8;
    *((_DWORD *)&D3DK::g_pDevice->m_Pusher.m_pPut + v9) = v2;
    *((_DWORD *)v10 + 10) = v3;
    *((_DWORD *)v10 + 11) = v4;
  }
  if ( !(Flags & 2) )
    D3DK::CDevice::KickOff(D3DK::g_pDevice, (int *)D3DK::g_pDevice);
  D3DK::g_pDevice->m_CpuTime += 2;
  return v2;
}
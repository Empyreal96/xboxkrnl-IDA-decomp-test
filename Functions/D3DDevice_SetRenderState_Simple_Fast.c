// write access to const memory has been detected, the output may be wrong!
void __usercall D3DDevice_SetRenderState_Simple_Fast(unsigned int Method@<eax>, unsigned int Value@<ecx>, unsigned int a3@<edx>, int *a4@<edi>)
{
  unsigned int v4; // ST04_4
  unsigned int v5; // ST00_4

  while ( D3DK::g_Device.m_Pusher.m_pPut + 2 >= D3DK::g_Device.m_Pusher.m_pThreshold )
  {
    v4 = a3;
    v5 = Value;
    D3DK::CDevice::MakeSpace(D3DK::g_pDevice, a4);
    Value = v5;
    a3 = v4;
  }
  D3DK::g_Device.m_Pusher.m_pPut += 2;
  *D3DK::g_Device.m_Pusher.m_pPut = Value;
  D3DK::g_Device.m_Pusher.m_pPut[1] = a3;
}
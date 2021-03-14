// write access to const memory has been detected, the output may be wrong!
unsigned int __stdcall D3DDevice_Release()
{
  unsigned int v0; // eax
  unsigned int result; // eax

  v0 = D3DK::g_pDevice->m_cRefs;
  if ( v0 == 1 )
  {
    D3DK::CDevice::UnInit(D3DK::g_pDevice, (int *)D3DK::g_pDevice);
    result = 0;
    g_pPushBuffer = 0;
    D3DK::g_pDevice = (D3DK::CDevice *)(unsigned __int8)g_pPushBuffer;
    memset(D3DK::g_pDevice, 0, sizeof(D3DK::CDevice));
  }
  else
  {
    result = v0 - 1;
    D3DK::g_pDevice->m_cRefs = result;
  }
  return result;
}
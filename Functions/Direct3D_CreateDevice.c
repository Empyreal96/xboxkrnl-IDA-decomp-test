// write access to const memory has been detected, the output may be wrong!
int __userpurge Direct3D_CreateDevice@<eax>(int *a1@<edi>, unsigned int Adapter, _D3DDEVTYPE DeviceType, void *pUnused, unsigned int Flags, _D3DPRESENT_PARAMETERS_ *pPresentationParams, D3DDevice **ppNewInterface)
{
  int v7; // esi
  int result; // eax

  ++D3DK::g_PerfCounters.m_APICounters[4];
  if ( !pPresentationParams )
    D3DK::DXGRIP(a1, "Invalid D3DPRESENT_PARAMETERS pointer, CreateDevice fails");
  if ( pPresentationParams->BackBufferFormat == -1 )
    D3DK::DXGRIP(a1, "D3DFORMAT_UNKNOWN not allowed on Xbox");
  if ( Adapter > 1 )
    D3DK::DXGRIP(a1, "Invalid Adapter parameter passed to CreateDevice");
  if ( Flags & 0x7FFFFF00 )
    D3DK::DXGRIP(a1, "Invalid BehaviorFlags passed to CreateDevice");
  if ( pPresentationParams->Windowed )
    D3DK::DXGRIP(a1, "Windowed must be FALSE");
  if ( Flags & 0xA0 )
    D3DK::DXGRIP(a1, "Only hardware vertex processing supported");
  if ( DeviceType != 1 )
    D3DK::DXGRIP(a1, "Only HAL devices supported");
  if ( D3DK::g_TextureFormat[pPresentationParams->BackBufferFormat] >= 0 )
    D3DK::DXGRIP(a1, "Only D3DFMT_A8R8G8B8, _X8R8G8B8, _R5G6B5, _X1R5G5B5 (and _LIN versions) supported");
  if ( D3DK::g_pDevice )
    D3DK::DXGRIP(a1, "Can't create more than one D3D device");
  if ( !D3DK::CDevice::m_PushBufferSize )
    D3DK::CDevice::m_PushBufferSize = 0x80000;
  if ( !D3DK::CDevice::m_PushSegmentSize )
    D3DK::CDevice::m_PushSegmentSize = 0x8000;
  D3DK::g_pDevice = &D3DK::g_Device;
  g_pPushBuffer = (_XMETAL_PushBuffer *)&D3DK::g_Device;
  D3DK::g_Device.m_cRefs = 1;
  D3DK::g_Device.m_StateFlags |= Flags & 0x10;
  v7 = D3DK::CDevice::Init(&D3DK::g_Device, a1, (int)pPresentationParams, pPresentationParams);
  if ( v7 >= 0 )
  {
    D3DPERF_Reset(a1);
    if ( ppNewInterface )
      *ppNewInterface = (D3DDevice *)&D3DK::g_Device;
    result = 0;
  }
  else
  {
    D3DK::DXGRIP(a1, "Failed to initialize device object");
    D3DK::CDevice::UnInit(&D3DK::g_Device, a1);
    result = v7;
  }
  return result;
}
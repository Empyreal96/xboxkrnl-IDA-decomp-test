// write access to const memory has been detected, the output may be wrong!
void __userpurge Direct3D_SetPushBufferSize(int *a1@<edi>, unsigned int PushBufferSize, unsigned int KickOffSize)
{
  ++D3DK::g_PerfCounters.m_APICounters[10];
  if ( D3DK::g_pDevice )
    D3DK::DXGRIP(a1, "Direct3D_SetPushBufferSize - Called when there is an active device.");
  if ( (KickOffSize - 1) & KickOffSize )
    D3DK::DXGRIP(a1, "Direct3D_SetPushBufferSize - The KickOffSize must be a power of 2.");
  if ( PushBufferSize < 0x10000 )
    D3DK::DXGRIP((int *)PushBufferSize, "Direct3D_SetPushBufferSize - The PushBufferSize must not be less than 64 KB.");
  if ( KickOffSize < 0x400 )
    D3DK::DXGRIP((int *)PushBufferSize, "Direct3D_SetPushBufferSize - KickOffSize must be no less than 1024 bytes.");
  if ( PushBufferSize % KickOffSize )
    D3DK::DXGRIP(
      (int *)PushBufferSize,
      "Direct3D_SetPushBufferSize - The PushBufferSize must be a multiple of the KickOffSize.");
  if ( PushBufferSize / KickOffSize < 4 )
    D3DK::DXGRIP((int *)PushBufferSize, "Direct3D_SetPushBufferSize - A push buffer must have at least 4 segments.");
  D3DK::CDevice::m_PushBufferSize = PushBufferSize;
  D3DK::CDevice::m_PushSegmentSize = KickOffSize;
}
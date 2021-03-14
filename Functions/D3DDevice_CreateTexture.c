// write access to const memory has been detected, the output may be wrong!
int __userpurge D3DDevice_CreateTexture@<eax>(int *a1@<edi>, int a2@<esi>, unsigned int Width, unsigned int Height, unsigned int Levels, unsigned int Usage, _D3DFORMAT Format, unsigned int Pool, D3DTexture **ppTexture)
{
  ++D3DK::g_PerfCounters.m_APICounters[32];
  return D3DK::CreateTexture(a1, a2, Width, Height, 1u, Levels, Usage, Format, 0, 0, (D3DBaseTexture **)ppTexture);
}
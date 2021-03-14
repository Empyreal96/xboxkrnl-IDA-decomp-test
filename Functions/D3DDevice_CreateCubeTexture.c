// write access to const memory has been detected, the output may be wrong!
int __userpurge D3DDevice_CreateCubeTexture@<eax>(int *a1@<edi>, int a2@<esi>, unsigned int EdgeLength, unsigned int Levels, unsigned int Usage, _D3DFORMAT Format, unsigned int Pool, D3DCubeTexture **ppCubeTexture)
{
  ++D3DK::g_PerfCounters.m_APICounters[22];
  return D3DK::CreateTexture(
           a1,
           a2,
           EdgeLength,
           EdgeLength,
           1u,
           Levels,
           Usage,
           Format,
           1,
           0,
           (D3DBaseTexture **)ppCubeTexture);
}
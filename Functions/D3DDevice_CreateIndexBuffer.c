// write access to const memory has been detected, the output may be wrong!
int __userpurge D3DDevice_CreateIndexBuffer@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int Length, unsigned int Usage, _D3DFORMAT Format, unsigned int Pool, D3DIndexBuffer **ppIndexBuffer)
{
  D3DIndexBuffer *v8; // eax

  ++D3DK::g_PerfCounters.m_APICounters[26];
  v8 = (D3DIndexBuffer *)D3DK::MemAlloc(a1, a2, a3, Length + 12);
  if ( !v8 )
    return (int)&loc_80070009 + 5;
  v8->Common = 0;
  v8->Data = 0;
  v8->Lock = 0;
  v8->Common = 16842753;
  v8->Data = (unsigned int)&v8[1];
  *ppIndexBuffer = v8;
  return 0;
}
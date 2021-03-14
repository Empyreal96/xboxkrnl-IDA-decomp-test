// write access to const memory has been detected, the output may be wrong!
int __userpurge D3DDevice_CreateVertexBuffer@<eax>(int *a1@<edi>, int a2@<ecx>, int a3@<esi>, unsigned int Length, unsigned int Usage, unsigned int FVF, unsigned int Pool, D3DVertexBuffer **ppVertexBuffer)
{
  int v8; // edx
  int v9; // ecx
  D3DVertexBuffer *v10; // esi
  void *v11; // edx

  v10 = (D3DVertexBuffer *)D3DK::MemAlloc(++D3DK::g_PerfCounters.m_APICounters[33] + 1, a2, a3, 0xCu);
  if ( v10 )
  {
    v11 = (void *)MmAllocateContiguousMemoryEx(v8, v9, (int)v10, Length, 0, 0x3FFB000u, 0, 0x404u);
    if ( v11 )
    {
      _EAX = 1;
      _ECX = &D3D__AllocsContiguous;
      __asm { xadd    [ecx], eax }
      v10->Common = 16777217;
      v10->Data = D3DK::GetGPUAddress(a1, v11);
      *ppVertexBuffer = v10;
      return 0;
    }
    D3DK::MemFree(v10);
  }
  return (int)&loc_80070009 + 5;
}
int *__usercall D3DK::ComputeGap@<eax>(D3DK::CDevice *pDevice@<eax>, D3DK::Fence *pFence@<ecx>, int *a3@<edx>)
{
  int *v3; // edi
  D3DK::Fence *v4; // esi
  unsigned int *v5; // eax
  unsigned int v6; // ecx
  int v7; // ebx
  int *v9; // edi

  v3 = a3;
  v4 = pFence;
  v5 = D3DK::CDevice::GpuGet((D3DK::CDevice *)pFence, a3);
  if ( (unsigned int)v5 <= v4->Time )
    v5 = (unsigned int *)((char *)v5 + (unsigned int)v4[83].pEncoding);
  v6 = v3[1];
  if ( v6 <= v4->Time )
    v6 += (unsigned int)v4[83].pEncoding;
  v7 = v6 - (_DWORD)v5;
  if ( (signed int)(v6 - (_DWORD)v5) < 0 )
    return 0;
  v9 = (int *)(v4[83].Time - v4[925].Time);
  if ( (signed int)v9 < 0 )
    D3DK::DXGRIP(v9, "Assertion failure: %s", "run >= 0");
  return (int *)((char *)v9 + v7);
}
unsigned int __userpurge D3DK::GetGPUAddressFromWC@<eax>(int *a1@<edi>, void *pv)
{
  if ( ((unsigned int)pv & 0xF0000000) != 0x80000000 )
    D3DK::DXGRIP(a1, "AssertContiguous - the memory is not contiguous.");
  return (unsigned int)pv & 0xFFFFFFF;
}
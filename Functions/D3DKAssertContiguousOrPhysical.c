void __userpurge D3DK::AssertContiguousOrPhysical(int *a1@<edi>, void *pv)
{
  if ( ((unsigned int)pv & 0xF0000000) != 0x80000000 )
  {
    if ( (unsigned int)pv & 0xF0000000 )
      D3DK::DXGRIP(a1, "AssertContiguous - the memory is not contiguous or a physical address.");
  }
}
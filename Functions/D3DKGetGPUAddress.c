unsigned int __userpurge D3DK::GetGPUAddress@<eax>(int *a1@<edi>, void *pv)
{
  if ( ((unsigned int)pv & 0xF0000000) != 0x80000000 )
  {
    DbgPrint(a1, "DebugVerifyContiguous - the address is not a write combined mapping to contiguous memory.");
    DbgPrint(a1, "\n");
    __debugbreak();
  }
  if ( ((unsigned int)pv & 0xFFFFFFF) > 0x4000000 )
  {
    DbgPrint(a1, "DebugVerifyContiguous - the address is not a write combined mapping to contiguous memory.");
    DbgPrint(a1, "\n");
    __debugbreak();
  }
  return (unsigned int)pv & 0x3FFFFFF;
}
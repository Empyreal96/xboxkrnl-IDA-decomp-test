signed int __stdcall ExQueryPoolBlockSize(void *PoolBlock)
{
  signed int result; // eax

  if ( (unsigned __int16)PoolBlock & 0xFFF )
    result = 32 * (unsigned __int8)*((char *)PoolBlock - 5) - 8;
  else
    result = MmQueryAllocationSize(PoolBlock);
  return result;
}
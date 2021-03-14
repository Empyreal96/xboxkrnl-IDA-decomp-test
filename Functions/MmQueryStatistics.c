int __stdcall MmQueryStatistics(_MM_STATISTICS *MemoryStatistics)
{
  KIRQL v1; // al

  if ( MemoryStatistics->Length != 36 )
    return -1073741811;
  v1 = KeRaiseIrqlToDpcLevel();
  MemoryStatistics->TotalPhysicalPages = MmNumberOfPhysicalPages;
  MemoryStatistics->AvailablePages = MmAvailablePages;
  MemoryStatistics->VirtualMemoryBytesCommitted = (MmAllocatedPagesByUsage[5] + MmAllocatedPagesByUsage[7]) << 12;
  MemoryStatistics->VirtualMemoryBytesReserved = MmVirtualMemoryBytesReserved;
  MemoryStatistics->CachePagesCommitted = MmAllocatedPagesByUsage[8];
  MemoryStatistics->PoolPagesCommitted = MmAllocatedPagesByUsage[4];
  MemoryStatistics->StackPagesCommitted = MmAllocatedPagesByUsage[1];
  MemoryStatistics->ImagePagesCommitted = MmAllocatedPagesByUsage[7];
  KfLowerIrql(v1);
  return 0;
}
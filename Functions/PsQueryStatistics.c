int __stdcall PsQueryStatistics(_PS_STATISTICS *ProcessStatistics)
{
  if ( ProcessStatistics->Length != 12 )
    return -1073741811;
  ProcessStatistics->ThreadCount = thread->ApcState.Process->StackCount;
  ProcessStatistics->HandleCount = (unsigned int)ObpObjectHandleTable;
  return 0;
}
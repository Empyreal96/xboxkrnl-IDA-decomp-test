unsigned int __stdcall KeIsExecutingDpc()
{
  return KeGetCurrentPrcb()->DpcRoutineActive;
}
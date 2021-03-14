char __stdcall CAc97Device::AciSynchronizationRoutine(void *pvContext)
{
  CAc97Device::SynchronizeAciInterrupt((CAc97Device *)pvContext);
  return 1;
}
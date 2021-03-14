void __userpurge CAc97Device::AciShutdownNotifier(int *a1@<edi>, _HAL_SHUTDOWN_REGISTRATION *pHalShutdownData)
{
  CAc97Device::Terminate((CAc97Device *)&pHalShutdownData[-1].Priority, a1);
}
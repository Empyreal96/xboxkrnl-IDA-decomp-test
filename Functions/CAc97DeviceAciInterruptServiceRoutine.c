bool __userpurge CAc97Device::AciInterruptServiceRoutine@<al>(int *a1@<edi>, _KINTERRUPT *pInterrupt, void *pvContext)
{
  return CAc97Device::ServiceAciInterrupt((CAc97Device *)pvContext, a1) != 0;
}
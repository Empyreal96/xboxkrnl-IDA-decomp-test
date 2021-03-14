int __userpurge CMcpxAPU::ApuInterruptServiceRoutine@<eax>(int *a1@<edi>, _KINTERRUPT *pInterrupt, void *pvContext)
{
  return CMcpxAPU::ServiceApuInterrupt((CMcpxAPU *)pvContext, a1);
}
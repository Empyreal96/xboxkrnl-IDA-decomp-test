void __userpurge CMcpxAPU::ApuShutdownNotifier(int *a1@<edi>, _HAL_SHUTDOWN_REGISTRATION *pHalShutdownData)
{
  CMcpxAPU::Terminate((CMcpxAPU *)&pHalShutdownData[-231].ListEntry.Blink, a1);
}
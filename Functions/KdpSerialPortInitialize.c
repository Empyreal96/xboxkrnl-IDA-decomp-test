char __stdcall KdpSerialPortInitialize(char Initialize)
{
  if ( Initialize )
    CpInitialize(&KdPort, (char *)0x3F8, 0x1C200u);
  return 1;
}
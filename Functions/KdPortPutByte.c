void __stdcall KdPortPutByte(char Output)
{
  CpPutByte(&KdPort, Output);
}
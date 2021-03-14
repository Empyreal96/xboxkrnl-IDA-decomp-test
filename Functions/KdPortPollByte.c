unsigned int __stdcall KdPortPollByte(char *Input)
{
  return CpGetByte(&KdPort, Input, 0);
}
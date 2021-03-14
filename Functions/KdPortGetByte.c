unsigned int __stdcall KdPortGetByte(char *Input)
{
  return CpGetByte(&KdPort, Input, 1);
}
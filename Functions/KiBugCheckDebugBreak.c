void __stdcall KiBugCheckDebugBreak(unsigned int BreakStatus)
{
  do
    DbgBreakPointWithStatus(BreakStatus);
  while ( BreakStatus != 3 );
}
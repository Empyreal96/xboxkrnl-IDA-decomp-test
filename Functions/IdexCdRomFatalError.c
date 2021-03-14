void __userpurge __noreturn IdexCdRomFatalError(int *a1@<edi>, int a2@<esi>, unsigned int ErrorCode)
{
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  int v6; // ecx

  DbgBreakPoint();
  HalWriteSMCLEDStates(v3, v4, a1, a2, 0x1Eu);
  ExDisplayFatalError(v5, v6, a2, ErrorCode);
}
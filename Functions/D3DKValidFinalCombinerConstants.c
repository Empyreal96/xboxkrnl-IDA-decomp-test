int __userpurge D3DK::ValidFinalCombinerConstants@<eax>(int *a1@<edi>, unsigned int val, char *err)
{
  if ( !(val & 0xFFFFFE00) )
    return 1;
  DbgPrint(a1, "%s: %s", err, "31:9 must be 0");
  D3DK::DXGRIP(a1, byte_80014442);
  return 0;
}
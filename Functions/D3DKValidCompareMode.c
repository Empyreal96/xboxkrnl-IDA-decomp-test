int __userpurge D3DK::ValidCompareMode@<eax>(int *a1@<edi>, unsigned int val, char *err)
{
  if ( !(val & 0xFFFF0000) )
    return 1;
  DbgPrint(a1, "%s: %s", err, "31:16 must be 0\n");
  D3DK::DXGRIP(a1, byte_80014442);
  return 0;
}
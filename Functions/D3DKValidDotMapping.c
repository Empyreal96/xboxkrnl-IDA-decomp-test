int __userpurge D3DK::ValidDotMapping@<eax>(int *a1@<edi>, unsigned int val, char *err)
{
  if ( !((255 >> (val & 0xF)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Stage 1 invalid");
LABEL_7:
    D3DK::DXGRIP(a1, byte_80014442);
    return 0;
  }
  if ( !((255 >> ((unsigned __int8)val >> 4)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Stage 2 invalid");
    goto LABEL_7;
  }
  if ( !((255 >> (BYTE1(val) & 0xF)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Stage 3 invalid");
    goto LABEL_7;
  }
  if ( !(val & 0xFFFFF000) )
    return 1;
  DbgPrint(a1, "%s: %s", err, "31:12 must be 0");
  D3DK::DXGRIP(a1, byte_80014442);
  return 0;
}
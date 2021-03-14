int __userpurge D3DK::ValidCombinerCount@<eax>(int *a1@<edi>, unsigned int val, char *err)
{
  if ( !((510 >> val) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid Combiner Count");
LABEL_7:
    D3DK::DXGRIP(a1, byte_80014442);
    return 0;
  }
  if ( !((3 >> (BYTE1(val) & 0xF)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid Mux bit");
    goto LABEL_7;
  }
  if ( !((3 >> ((unsigned __int16)val >> 12)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid Separate C0 flag");
    goto LABEL_7;
  }
  if ( !(val & 0xFFFE0000) )
    return 1;
  DbgPrint(a1, "%s: %s", err, "31:17 must be 0");
  D3DK::DXGRIP(a1, byte_80014442);
  return 0;
}
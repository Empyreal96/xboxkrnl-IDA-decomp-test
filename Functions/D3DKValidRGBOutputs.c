int __userpurge D3DK::ValidRGBOutputs@<eax>(int *a1@<edi>, unsigned int val, char *err)
{
  if ( val & 0xFFF00000 )
  {
    DbgPrint(a1, "%s: %s", err, "31:20 must be 0");
LABEL_11:
    D3DK::DXGRIP(a1, byte_80014442);
    return 0;
  }
  if ( !((95 >> ((val >> 15) & 7)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid output mapping");
    goto LABEL_11;
  }
  if ( !((16177 >> (BYTE1(val) & 0xF)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid Sum register");
    goto LABEL_11;
  }
  if ( !((16177 >> ((unsigned __int8)val >> 4)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid AB register");
    goto LABEL_11;
  }
  if ( !((16177 >> (val & 0xF)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid CD register");
    goto LABEL_11;
  }
  return 1;
}
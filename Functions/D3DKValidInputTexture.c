int __userpurge D3DK::ValidInputTexture@<eax>(int *a1@<edi>, unsigned int val, char *err)
{
  if ( (_WORD)val )
  {
    DbgPrint(a1, "%s: %s", err, "15:0 must be 0");
LABEL_7:
    D3DK::DXGRIP(a1, byte_80014442);
    return 0;
  }
  if ( !((3 >> (BYTE2(val) & 0xF)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid input texture in stg 2");
    goto LABEL_7;
  }
  if ( !((7 >> ((val >> 20) & 0xF)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid input texture in stg 3");
    goto LABEL_7;
  }
  if ( !(val & 0xFF000000) )
    return 1;
  DbgPrint(a1, "%s: %s", err, "31:24 must be 0");
  D3DK::DXGRIP(a1, byte_80014442);
  return 0;
}
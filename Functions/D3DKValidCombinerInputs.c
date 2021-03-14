int __userpurge D3DK::ValidCombinerInputs@<eax>(int *a1@<edi>, unsigned int val, char *err)
{
  if ( !((16191 >> (HIBYTE(val) & 0xF)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid A Register");
LABEL_9:
    D3DK::DXGRIP(a1, byte_80014442);
    return 0;
  }
  if ( !((16191 >> (BYTE2(val) & 0xF)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid B Register");
    goto LABEL_9;
  }
  if ( !((16191 >> (BYTE1(val) & 0xF)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid C Register");
    goto LABEL_9;
  }
  if ( !((16191 >> (val & 0xF)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid D Register");
    goto LABEL_9;
  }
  return 1;
}
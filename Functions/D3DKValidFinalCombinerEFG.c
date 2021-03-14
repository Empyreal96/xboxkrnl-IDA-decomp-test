int __userpurge D3DK::ValidFinalCombinerEFG@<eax>(int *a1@<edi>, unsigned int val, char *err)
{
  const char *v4; // [esp-4h] [ebp-4h]

  if ( !((3 >> (val >> 29)) & 1) )
  {
    v4 = "Invalid input mapping Reg E";
LABEL_15:
    DbgPrint(a1, "%s: %s", err, v4);
    goto LABEL_16;
  }
  if ( !((3 >> ((val >> 21) & 7)) & 1) )
  {
    v4 = "Invalid input mapping Reg F";
    goto LABEL_15;
  }
  if ( !((3 >> ((unsigned __int16)val >> 13)) & 1) )
  {
    v4 = "Invalid input mapping Reg G";
    goto LABEL_15;
  }
  if ( val & 0x1F )
  {
    DbgPrint(a1, "%s: %s", err, "4:0 must be 0");
LABEL_16:
    D3DK::DXGRIP(a1, byte_80014442);
    return 0;
  }
  if ( !((16191 >> (HIBYTE(val) & 0xF)) & 1) )
  {
    v4 = "Invalid E Register";
    goto LABEL_15;
  }
  if ( !((16191 >> (BYTE2(val) & 0xF)) & 1) )
  {
    v4 = "Invalid F Register";
    goto LABEL_15;
  }
  if ( !((16191 >> (BYTE1(val) & 0xF)) & 1) )
  {
    v4 = "Invalid G Register";
    goto LABEL_15;
  }
  return 1;
}
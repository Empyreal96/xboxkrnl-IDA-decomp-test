int __userpurge D3DK::ValidAlphaOutputs@<eax>(int *a1@<edi>, unsigned int val, char *err)
{
  const char *v4; // [esp-4h] [ebp-4h]

  if ( val & 0xFFFC0000 )
  {
    v4 = "31:18 must be 0";
LABEL_13:
    DbgPrint(a1, "%s: %s", err, v4);
    goto LABEL_14;
  }
  if ( val & 0x3000 )
  {
    DbgPrint(a1, "%s: %s", err, "13:12 must be 0");
LABEL_14:
    D3DK::DXGRIP(a1, byte_80014442);
    return 0;
  }
  if ( !((95 >> ((val >> 15) & 7)) & 1) )
  {
    v4 = "Invalid output mapping";
    goto LABEL_13;
  }
  if ( !((16177 >> (BYTE1(val) & 0xF)) & 1) )
  {
    v4 = "Invalid Sum register";
    goto LABEL_13;
  }
  if ( !((16177 >> ((unsigned __int8)val >> 4)) & 1) )
  {
    v4 = "Invalid AB register";
    goto LABEL_13;
  }
  if ( !((16177 >> (val & 0xF)) & 1) )
  {
    v4 = "Invalid CD register";
    goto LABEL_13;
  }
  return 1;
}
unsigned int __stdcall HalpReadPCISpaceUchar(_PCI_TYPE1_CFG_BITS CfgBits, unsigned int RegisterNumber, void *Buffer)
{
  unsigned __int8 v3; // al

  __outdword(0xCF8u, CfgBits.u.AsULONG ^ (unsigned __int8)((RegisterNumber ^ *(_BYTE *)&CfgBits.u.bits) & 0xFC));
  v3 = __inbyte((RegisterNumber & 3) + 3324);
  *(_BYTE *)Buffer = v3;
  return 1;
}
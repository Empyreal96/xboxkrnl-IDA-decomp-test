unsigned int __stdcall HalpReadPCISpaceUshort(_PCI_TYPE1_CFG_BITS CfgBits, unsigned int RegisterNumber, void *Buffer)
{
  unsigned __int16 v3; // ax

  __outdword(0xCF8u, CfgBits.u.AsULONG ^ (unsigned __int8)((RegisterNumber ^ *(_BYTE *)&CfgBits.u.bits) & 0xFC));
  v3 = __inword((RegisterNumber & 3) + 3324);
  *(_WORD *)Buffer = v3;
  return 2;
}
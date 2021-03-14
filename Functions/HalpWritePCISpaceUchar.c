unsigned int __stdcall HalpWritePCISpaceUchar(_PCI_TYPE1_CFG_BITS CfgBits, unsigned int RegisterNumber, void *Buffer)
{
  __outdword(0xCF8u, CfgBits.u.AsULONG ^ (unsigned __int8)((RegisterNumber ^ *(_BYTE *)&CfgBits.u.bits) & 0xFC));
  __outbyte((RegisterNumber & 3) + 3324, *(_BYTE *)Buffer);
  return 1;
}
unsigned int __stdcall HalpWritePCISpaceUshort(_PCI_TYPE1_CFG_BITS CfgBits, unsigned int RegisterNumber, void *Buffer)
{
  __outdword(0xCF8u, CfgBits.u.AsULONG ^ (unsigned __int8)((RegisterNumber ^ *(_BYTE *)&CfgBits.u.bits) & 0xFC));
  __outword((RegisterNumber & 3) + 3324, *(_WORD *)Buffer);
  return 2;
}
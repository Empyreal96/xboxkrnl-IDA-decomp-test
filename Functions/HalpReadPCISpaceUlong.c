unsigned int __userpurge HalpReadPCISpaceUlong@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _PCI_TYPE1_CFG_BITS CfgBits, unsigned int RegisterNumber, void *Buffer)
{
  unsigned __int32 v7; // eax

  if ( RegisterNumber & 3 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "(RegisterNumber % sizeof(ULONG)) == 0",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\pcispace.c",
      0x82u,
      0);
  __outdword(0xCF8u, CfgBits.u.AsULONG ^ (unsigned __int8)((RegisterNumber ^ *(_BYTE *)&CfgBits.u.bits) & 0xFC));
  v7 = __indword(0xCFCu);
  *(_DWORD *)Buffer = v7;
  return 4;
}
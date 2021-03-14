unsigned int __userpurge HalpWritePCISpaceUlong@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _PCI_TYPE1_CFG_BITS CfgBits, unsigned int RegisterNumber, void *Buffer)
{
  if ( RegisterNumber & 3 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "(RegisterNumber % sizeof(ULONG)) == 0",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\pcispace.c",
      0xF0u,
      0);
  __outdword(0xCF8u, CfgBits.u.AsULONG ^ (unsigned __int8)((RegisterNumber ^ *(_BYTE *)&CfgBits.u.bits) & 0xFC));
  __outdword(0xCFCu, *(_DWORD *)Buffer);
  return 4;
}
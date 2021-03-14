int __userpurge PhyWriteReg@<eax>(int *a1@<edi>, int a2@<esi>, $3A248F961AD0BF30135A1C166837D1FD *csr, unsigned int phyreg, unsigned int val)
{
  unsigned int v5; // eax
  signed int v6; // ebx
  bool v7; // zf
  int v8; // edx
  int v9; // ST0C_4

  if ( csr->mdio_adr & 0x8000 )
    PhyClearMDIOLOCK(csr);
  csr->mdio_data = val;
  csr->mdio_adr = phyreg | 0x420;
  LOWORD(v5) = phyreg | 0x8420;
  v6 = 0x2000;
  while ( 1 )
  {
    v7 = (unsigned __int16)(v5 & 0x8000) == 0;
    if ( !(v5 & 0x8000) )
      break;
    KeStallExecutionProcessor(0x32u);
    v5 = csr->mdio_adr;
    v6 -= 50;
    if ( v6 <= 0 )
    {
      v7 = (csr->mdio_adr & 0x8000) == 0;
      break;
    }
  }
  if ( v7 )
    return 1;
  DbgPrint(a1, "PHY write failed: reg %d.\n", phyreg);
  RtlAssert(v8, v9, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\phy\\phy.c", 0xFBu, 0);
  return 0;
}
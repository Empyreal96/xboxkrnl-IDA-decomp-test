int __userpurge PhyReadReg@<eax>(int *a1@<edi>, int a2@<esi>, $3A248F961AD0BF30135A1C166837D1FD *csr, unsigned int phyreg, unsigned int *val)
{
  unsigned int v5; // eax
  signed int v6; // ebx
  int v7; // edx
  int v8; // ST0C_4

  if ( csr->mdio_adr & 0x8000 )
    PhyClearMDIOLOCK(csr);
  csr->mdio_adr = phyreg | 0x20;
  LOWORD(v5) = phyreg | 0x8020;
  v6 = 0x2000;
  do
  {
    if ( !(v5 & 0x8000) )
      break;
    KeStallExecutionProcessor(0x32u);
    v5 = csr->mdio_adr;
    v6 -= 50;
  }
  while ( v6 > 0 );
  *val = csr->mdio_data;
  if ( !(v5 & 0x8000) )
    return 1;
  DbgPrint(a1, "PHY read failed: reg %d.\n", phyreg);
  RtlAssert(v7, v8, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\phy\\phy.c", 0xBEu, 0);
  return 0;
}
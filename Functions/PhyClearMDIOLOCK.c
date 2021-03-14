void __stdcall PhyClearMDIOLOCK($3A248F961AD0BF30135A1C166837D1FD *csr)
{
  signed int v1; // ebx

  csr->mdio_adr = 0x8000;
  DbgPrint((int *)csr, "PHY: MDIOADR_LOCK is set\n");
  v1 = 0x2000;
  do
  {
    KeStallExecutionProcessor(0x32u);
    v1 -= 50;
  }
  while ( v1 > 0 && csr->mdio_adr & 0x8000 );
}
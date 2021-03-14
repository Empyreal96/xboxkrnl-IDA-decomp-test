unsigned int __userpurge PhyWaitForLinkUp@<eax>(int *a1@<edi>, $3A248F961AD0BF30135A1C166837D1FD *csr)
{
  int v2; // esi
  unsigned int miiStatus; // [esp+4h] [ebp-4h]

  miiStatus = 0;
  v2 = 1000;
  do
  {
    --v2;
    if ( miiStatus & 4 )
      break;
    KeStallExecutionProcessor(0x1F4u);
    if ( !PhyReadReg(a1, v2, csr, 1u, &miiStatus) )
      break;
  }
  while ( v2 );
  return miiStatus;
}
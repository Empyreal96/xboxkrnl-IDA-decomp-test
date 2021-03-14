int __userpurge PhyUpdateLinkState@<eax>(int *a1@<edi>, $3A248F961AD0BF30135A1C166837D1FD *csr)
{
  unsigned int v2; // esi
  __int16 v3; // ax
  signed int v5; // [esp-4h] [ebp-10h]
  unsigned int lpanar; // [esp+4h] [ebp-8h]
  unsigned int anar; // [esp+8h] [ebp-4h]

  v2 = 0;
  if ( !PhyReadReg(a1, 0, csr, 4u, &anar)
    || !PhyReadReg(a1, 0, csr, 5u, &lpanar)
    || !PhyReadReg(a1, 0, csr, 1u, (unsigned int *)&csr) )
  {
    return 0;
  }
  v3 = lpanar & anar;
  if ( (unsigned __int16)lpanar & (unsigned __int16)anar & 0x180 )
  {
    v5 = 2;
LABEL_8:
    v2 = v5;
    goto LABEL_9;
  }
  if ( v3 & 0x60 )
  {
    v5 = 4;
    goto LABEL_8;
  }
LABEL_9:
  if ( v3 & 0x140 )
  {
    v2 |= 8u;
  }
  else if ( v3 & 0xA0 )
  {
    v2 |= 0x10u;
  }
  if ( (unsigned __int8)csr & 4 )
    v2 |= 1u;
  PhyLinkState = v2;
  return 1;
}
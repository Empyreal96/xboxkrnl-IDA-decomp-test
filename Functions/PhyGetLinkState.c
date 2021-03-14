unsigned int __userpurge PhyGetLinkState@<eax>(int *a1@<edi>, int update)
{
  if ( !PhyLinkState || update )
  {
    _ECX = &PhyLockFlag;
    _EDX = 1;
    __asm { cmpxchg [ecx], edx }
    PhyUpdateLinkState(a1, ($3A248F961AD0BF30135A1C166837D1FD *)0xFEF00000);
    PhyLockFlag = 0;
  }
  return PhyLinkState;
}
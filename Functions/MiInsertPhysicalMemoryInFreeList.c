void __userpurge MiInsertPhysicalMemoryInFreeList(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, unsigned int PageFrameNumber, unsigned int EndingPageFrameNumberExclusive)
{
  unsigned int i; // esi

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x2C6u,
      0);
  for ( i = PageFrameNumber; i < EndingPageFrameNumberExclusive; ++i )
  {
    MiInsertPageInFreeList(i, 0);
    ++MmNumberOfPhysicalPages;
  }
}